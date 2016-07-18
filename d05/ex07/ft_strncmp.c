int	min_strlen(char *s1, char *s2, unsigned int n)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (n > i + 1)
		return (i + 1);
	else
		return (n);
}

int	ft_strcmp(char *s1, char *s2, unsigned int n)
{
	int l;
	int i;

	l = min_strlen(s1, s2, n);
	i = 0;
	while (i < l)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
