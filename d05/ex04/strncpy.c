char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] = '\0')
			break ;
		i++;
	}
	i++;
	while (i < n)
		dest[i] = '\0';
	return (dest);
}
