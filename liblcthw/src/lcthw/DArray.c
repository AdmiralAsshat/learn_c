#include <lcthw/DArray.h>

DArray *DArray_create(size_t element_size, size_t initial_max)
{
	DArray *array = malloc(sizeof(DArray));
	check_mem(array);
	array->max = initial_max;
	check(array->max > 0, "You must set an initial max > 0.");

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
	int elem = 0;
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

static inline int DArray_resize(DArray *array, size_t newsize)
{
	array->max = newsize;
	check(array->max > 0, "The newsize must be > 0");

	void *contents = realloc(array->contents, array->max * sizeof(void *));
	// check contents and assume realloc doesn't harm the original on error

	check_mem(contents);

	array->contents = contents;

	return 0;
error:
	return -1;
}

int DArray_expand(DArray *array)
{
	size_t old_max = array->max;
	check(DArray_resize(array, array->max + array->expand_rate) == 0,
		"Failed to expand array to new size: %d",
		array->max + (int)array->expand_rate);

	memset(array->contents + old_max, 0, array->expand_rate + 1);
	return 0;

error:
	return -1;
}


int DArray_contract(DArray *array)
{
	int new_size = array->end < (int)array->expand_rate ? (int)array->expand_rate : array->end;

	return DArray_resize(array, new_size + 1);

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
	check(array->end -1 >= 0, "Attempt to pop from empty array.");

	void *el = DArray_remove(array, array->end - 1);
	array->end--;

	if(DArray_end(array) > (int)array->expand_rate && DArray_end(array) % array->expand_rate) 
	{
	DArray_contract(array);
	}

	return el;

error:
	return NULL;
}

void DArray_clear_destroy(DArray *array)
{
	DArray_clear(array);
	DArray_destroy(array);
}
