#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sorter.h"

class QuickSort : public Sorter {
public:
    void sort(std::vector<int>& data, SortMetrics& metrics) override;
    std::string name() const override { return "Quick Sort"; }

private:
    void quickSortRecursive(std::vector<int>& data, int low, int high, SortMetrics& metrics);
    int partition(std::vector<int>& data, int low, int high, SortMetrics& metrics);
};

#endif
