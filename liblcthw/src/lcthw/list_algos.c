#include<lcthw/dbg.h>
#include<lcthw/list_algos.h>

List *List_bubble_sort(List *list)
{
	ListNode *cur;
	int swapped = 0;

	do
	{
		swapped = 0;
		for (cur = list->first; cur->next != NULL; cur = cur->next)
		{
			if (cur->value > cur->next->value)
			{
				cur->next = cur->next->next;
				cur->next->prev = cur->prev;
				cur->prev = cur->next;
				cur->prev->next = cur;
				swapped = 1;
			}
		}
	} while (swapped == 0);

return list;
}
