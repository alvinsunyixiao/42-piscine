int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;
	int sl;

	sl = ft_strlen(src);
	while (i < sl)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (sl);
}
