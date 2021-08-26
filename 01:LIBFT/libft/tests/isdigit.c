#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int u;

	u = 101;
	printf("%d\n", ft_isdigit(u));
	u = 49;
	printf("%d\n", ft_isdigit(u));
	u = 48;
	printf("%d\n", ft_isdigit(u));
	u = 172;
	printf("%d\n", ft_isdigit(u));
	u = 133;
	printf("%d\n", ft_isdigit(u));
	printf("\n");

	u = 101;
	printf("%d\n", isdigit(u));
	u = 49;
	printf("%d\n", isdigit(u));
	u = 48;
	printf("%d\n", isdigit(u));
	u = 172;
	printf("%d\n", isdigit(u));
	u = 133;
	printf("%d\n", isdigit(u));
}