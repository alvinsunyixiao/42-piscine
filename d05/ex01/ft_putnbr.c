int		ft_putchar(char c);

void	print_positive(long nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + 48);
		return ;
	}
	print_positive(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (str[i] == '-')
	{
		n = -n;
		ft_putchar('-');
	}
	print_positive(n);
}
