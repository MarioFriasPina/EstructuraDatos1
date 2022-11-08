#include "structures.h"

int main(void)
{
	t_pqueue	*q;
	t_circular	*list;
	printf("%s--------Using a Priority Queue--------%s\n", MAG, END);
	q = initPqueue();
	printf("%sOperation  \"Enqueue\"\n%s",MAG,END);
	enPqueue(q, 12, 1);
	enPqueue(q, 14, 2);
	enPqueue(q, 17, 2);
	printPriorityQueue(q);
	printf("%sOperation  \"Multiple enqueue\"\n%s", MAG, END);
	addMultiplePqueue(q);
	printPriorityQueue(q);
	printf("%sOperation  \"Delete node\"\n%s", MAG, END);
	dePqueue(q);
	printPriorityQueue(q);
	printf("%sOperation  \"Search node\"\n%s",MAG, END);
	searchNodePqueue(q,14);
	searchNodePqueue(q,15);
	printf("%sOperation  \"Empty queue?\"\n%s", MAG, END);
	if (emptyPqueue(q))
		printf("%sEmpty queue%s\n\n", BAK, END);
	else
		printf("%sThe queue is not empty%s\n\n", BAK, END);
	printf("%sOperation  \"Size of queue\"\n%s", MAG, END);
	printf("%sThe size of the queue is:%s %s%d%s\n\n", BAK, END, MAG, sizePqueue(q), END);
	printf("%sOperation  \"Free queue\"\n%s", MAG, END);
	freePqueue(q);


	printf("%s--------Use of a circular double-linked list--------%s\n",CYN,END);
	list = initCircular();
	printf("%sOperation  \"Add nodes\"\n%s", CYN, END);
	addfirstCircular(list,6);
	addMiddleCircular(list,4);
	addMiddleCircular(list,5);
	addlastCircular(list,4);
	addlastCircular(list,8);
	printCircular(list);
	printf("%sOperation  \"Add multiple nodes\"\n%s", CYN, END);
	addMultipleCircular(list);
	printCircular(list);
	printf("%sOperation  \"delete node\"\n%s", CYN, END);
	delCircular(list,6);
	printCircular(list);
	printf("%sOperation  \"dele multiple nodes\"\n%s", CYN, END);
	delallCircular(list,4);
	printf("%sOperation  \"Search node\"\n%s", CYN, END);
	searchCircular(list,5);
	printf("%sOperation  \" Average of list\"\n%s", CYN, END);
	avgCircular(list);
	printf("%sOperation  \"Circular double-linked list is empty?\"\n%s", CYN, END);
	if (emptyCircular(list))
		printf("%sEmpty list%s\n\n", BAK, END);
	else
		printf("%sThe list is not empty%s\n\n", BAK, END);
	printf("%sOperation  \"Size of the circular double-linked list\"\n%s", CYN, END);
	printf("%sThe size of the queue is:%s %s%d%s\n\n", BAK, END, CYN, sizeCircular(list), END);
		printf("%sOperation  \"Free the circular double-linked list\"\n%s", CYN, END);
	freeCircular(list);
	return (0);
}
