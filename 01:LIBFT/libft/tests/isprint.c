#include <ctype.h>
#include <stdio.h>
#include "../libft.h"

int main(void)
{
	int u;

	u = 32;
	printf("%d\n", ft_isprint(u));
	u = 49;
	printf("%d\n", ft_isprint(u));
	u = 48;
	printf("%d\n", ft_isprint(u));
	u = 172;
	printf("%d\n", ft_isprint(u));
	u = 133;
	printf("%d\n", ft_isprint(u));
	printf("\n");

	u = 32;
	printf("%d\n", isprint(u));
	u = 49;
	printf("%d\n", isprint(u));
	u = 48;
	printf("%d\n", isprint(u));
	u = 172;
	printf("%d\n", isprint(u));
	u = 133;
	printf("%d\n", isprint(u));
}

