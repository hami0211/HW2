all: main.c quicksort.o mergesort.o heapsort.o
	gcc main.c quicksort.o mergesort.o heapsort.o -o main
quicksort.o: QuickSort.c quicksort.h
	gcc -c QuickSort.c -o quicksort.o
mergesort.o: MergeSort.c mergesort.h
	gcc -c MergeSort.c -o mergesort.o
heapsort.o: Heapsort.c heapsort.h
	gcc -c Heapsort.c -o heapsort.o
clean:
	rm -f quicksort.o mergesort.o heapsort.o main