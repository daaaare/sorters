#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <algorithm>
#include <random>
#include <filesystem> //directory creation
#include "Sorter.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"

//struct to hold the results of a single run
struct RunResult {
    double cpu_time_ms; //cpu time in ms
    long long comparisons;
    long long swaps;
};

//random ints in specific range
std::vector<int> generateRandomNumbers(size_t size, int lower = 0, int upper = 1000000) {
    std::vector<int> numbers;
    numbers.reserve(size);

    //rng
    std::random_device rd; //seed
    std::mt19937 gen(rd()); //Mersenne Twister engine
    std::uniform_int_distribution<> dis(lower, upper); //Uniform distribution

    for (size_t i = 0; i < size; ++i) {
        numbers.push_back(dis(gen));
    }

    return numbers;
}

//function to create a sorted copy of a given dataset using std::sort
std::vector<int> createSortedCopy(const std::vector<int>& original) {
    std::vector<int> sorted = original;
    std::sort(sorted.begin(), sorted.end());
    return sorted;
}

//function to measure the performance of a sorting algorithm on a given dataset
RunResult measureSortPerformance(Sorter& sorter, std::vector<int>& data) {
    SortMetrics metrics;

    //timing
    auto start = std::chrono::high_resolution_clock::now();

    //sorting
    sorter.sort(data, metrics);

    //end timing
    auto end = std::chrono::high_resolution_clock::now();

    //calculate elapsed time in milliseconds
    std::chrono::duration<double, std::milli> elapsed = end - start;

    //prep results
    RunResult result;
    result.cpu_time_ms = elapsed.count();
    result.comparisons = metrics.comparisons;
    result.swaps = metrics.swaps;

    return result;
}

//function to check if a vector is sorted
bool isSorted(const std::vector<int>& data) {
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i - 1] > data[i])
            return false;
    }
    return true;
}

int main() {
    //create a data directory
    std::filesystem::create_directory("data");

    //sort algorithms
    std::vector<Sorter*> sorters;
    sorters.push_back(new InsertionSort());
    sorters.push_back(new SelectionSort());
    sorters.push_back(new MergeSort());
  
    //data sizes
    std::vector<size_t> sizes = {1000, 10000, 100000};

    //sets
    std::map<size_t, std::vector<int>> randomDatasets;
    std::map<size_t, std::vector<int>> sortedDatasets;

    std::cout << "Generating random datasets...\n";
    for (auto size : sizes) {
        randomDatasets[size] = generateRandomNumbers(size);
        sortedDatasets[size] = createSortedCopy(randomDatasets[size]);
    }
    std::cout << "Datasets generated.\n";

    std::ofstream csvFile("data/measurements.csv");
    if (!csvFile.is_open()) {
        std::cerr << "Error: Unable to open data/measurements.csv for writing.\n";
        return 1;
    }

    //csv headers
    csvFile << "Algorithm,Data Size,Category,Run,CPU Time (ms),Comparisons,Swaps\n";

    // sorting and collecting
    for (auto sorter : sorters) {
        std::cout << "Running " << sorter->name() << "...\n";

        for (auto size : sizes) {
            for (const std::string& category : {"Unsorted", "Sorted"}) {
                
                std::vector<int> dataset = (category == "Unsorted") ? randomDatasets[size] : sortedDatasets[size];

                for (int run = 1; run <= 10; ++run) {
                    //make a copy to ensure each run starts with the same data
                    std::vector<int> dataCopy = dataset;

                    //measure performance
                    RunResult result = measureSortPerformance(*sorter, dataCopy);

                    if (!isSorted(dataCopy)) {
                        std::cerr << "Error: " << sorter->name() << " failed to sort the data on run " << run << ".\n";
                    }

                    //send to csv
                    csvFile << sorter->name() << "," << size << "," << category << "," << run << ","
                            << result.cpu_time_ms << "," << result.comparisons << "," << result.swaps << "\n";
                    if (run % 2 == 0) { // Display every 2 runs
                        std::cout << sorter->name() << " - Size: " << size << " - " << category
                                  << " - Run: " << run << " completed.\n";
                    }
                }
            }
        }

        std::cout << sorter->name() << " completed.\n";
    }

    csvFile.close();

    for (auto sorter : sorters) {
        delete sorter;
    }

    std::cout << "All measurements have been saved to data/measurements.csv\n";
    std::cout << "You can now create graphs based on this data.\n";

    return 0;
}
