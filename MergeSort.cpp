#include "MergeSort.h"

void MergeSort::sort(std::vector<int>& data, SortMetrics& metrics) {
    if (data.empty()) return;
    mergeSortRecursive(data, 0, data.size() - 1, metrics);
}

void MergeSort::mergeSortRecursive(std::vector<int>& data, int left, int right, SortMetrics& metrics) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortRecursive(data, left, mid, metrics);
        mergeSortRecursive(data, mid + 1, right, metrics);

        merge(data, left, mid, right, metrics);
    }
}

void MergeSort::merge(std::vector<int>& data, int left, int mid, int right, SortMetrics& metrics) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(data.begin() + left, data.begin() + mid + 1);
    std::vector<int> R(data.begin() + mid + 1, data.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        metrics.comparisons++;
        if (L[i] <= R[j]) {
            data[k++] = L[i++];
        } else {
            data[k++] = R[j++];
        }
    }

    while (i < n1) {
        data[k++] = L[i++];
    }

    while (j < n2) {
        data[k++] = R[j++];
    }
}
