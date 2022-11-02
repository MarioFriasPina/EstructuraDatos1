#include "structures.h"

//Returns 1 if the list is empty, 0 if not.
int		emptyCircular(t_circular *lst)
{
	if (lst->first == NULL)
		return 1;
	return 0;
}

//Initiates a new circular list.
t_circular	*initCircular(void)
{
	t_circular *new;

	new = (t_circular *)malloc(sizeof(t_circular));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

//Returns the size of the list.
int		sizeCircular(t_circular *lst)
{
	int		size;
	t_dlist	*index;

	size = 0;
	index = lst->first;
	do
	{
		index = index->next;
		size++;
	} while (index != lst->first);
	return (size);
}

//Adds the value to the end of the list.
void	addCircular(t_circular *lst, int value)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (new == NULL)
	{
		printf("Error while allocating memory for node\n");
		return;
	}
	new->value = value;
	
	if (emptyCircular(lst) == 1)
		lst->first = new;
	else
		lst->last->next = new;

	lst->last = new;
	lst->last->next = lst->first;
	lst->first->past = lst->last;
}

//Adds the value to the start of the list.
void	addfirstCircular(t_circular *lst, int value)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (new == NULL)
	{
		printf("Error while allocating memory for node\n");
		return;
	}
	new->value = value;

	if (emptyCircular(lst) == 1)
		lst->last = new;
	else
		lst->first->past = new;

	new->next = lst->first;
	lst->first = new;
	lst->last->next = lst->first;
	lst->first->past = lst->last;
}

//Prints all the times a specific value is found and its position, and returns the number.
int		searchCircular(t_circular *lst, int value)
{
	t_dlist	*index;
	int		times;
	int		pos;

	times = 0;
	pos = 0;
	index = lst->first;
	do
	{
		if (index->value == value)
		{
			times++;
			printf("Found %d on position %d\n", index->value, pos);
		}
		index = index->next;
		pos++;
	} while (index != lst->first);
	return (times);
}

//Returns the average of the values in the list.
double	avgCircular(t_circular *lst)
{
	t_dlist	*index;
	double	avg;
	double	count;

	avg = 0;
	count = 0;
	index = lst->first;
	do
	{
		avg += index->value;
		count++;
		index = index->next;
	} while (index != lst->first);
	return (avg / count);
}

//Deletes the first time a specific value is found in the list.
void	delCircular(t_circular *lst, int value)
{
	t_dlist	*index;
	t_dlist	*past;

	index = lst->first;
	past = NULL;
	do
	{
		if (index->value == value)
		{
			if (past)
			{
				past->next = index->next;
				index->next->past = past;
				if (index == lst->last)
					lst->last = past;
			}
			else
			{
				lst->first = index->next;
				lst->first->past = lst->last;
				lst->last->next = lst->first;
			}
			free(index);
			return;
		}
		past = index;
		index = index->next;
	} while(index != lst->first);
}

//Deletes all the times a specific value is found in the list.
void	delallCircular(t_circular *lst, int value)
{
	t_dlist	*index;
	t_dlist	*past;
	t_dlist	*cpy;

	index = lst->first;
	past = NULL;
	do
	{
		if (index->value == value)
		{
			if (past)
			{
				past->next = index->next;
				index->next->past = past;
				if (index == lst->last)
					lst->last = past;
			}
			else
			{
				lst->first = index->next;
				lst->first->past = lst->last;
				lst->last->next = lst->first;
			}
			cpy = index;
			index = index->next;
			free(cpy);
		}
		else
		{
			past = index;
			index = index->next;
		}
	} while(index != lst->first);
}

//Prints all the elements in the list with a tab between them
void	printCircular(t_circular *lst)
{
	t_dlist	*index;

	index = lst->first;
	do
	{
		printf("%d\t", index->value);
		index = index->next;
	} while (index != lst->first);
	printf("\n");
}

//Prints all the elements in the list with a tab between them
void	freeCircular(t_circular *lst)
{
	t_dlist	*index, *temp;

	index = lst->first;
	do
	{
		temp = index;
		index = index->next;
		free(temp);
	} while (index != lst->first);
	free(lst);
	lst = NULL;
}
