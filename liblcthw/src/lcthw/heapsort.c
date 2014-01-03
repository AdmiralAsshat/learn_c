#include <stdio.h>
#include "dbg.h"

/* Simple heapsort prog
TODO: Get heapsort working on fixed array, then implement on DArray */

#define SWAP(r,s)  do{int t=r; r=s; s=t; } while(0)

int heapify(int *a, int count);
int siftDown(int *a, int start, int end);
int heapsort(int *a, int count);

int main(int argc, char *argv[])
{
	int i;
	int to_sort[] = { 34, 7, 19, 25, 1, 78, 4 };
	int size = (sizeof(to_sort) / sizeof(to_sort[0]));

	printf("Array Size: %d\n", size);
	printf("Before sort: ");
	for(i = 0; i < size; i++)  printf("%d,", to_sort[i]); 
	printf("\n");

	heapsort(to_sort, size);

	printf("After sort: ");
	for(i = 0; i < size; i++)  printf("%d,", to_sort[i]); 
	printf("\n");

	return 0;
}

int heapify(int *a, int count)
{
	int start = (count - 2) / 2;

	do
	{
		siftDown(a, start, count - 1);
		start--;
	} while (start >= 0);

	return 0;
error:
	return 1;
}

int siftDown(int *a, int start, int end)
{
	int root = start;
	while((root * 2) + 1 <= end)
	{
		int child = (root * 2) + 1;
		int to_swap = root;
		if (a[to_swap] < a[child])
			to_swap = child;
		if (child+1 <= end && a[to_swap] < a[child + 1])
			to_swap = child + 1;
		if (to_swap != root)
		{
			SWAP(a[root], a[to_swap]);
			root = to_swap;
		} else
			return;
	}
error:
	return 1;
}

int heapsort(int *a, int count)
{
	heapify(a, count);
	unsigned int end = count - 1;
	do
	{
		SWAP(a[end], a[0]);
		end--;
		siftDown(a, 0, end);
	} while (end > 0);

	return 0;

error:
	return 1;
}
