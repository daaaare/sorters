#ifndef MERGESORT_H
#define MERGESORT_H

#include "Sorter.h"

class MergeSort : public Sorter {
public:
    void sort(std::vector<int>& data, SortMetrics& metrics) override;
    std::string name() const override { return "Merge Sort"; }

private:
    void mergeSortRecursive(std::vector<int>& data, int left, int right, SortMetrics& metrics);
    void merge(std::vector<int>& data, int left, int mid, int right, SortMetrics& metrics);
};

#endif
