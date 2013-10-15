#include<lcthw/dbg.h>
#include<lcthw/list_algos.h>

List *List_bubble_sort(List *list, (List_compare) method)
{
	ListNode *outer, inner, temp = NULL;
	ListNode *cur = malloc(sizeof(ListNode));
	check(cur !=NULL, "Could not allocate memory.");
	
	for (outer = list->first; outer->next != NULL; outer = outer->next)
		for (inner = outer; inner->next != NULL; inner = inner->next)
		{
			cur = inner;
			if (method(cur, cur->next) > 1)
			{
				temp = cur->next;
				cur->next = cur;
				cur = temp;
			}
		}

return list;
}

