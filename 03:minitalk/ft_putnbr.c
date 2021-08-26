#include "minitalk.h"

void	ft_putnbr(int n)
{
	char	s;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = n * (-1);
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
		{
			s = n + '0';
			write(1, &s, 1);
		}
	}
}
