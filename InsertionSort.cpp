#include "InsertionSort.h"

void InsertionSort::sort(std::vector<int>& data, SortMetrics& metrics) {
    size_t n = data.size();
    for (size_t i = 1; i < n; ++i) {
        int key = data[i];
        size_t j = i;

        while (j > 0) {
            metrics.comparisons++;
            if (data[j - 1] > key) {
                data[j] = data[j - 1];
                metrics.swaps++;
                j--;
            } else {
                break;
            }
        }
        data[j] = key;
    }
}
