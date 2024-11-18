#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Sorter.h"

class BubbleSort : public Sorter {
public:
    void sort(std::vector<int>& data, SortMetrics& metrics) override;
    std::string name() const override { return "Bubble Sort"; }
};

#endif
