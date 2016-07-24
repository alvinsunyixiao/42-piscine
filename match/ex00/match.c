#include <stdio.h>

int		no_star_match(char **s1, char **s2)
{
	int j;

	j = 0;
	while (**s1 == **s2)
	{
		if (!(*(*s2 + j)) || *(*s2 + j) == '*')
		{
			*s1 += j;
			*s2 += j;
			return (1);
		}
		j++;
	}
	return (0);
}

int		s_match(char **s1, char **s2, int s_mark)
{
	int j;

	j = 0;
	if (s_mark)
		while (**s1)
		{
			j = 0;
			while (**s1 == **s2)
			{
				if (!(*(*s2 + j)) || *(*s2 + j) == '*' || (!*(*s1 + j)))
				{
					*s1 += j;
					*s2 += j;
					return (1);
				}
				j++;
			}
			*s1 += 1;
		}
	else
		return (no_star_match(s1, s2));
	return (0);
}

int		check_rest(char *str)
{
	while (*str)
		if (*(str++) != '*')
			return (0);
	return(1);
}

int		match(char *s1, char *s2)
{
	int i1;
	int i2;
	int s_mark;

	i1 = 0;
	while (*s1)
	{
		s_mark = 0;
		while (s2[0] == '*')
		{
			s_mark = 1;
			if (!(*(++s2)))
				return (1);
		}
		if (!(s_match(&s1, &s2, s_mark)))
			return (0);
	}
	return (1 & check_rest(s2));
}
