#include "stack.h"

t_stack	*create(void *data)
{
	t_stack	*tmp;

	if (!(tmp = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	tmp->next = 0;
	tmp->data = data;
	return (tmp);
}

void	*pop(t_stack **stack)
{
	void	*data;
	t_stack	*tmp;

	if (!(*stack))
		return (0);
	data = (*stack)->data;
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	return (data);
}

void	push(t_stack **stack, void *data)
{
	t_stack	*tmp;

	if (!(tmp = create(data)))
		return ;
	tmp->next = *stack;
	*stack = tmp;
}
