int		search(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

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

int		check_valid_str(char *str, char *base)
{
	int i;
	int j;
	int l;

	i = 0;
	l = ft_strlen(base);
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0' && str[i] != base[j])
			j++;
		if (j == l)
			return (0);
		i++;
	}
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int num_base;
	int rs;
	int ng_mark;

	i = 0;
	rs = 0;
	num_base = ft_strlen(base);
	ng_mark = 0;
	if (str[0] == '-')
		ng_mark = 1;
	if (!(check_valid_base(base) && check_valid_str(str, base)))
		return (0);
	while (i < ft_strlen(str))
	{
		rs *= num_base;
		rs += search(str[i], base);
	}
	return (rs);
}
