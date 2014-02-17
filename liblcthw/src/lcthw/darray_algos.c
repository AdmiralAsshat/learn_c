#include <lcthw/darray_algos.h>
#include <stdlib.h>

//TODO: Work on mergesort, change all heapsort functions
// to use proper compare fn pointers
static inline void print_array(void **array, char *preface)
{
	unsigned int end;
	printf(preface);
	for (end = 0; array[end] != NULL; end++)
		printf("%s ", array[end]);
	printf("\n");
}

int DArray_qsort(DArray *array, DArray_compare cmp)
{
	qsort(array->contents, DArray_count(array), sizeof(void *), cmp);
	return 0;
}

int DArray_heapsort(DArray *array, DArray_compare cmp)
{
	return heapsort(array->contents, DArray_count(array), sizeof(void *), cmp);
}

int DArray_mergesort(DArray *array, DArray_compare cmp)
{
	return mergesort(array->contents, DArray_count(array), sizeof(void *), cmp);
}

inline void DArray_swap(void **a, void **b)
{
	void *temp = *a;
	*a = *b;
	*b = temp;
}

int mergesort(void *array, int length, int size, DArray_compare cmp)
{	
	return 0;
}

int heapify(void *a, int count, DArray_compare cmp)
{
	int start;
	for (start = (count - 2) / 2; start >=0; start--)
	{
		siftDown(a, start, count -1, cmp);
	}
	return 0;
error:
	return 1;
}

int siftDown(void **a, int start, int end, DArray_compare cmp)
{
	int root = start;	
	while((root * 2) + 1 <= end)
	{
		int child = (root * 2) + 1;
		int to_swap = root;

		if (cmp(&a[to_swap], &a[child]) < 0)
			to_swap = child;
		if (child+1 <= end && cmp(&a[to_swap], &a[child + 1]) < 0)
			to_swap = child + 1;
		if (to_swap != root)
		{
			DArray_swap(&a[root], &a[to_swap]);
			root = to_swap;
		} else
			return 0;
	}
error:
	return 1;
}

int heapsort(void **a, int count, int size, DArray_compare cmp)
{
	unsigned int end;
	heapify(a, count, cmp);

	print_array(a,"Before sort: ");

	for (end = count - 1; end > 0; end--)
	{
		DArray_swap(&a[end], &a[0]);
		siftDown(a, 0, end - 1, cmp);
	} 

	//Debug block
	print_array(a,"After sort: ");
	//End block */

	return 0;

error:
	return 1;
}
