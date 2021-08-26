
#include "../libft.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
	int c;
	size_t len;

	char str[5] = "asdf\0";
	len = 10;
	c = 45;
	printf("%s\n", ft_memset(str, c, len));
	printf("%s\n", memset(str, c, len));
}
