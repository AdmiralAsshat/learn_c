#ifndef lcthw_list_algos_h
#define lcthw_list_algos_h

#include<lcthw/list.h>
#include<stdlib.h>

typedef int (*List_compare)(char *a, char *b);

int List_bubble_sort(List *list, List_compare method);
int List_merge_sort(List *list, List_compare method);
List merge(List *left, List *right);

#endif
