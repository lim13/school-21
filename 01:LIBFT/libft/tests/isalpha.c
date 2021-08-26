#include <stdio.h>
#include "../libft.h"
#include <ctype.h>

int main(void)
{
	int u;

	u = 101;
	printf("%d\n", ft_isalpha(u));
	u = 99;
	printf("%d\n", ft_isalpha(u));
	u = 160;
	printf("%d\n", ft_isalpha(u));
	u = 172;
	printf("%d\n", ft_isalpha(u));
	u = 133;
	printf("%d\n", ft_isalpha(u));
	printf("\n");

	u = 101;
	printf("%d\n", isalpha(u));
	u = 99;
	printf("%d\n", isalpha(u));
	u = 160;
	printf("%d\n", isalpha(u));
	u = 172;
	printf("%d\n", isalpha(u));
	u = 133;
	printf("%d\n", isalpha(u));
}