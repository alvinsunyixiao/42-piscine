int	min_strlen(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (i + 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int l;
	int i;

	l = min_strlen(s1, s2);
	i = 0;
	while (i < l)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
