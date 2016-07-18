int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	int l;
	int i;

	l = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i + l] = src[i];
		i++;
	}
	dest[i + l] = '\0';
	return (dest);
}
