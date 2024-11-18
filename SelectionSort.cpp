#include "SelectionSort.h"
#include <algorithm>

void SelectionSort::sort(std::vector<int>& data, SortMetrics& metrics) {
    size_t n = data.size();
    for (size_t i = 0; i < n - 1; ++i) {
        size_t min_idx = i;

        for (size_t j = i + 1; j < n; ++j) {
            metrics.comparisons++;
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            std::swap(data[i], data[min_idx]);
            metrics.swaps++;
        }
    }
}
