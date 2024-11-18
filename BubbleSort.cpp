#include "BubbleSort.h"
#include <algorithm>

void BubbleSort::sort(std::vector<int>& data, SortMetrics& metrics) {
    size_t n = data.size();
    bool swapped;

    for (size_t i = 0; i < n - 1; ++i) {
        swapped = false;

        for (size_t j = 0; j < n - i - 1; ++j) {
            metrics.comparisons++;
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                metrics.swaps++;
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}
