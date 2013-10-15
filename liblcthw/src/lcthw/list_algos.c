#include<lcthw/dbg.h>
#include<lcthw/list_algos.h>

int List_bubble_sort(List *list, List_compare method)
{
	int i, j;
	ListNode *outer, *inner, *temp = NULL;
	ListNode *cur = malloc(sizeof(ListNode));
	check(cur !=NULL, "Could not allocate memory.");
	
	for (i = 0, outer = list->first; i < list->count; i++, outer = outer->next)
		for (j = 0, inner = list->first; j < i - 1; j++, inner = inner->next)
		{
			cur = inner;
			if (method(cur->value, cur->next->value) > 1)
			{
				temp = cur->next;
				cur->next = cur;
				cur = temp;
			}
		}

	return 0;

error:
return 1;
}
