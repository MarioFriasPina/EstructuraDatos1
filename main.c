#include "structures.h"

int main(void)
{
	t_pqueue	*q;
	t_circular	*list;

	q = initPqueue();
	enPqueue(q, 12, 1);
	enPqueue(q, 14, 3);
	enPqueue(q, 16, 2);
	enPqueue(q, 11, 1);
	enPqueue(q, 19, 1);
	printPriorityQueue(q);

	list = initCircular();
	addCircular(list, 12);
	addCircular(list, 15);
	addCircular(list, 11);
	addCircular(list, 19);
	printCircular(list);
	freePqueue(q);
	freeCircular(list);
	return (0);
}
