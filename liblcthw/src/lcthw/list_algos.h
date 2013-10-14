#ifndef lcthw_list_algos_h
#define lcthw_list_algos_h

#include<lcthw/list.h>
#include<stdlib.h>

typedef int (*List_compare)(char *a, char *b);

List *List_bubble_sort(List *list, (List compare) method);


#endif
