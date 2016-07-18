int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int dl;
	int i;
	int sl;

	i = 0;
	dl = ft_strlen(dest);
	sl = ft_strlen(src);
	while (i < sl)
	{
		dest[i + l] = src[i];
		i++;
	}
	dest[i + l] = '\0';
	return (dl + sl);
}
