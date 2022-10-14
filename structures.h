#ifndef STRUCTURES_H
# define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define END	"\x1B[0m"

//Double linked list nodes
typedef struct			s_doublelist
{
	int					value;
	struct s_doublelist	*next;
	struct s_doublelist	*past;
}						t_dlist;

//Circular doubly linked list
typedef struct			s_circular
{
	t_dlist				*first;
	t_dlist				*last;
}						t_circular;

//Priority queue nodes
typedef struct		s_node
{
	int				value;
	int				priority;
	struct s_node	*next;
}					t_node;

//Priority queue
typedef struct		s_pqueue
{
	struct s_node	*first;
	struct s_node	*last;
}					t_pqueue;

//Circular doubly linked list functions
int			emptyCircular(t_circular *lst);
t_circular	*initCircular(void);
int			sizeCircular(t_circular *lst);
void		addCircular(t_circular *lst, int value);
void		addfirstCircular(t_circular *lst, int value);
int			searchCircular(t_circular *lst, int value);
double		avgCircular(t_circular *lst);
void		delCircular(t_circular *lst, int value);
void		delallCircular(t_circular *lst, int value);
void		printCircular(t_circular *lst);
void		freeCircular(t_circular *lst);

//Priority queue functions
int			emptyPqueue(t_pqueue *queue);
void		enPqueue(t_pqueue *queue, int value, int priority);
int			dePqueue(t_pqueue *queue);
t_pqueue	*initPqueue(void);
void		freePqueue(t_pqueue *queue);
void		printPqueue(t_pqueue *queue);
void		printPriorityQueue(t_pqueue *queue);

#endif
