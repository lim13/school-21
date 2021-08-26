#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main(void) {
	int u;

	u = 'A';
	printf("%c\n", ft_tolower(u));
	u = 'd';
	printf("%c\n", ft_tolower(u));
	u = 48;
	printf("%c\n", ft_tolower(u));
	u = 66;
	printf("%c\n", ft_tolower(u));
	u = 119;
	printf("%c\n", ft_tolower(u));
	printf("\n");

	u = 'A';
	printf("%c\n", tolower(u));
	u = 'd';
	printf("%c\n", tolower(u));
	u = 48;
	printf("%c\n", tolower(u));
	u = 66;
	printf("%c\n", tolower(u));
	u = 119;
	printf("%c\n", tolower(u));
}
