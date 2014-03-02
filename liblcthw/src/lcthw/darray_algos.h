#ifndef darray_algos_h
#define darray_algos_h

#include<lcthw/DArray.h>

typedef int (*DArray_compare)(const void *a, const void *b);

int DArray_qsort(DArray *array, DArray_compare cmp);

int DArray_heapsort(DArray *array, DArray_compare cmp);

int DArray_mergesort(DArray *array, DArray_compare cmp);

inline void DArray_swap(void **a, void **b);

int mergesort(void *array, int length, int size, DArray_compare cmp);

DArray merge(DArray left, DArray right);

int heapify(void *a, int count, DArray_compare cmp);

int siftDown(void **a, int start, int end, DArray_compare cmp);

int heapsort(void **a, int count, int size, DArray_compare cmp);

#endif
