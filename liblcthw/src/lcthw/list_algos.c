List *List_sort(List *list)
{
	ListNode *cur;
	do
	{
		bool swapped = FALSE;
		for (cur = list->first; cur->next != NULL; cur = cur->next;)
		{
			if (cur->value > cur->next->value)
			{
				cur->next = cur->next->next;
				cur->next->previous = cur->previous;
				cur->previous = cur->next;
				cur->previoux->next = cur;
				swapped = TRUE;
			}
		}
	} while (swapped = FALSE);
}
