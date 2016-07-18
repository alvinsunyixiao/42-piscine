int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int str_len;
	int search_len;

	i = 0;
	str_len = ft_strlen(str);
	search_len = ft_strlen(to_find);
	if (search_len == 0)
		return str;
	while (i < str_len - search_len)
	{
		j = i;
		while (j <= i + search_len)
		{
			if (j == i + search_len)
				return (str + i);
			if (str[i] != to_find[j - i])
				break ;
			j++;
		}
	}
	return (NULL);
}
