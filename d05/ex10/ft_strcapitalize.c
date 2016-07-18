int		ft_putchar(char c);

int		check_alphanumeric(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		while (!check_alphanumeric(str[i]) && str[i] != '\0')
			i++;
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' - 'A';
		while (check_alphanumeric(str[i]))
			i++;
	}
	return (str);
}
