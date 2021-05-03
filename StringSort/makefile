all: main.c quicksort_string.o mergesort_string.o heapsort_string.o
	gcc main.c quicksort_string.o mergesort_string.o heapsort_string.o -o main
quicksort_string.o: QuickSort_String.c quicksort_string.h
	gcc -c QuickSort_String.c -o quicksort_string.o
mergesort_string.o: MergeSort_String.c mergesort_string.h
	gcc -c MergeSort_String.c -o mergesort_string.o
heapsort_string.o: Heapsort_String.c heapsort_string.h
	gcc -c Heapsort_String.c -o heapsort_string.o
clean:
	rm -f quicksort_string.o mergesort_string.o heapsort_string.o main