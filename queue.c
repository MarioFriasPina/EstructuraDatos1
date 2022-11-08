#include "structures.h"
//Function 1 add node
//Adds a new node to the queue. 
void	enPqueue(t_pqueue *queue, int value, int priority)
{
	t_node *curr, *temp;
	t_node *node = (t_node *)malloc(sizeof(t_node));

	if (node == NULL)
	{
		printf("%sError while allocating memory for node%s\n", RED, END);
		return;
	}
	printf("%sThe value%s %s%d%s %sand a priority%s %s%d%s %shas been added to the queue with priority.%s\n\n", BAK, END, MAG, value, END, BAK, END, MAG, priority, END, BAK, END);
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

//Function 2 add multiple consecutive nodes
void    addMultiplePqueue(t_pqueue *queue){
    short int counter, value,priority, i;
    printf("\n%sHow many nodes you want to add? %s", MAG, END);
    scanf("%hd",&counter);
    for (i = 0; i < counter; ++i)
    {
        printf("%sWhat is the value of the node %hd: %s", BAK, i+1, END);
        scanf("%hd",&value);
		printf("%sWhat is the priority of the node %hd: %s", BAK, i+1, END);
        scanf("%hd",&priority);
        enPqueue(queue,value,priority);
	}   
}

//Function 3 delete nodes
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
	printf("%sThe node with value%s %s%d%s  %swith priority%s %s%d%s %swas deleted%s \n\n", BAK, END, MAG, first->value, END, BAK, END, MAG, first->priority, END, BAK, END);
	free(first);
	first = NULL;
	return (1);
}

//Function 4 delete all nodes
//Frees the memory of the queue.
void	freePqueue(t_pqueue *queue)
{
	while (!dePqueue(queue));
	free(queue);
	queue = NULL;
	printf("%sThe queue is empty%s\n\n", GRN, END);
}

//Function 5 search for node

void	searchNodePqueue(t_pqueue *queue, int value)
{
	t_node *index = queue->first;
	short int pos = 0, b = 1;
	
	while(index)
	{
		pos++;
		if(index->value == value)
		{
			printf("%sThe node is located in the position%s %s%hd.%s%sHaving the value:%s %s%d%s %sand priority:%s %s%d%s\n\n", BAK, END, MAG, pos, END, BAK, END, MAG, index->value, END, BAK, END, MAG, index->priority, END);
			b = 0;
		}
		index = index->next;
	} 
	if(b)
		printf("%sNode not found in queue%s\n",RED,END);
}

//Function 6 Queue with pririty is empty
//Returns 1 if the queue is empty, 0 if it has elements
int		emptyPqueue(t_pqueue *queue)
{
	if (queue->first)
		return (0);
	else
		return (1);
}

//Function 7 size of the queue
int	sizePqueue(t_pqueue *queue)
{
	t_node *index = queue->first;
	short int counter = 0; 
	while(index)
	{
		index = index->next;
		counter++;
	}
	return counter;
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


//Prints the queue with their respective priority.
void	printPriorityQueue(t_pqueue *queue)
{
	t_node	*curr;
	short int counter = 0;

	curr = queue->first;
	while (curr)
	{
		counter++;
		printf("%sNode[%s%s%hd%s%s]:%s %s%d%s %swith priority:%s %s%d%s \n\n", BAK, END, MAG, counter, END,  BAK, END, MAG, curr->value, END, BAK, END, MAG, curr->priority, END);
		curr = curr->next;
	}
	printf("\n");
}


