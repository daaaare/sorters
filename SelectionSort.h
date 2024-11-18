#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "Sorter.h"


class SelectionSort : public Sorter {
public:
    void sort(std::vector<int>& data, SortMetrics& metrics) override;
    std::string name() const override { return "Selection Sort"; }
};

#endif