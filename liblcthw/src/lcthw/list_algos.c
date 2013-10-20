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
	  printf("Debug: elems[%d] value: %s\n",i,elems[i]->value);

	}

	for(i = 0 ; i < size-1 ; i++)
	{
		for(j = i+1; j < size; j++)
		{
			if (method(elems[i]->value, elems[j]->value) > 0)
			{
			    printf("SWAP %s %s\n",(char *)elems[i]->value,(char *)elems[j]->value);
				tmp = elems[i];
				elems[i] = elems[j];
				elems[j] = tmp;
			}
		}
	}

    for(i = 0 ; i < size ;i++)
	{
	  
	  printf("After Debug: elems[%d] value: %s\n",i,(char *)elems[i]->value);

	}

	list->first = elems[0];
	elems[0]->prev=NULL;
	list->last=elems[size - 1];

	for(i=1;i<size;i++)
	{
		elems[i-1]->next = elems[i];
		elems[i]->prev = elems[i-1];
        
		elems[i]->next = NULL;
	}

    for(tmp=list->first ; tmp!=NULL ;tmp=tmp->next)
	{
	  printf("COCK %s \n",(char *)tmp->value);
	}

free(elems);

	return 0;

error:
return 1;
}
