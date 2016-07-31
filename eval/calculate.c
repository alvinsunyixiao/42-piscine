#include "calculate.h"

char	*preccmp(t_stack **stack, char *c)
{
	char *opp;

	if (!(*stack))
		return (0);
	opp = (char*)((*stack)->data);
	if ((*opp == '*' || *opp == '/' || *opp == '%') && (*c == '+' || *c == '-'))
	{
		pop(stack);
		return (opp);
	}
	else
	{
		push(stack, c);
		return (0);
	}
}

t_stack	*calculate(char *str)
{
	int		*nbr;
	char	*opp;
	t_stack	*num_stack;
	t_stack	*opp_stack;

	num_stack = 0;
	opp_stack = 0;
	while (str)
	{
		nbr = (int*)malloc(sizeof(int));
		*nbr = ft_atoi(&str);
		push(&num_stack, nbr);
	}
}
