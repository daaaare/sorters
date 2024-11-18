#include "QuickSort.h"
#include <algorithm>

void QuickSort::sort(std::vector<int>& data, SortMetrics& metrics) {
    if (data.empty()) return;
    quickSortRecursive(data, 0, data.size() - 1, metrics);
}

void QuickSort::quickSortRecursive(std::vector<int>& data, int low, int high, SortMetrics& metrics) {
    if (low < high) {
        int pi = partition(data, low, high, metrics);
        quickSortRecursive(data, low, pi - 1, metrics);
        quickSortRecursive(data, pi + 1, high, metrics);
    }
}

int QuickSort::partition(std::vector<int>& data, int low, int high, SortMetrics& metrics) {
    int pivot = data[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        metrics.comparisons++;
        if (data[j] < pivot) {
            i++;
            std::swap(data[i], data[j]);
            metrics.swaps++;
        }
    }
    std::swap(data[i + 1], data[high]);
    metrics.swaps++;
    return (i + 1);
}
