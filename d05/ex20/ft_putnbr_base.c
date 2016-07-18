int		ft_putchar(char c);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		check_valid_base(char *base)
{
	int l;
	int i;
	int j;

	i = 0;
	l = ft_strlen(base);
	if (l <= 1)
		return (0);
	while (i < l - 1)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] <= 31)
			return (0);
		while (j < l)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		numeric_base;
	long	n;

	numeric_base = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (!check_valid_base(base))
		return ;
	while (n > 0)
	{
		ft_putchar(base[n % numeric_base]);
		n /= numeric_base;
	}
}
