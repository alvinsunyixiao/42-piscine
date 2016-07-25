int	ft_count_if(char **tab, int(*f)(char*))
{
	int i;
	int rs;

	i = -1;
	rs = 0;
	while (tab[++i])
		if (f(tab[i]) == 1)
			rs++;
	return (rs);
}
