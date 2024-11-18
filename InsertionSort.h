#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Sorter.h"

class InsertionSort : public Sorter {
public:
    void sort(std::vector<int>& data, SortMetrics& metrics) override;
    std::string name() const override { return "Insertion Sort"; }
};

#endif
