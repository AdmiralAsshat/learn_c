#include<lcthw/dbg.h>
#include<lcthw/list_algos.h>

void printlist(List *list)
{
	ListNode *tmp=NULL;
	
	if(!list)
		return;

	tmp = list->first;

	printf("DEBUG: Values : ");
    for(tmp=list->first ; tmp != NULL ;tmp=tmp->next)
	{
		printf("%s ,",tmp->value);
	}
	printf("\n");
}

int List_bubble_sort(List *list, List_compare cmp)
{

	int sorted = 1;

	// Don't sort an empty list
	if(list == NULL || list->count < 1 || list->first == NULL)
	{
		return (0);
	}

	do 	{
		sorted = 1;
		LIST_FOREACH(list, first, next, cur) {
			if(cur->next) {
					if(cmp(cur->value, cur->next->value) > 0) {
						void *temp = cur->value;
						cur->value = cur->next->value;
						cur->next->value = temp;
						sorted = 0;
					}
				}
			}
		} while (!sorted);

	return 0;

error:
return 1;
}

List *List_merge_sort(List *list, List_compare method)
{
	int i;
	int size = list->count;
	ListNode *tmp;

	// Don't sort an empty list
	if (size <= 1)
		{
			return list;
		}

	List *left, *right, *result;
	left = List_create();
	right = List_create();

	int mid = size / 2;

	for (i = 0, tmp = list->first; i < size; i++, tmp = tmp->next)
	{
		check(tmp != NULL, "Bad; got a null in the list.")
		if (i < mid)
		{
			List_push(left, tmp->value);
		} else {
			List_push(right, tmp->value);
		}
		
	}

	left = List_merge_sort(left,strcmp);
	right = List_merge_sort(right,strcmp);

	result = merge(left, right);

	return result;
error:
if (left) { free(left);}
if (right) { free(right);}
if (result) { free(result);}
return NULL;

}

List *merge(List *left, List *right)
{
	List *result = List_create();
/*	Used during debugging; no longer needed
	printf("DEBUG: Left List:\n");
	printlist(left);
	printf("DEBUG: Right List:\n");
	printlist(right); */

	while (left->count > 0 || right->count > 0)
	{
		if (left->count > 0 && right->count > 0)
		{
			if(strcmp(left->first->value, right->first->value) < 0)
				{	List_push(result, left->first->value);
					List_remove(left, left->first);
				} else {
					List_push(result, right->first->value);
					List_remove(right, right->first);
				}

		} else if (left->count > 0) {
			List_push(result, left->first->value);
			List_remove(left, left->first);
		} else if (right->count > 0) {
			List_push(result, right->first->value);
			List_remove(right, right->first);
		}
	}

/*	printf("DEBUG: merge result:\n");
	printlist(result); */

	return result;
}
