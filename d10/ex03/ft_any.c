int		ft_any(char **tab, int(*f)(char*))
{
	int i;

	i = -1;
	while (tab[++i])
	{
		if (f(tab[i]))
			return (1);
	}
	return (0);
}
