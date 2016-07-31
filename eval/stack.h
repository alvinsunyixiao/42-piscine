#ifndef STACK_H
# define STACK_H
# include <stdlib.h>

typedef struct		s_stack
{
	struct s_stack	*next;
	void			*data;
}					t_stack;

void				*pop(t_stack **stack);
void				push(t_stack **stack, void *data);

#endif
