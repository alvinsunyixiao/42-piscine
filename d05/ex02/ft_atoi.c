int		ft_atoi(char *str)
{
	int n_mark;
	long rs;
	int i;

	rs = 0;
	i = 0;
	n_mark = 0;
	if (str[0] == '-')
	{
		n_mark = 1;
		i++;
	}
	if (str[0] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rs *= 10;
		rs += str[i] - 48;
	}
	if (n_mark)
		rs = -rs;
	return (rs);
}
