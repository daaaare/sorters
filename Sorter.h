#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <string>

//struct to hold sorting metrics
struct SortMetrics {
    long long comparisons = 0; //number of comparisons made
    long long swaps = 0;       //number of swaps made
};

//abstract base class for sorting algorithms
class Sorter {
public:
    //pure virtual function to sort data and collect metrics
    virtual void sort(std::vector<int>& data, SortMetrics& metrics) = 0;

    //pure virtual function to return the name of the sorting algorithm
    virtual std::string name() const = 0;

    virtual ~Sorter() {}
};

#endif
