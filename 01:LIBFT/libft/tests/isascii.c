#include <ctype.h>
#include <stdio.h>
#include "../libft.h"

int main(void)
{
	int u;

	u = 199;
	printf("%d\n", ft_isascii(u));
	u = 49;
	printf("%d\n", ft_isascii(u));
	u = 48;
	printf("%d\n", ft_isascii(u));
	u = 172;
	printf("%d\n", ft_isascii(u));
	u = 133;
	printf("%d\n", ft_isascii(u));
	printf("\n");

	u = 199;
	printf("%d\n", isascii(u));
	u = 49;
	printf("%d\n", isascii(u));
	u = 48;
	printf("%d\n", isascii(u));
	u = 172;
	printf("%d\n", isascii(u));
	u = 133;
	printf("%d\n", isascii(u));
}