sorter: main.o InsertionSort.o SelectionSort.o MergeSort.o BubbleSort.o QuickSort.o
	g++ main.o InsertionSort.o SelectionSort.o MergeSort.o BubbleSort.o QuickSort.o -o sorter

main.o: main.cpp Sorter.h InsertionSort.h SelectionSort.h MergeSort.h BubbleSort.h QuickSort.h
	g++ -c main.cpp

InsertionSort.o: InsertionSort.cpp InsertionSort.h Sorter.h
	g++ -c InsertionSort.cpp

SelectionSort.o: SelectionSort.cpp SelectionSort.h Sorter.h
	g++ -c SelectionSort.cpp

MergeSort.o: MergeSort.cpp MergeSort.h Sorter.h
	g++ -c MergeSort.cpp

BubbleSort.o: BubbleSort.cpp BubbleSort.h Sorter.h
	g++ -c BubbleSort.cpp

QuickSort.o: QuickSort.cpp QuickSort.h Sorter.h
	g++ -c QuickSort.cpp

clean:
	rm -f *.o sorter
