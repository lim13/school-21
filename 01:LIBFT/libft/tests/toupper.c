#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main(void)
{
	int u;

	u = 'a';
	printf("%c\n", ft_toupper(u));
	u = 49;
	printf("%c\n", ft_toupper(u));
	u = 48;
	printf("%c\n", ft_toupper(u));
	u = 66;
	printf("%c\n", ft_toupper(u));
	u = 119;
	printf("%c\n", ft_toupper(u));
	printf("\n");

	u = 'a';
	printf("%c\n", toupper(u));
	u = 49;
	printf("%c\n", toupper(u));
	u = 48;
	printf("%c\n", toupper(u));
	u = 66;
	printf("%c\n", toupper(u));
	u = 119;
	printf("%c\n", toupper(u));
}