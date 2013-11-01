#include<lcthw/dbg.h>
#include<lcthw/list_algos.h>

int List_bubble_sort(List *list, List_compare method)
{
	int i, j;

	ListNode **elems=NULL;
	ListNode *tmp;
	int size;

	// Don't sort an empty list
	if(list == NULL || list->count < 1 || list->first == NULL)
	{
		return (0);
	}

	size = list->count;


	elems = (ListNode *)malloc(sizeof(ListNode *) * size);

    for(i = 0,tmp=list->first ; i < size ;i++,tmp=tmp->next)
	{
	  elems[i] = tmp;
	// printf("Debug: elems[%d] value: %s\n",i,elems[i]->value);

	}

	for(i = 0 ; i < size-1 ; i++)
	{
		for(j = i+1; j < size; j++)
		{
			if (method(elems[i]->value, elems[j]->value) > 0)
			{
			   /* printf("SWAP %s %s\n",(char *)elems[i]->value,(char *)elems[j]->value); */
				tmp = elems[i];
				elems[i] = elems[j];
				elems[j] = tmp;
			}
		}
	}

    /*for(i = 0 ; i < size ;i++)
	{
	  
	  printf("After Debug: elems[%d] value: %s\n",i,(char *)elems[i]->value);

	}*/

	list->first = elems[0];
	elems[0]->prev=NULL;
	list->last=elems[size - 1];

	for(i=1;i<size;i++)
	{
		elems[i-1]->next = elems[i];
		elems[i]->prev = elems[i-1];
        
		elems[i]->next = NULL;
	}

	free(elems);

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

	while (left->count > 0 || right->count > 0)
	{
		if (left->count > 0 && right->count > 0)
		{
			if(strcmp(left->first->value, right->first->value) >= 0)
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

	return result;
}
