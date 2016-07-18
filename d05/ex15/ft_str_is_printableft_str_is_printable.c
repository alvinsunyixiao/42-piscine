int	ft_is_printable(char *str)
{
	int i;

	while (str[i] != '\0')
	{
		if (str[i] >= 32)
			return (0);
		i++;
	}
	return (1);
}
