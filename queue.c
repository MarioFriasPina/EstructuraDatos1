#include "structures.h"

//Returns 1 if the queue is empty, 0 if it has elements
int		emptyPqueue(t_pqueue *queue)
{
	if (queue->first)
		return (0);
	else
		return (1);
}

//Adds a new node to the queue. 
void	enPqueue(t_pqueue *queue, int value, int priority)
{
	t_node *curr, *temp;
	t_node *node = (t_node *)malloc(sizeof(t_node));

	if (node == NULL)
	{
		printf("Error while allocating memory for node\n");
		return;
	}
	node->value = value;
	node->next = NULL;
	node->priority = priority;
	if (emptyPqueue(queue))
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		curr = queue->first;
		while (curr->next && curr->next->priority <= node->priority)
			curr = curr->next;
		if (curr->next)
		{
			temp = curr->next;
			curr->next = node;
			node->next = temp;
		}
		else
		{
			queue->last->next = node;
			queue->last = node;
		}
	}
}

//Removes the first value from the queue.
int		dePqueue(t_pqueue *queue)
{
	t_node *first;

	if (emptyPqueue(queue))
		return (0);
	first = queue->first;
	if (queue->first == queue->last)
		queue->last = NULL;
	queue->first = first->next;
	free(first);
	first = NULL;
	return (1);
}

//Initiates a new Queue
t_pqueue	*initPqueue(void)
{
	t_pqueue *new;

	new = (t_pqueue *)malloc(sizeof(t_pqueue));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

//Frees the memory of the queue.
void	freePqueue(t_pqueue *queue)
{
	while (!dePqueue(queue));
	free(queue);
	queue = NULL;
}

//Prints the queue with a tab between the values.
void	printPqueue(t_pqueue *queue)
{
	t_node *curr;

	curr = queue->first;
	while (curr)
	{
		printf("%d\t", curr->value);
		curr = curr->next;
	}
	printf("\n");
}

//Prints the queue with their respective priority.
void	printPriorityQueue(t_pqueue *queue)
{
	t_node	*curr;

	curr = queue->first;
	while (curr)
	{
		printf("%d-%d ", curr->value, curr->priority);
		curr = curr->next;
	}
	printf("\n");
}
