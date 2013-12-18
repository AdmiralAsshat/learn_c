#include <lcthw/DArray.h>

DArray *DArray_create(size_t element_size, size_t initial_max)
{
	DArray *array = malloc(sizeof(DArray));
	array->max = initial_max;
	array->end = 0;
	array->element_size = element_size;
	array->expand_rate = DEFAULT_EXPAND_RATE;
	array->contents = calloc(initial_max, sizeof(void *));
	
	return(array);

error:
if(array) free(array);
return NULL;
}

void DArray_destroy(DArray *array)
{
	if(array)
	{
		if(array->contents) free(array->contents);
		free(array);
	}
}

void DArray_clear(DArray *array)
{
	int elem;
	// Don't bother clearing an empty array
	if(array->element_size > 0)
	{
		for(elem = 0; elem < array->max; elem++)
		{
			if(array->contents[elem] != NULL)
			{
				free(array->contents[elem]);
			}
		}
	}
}


int DArray_expand(DArray *array)
{

	if(array->end > array->max)
	{
		array->max += array->expand_rate;
	}

	return 0;

error:
	return 1;
}


int DArray_contract(DArray *array)
{
	if(array->max > array->end)
	{
		array->max = array->end;
	}
	return 0;

error:
	return 1;
}


int DArray_push(DArray *array, void *el)
{
	if(array->end == array->max)
	{
		DArray_expand(array);
	}

	int idx = array->end;
	idx++;
	array->contents[idx] = el;
	array->end = idx;

	return 0;

error:
	return 1;
}

void *DArray_pop(DArray *array)
{
	DArray_remove(array, array->end);
	array->end--;
}

void DArray_clear_destroy(DArray *array)
{
	DArray_clear(array);
	DArray_destroy(array);
}
