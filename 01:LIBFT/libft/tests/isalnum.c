#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main(void)
{
	int u;

	u = 101;
	printf("%d\n", ft_isalnum(u));
	u = 49;
	printf("%d\n", ft_isalnum(u));
	u = 48;
	printf("%d\n", ft_isalnum(u));
	u = 172;
	printf("%d\n", ft_isalnum(u));
	u = 133;
	printf("%d\n", ft_isalnum(u));
	printf("\n");

	u = 101;
	printf("%d\n", isalnum(u));
	u = 49;
	printf("%d\n", isalnum(u));
	u = 48;
	printf("%d\n", isalnum(u));
	u = 172;
	printf("%d\n", isalnum(u));
	u = 133;
	printf("%d\n", isalnum(u));
}