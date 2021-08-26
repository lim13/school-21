
#include <string.h>
#include <stdio.h>
#include "../libft.h"

int main(void)
{
	char s1[5] = "1234";
	char d1[5] = "6789";
	size_t n = 5;
	printf("%s\n", ft_memcpy(d1, s1, n));
	printf("%s\n", memcpy(d1, s1, n));

	char s2[4] = "123";
	char d2[5] = "6789";
	n = 5;
	printf("%s\n", ft_memcpy(d2, s2, n));
	printf("%s\n", memcpy(d2, s2, n));

	char s3[5] = "1234";
	char d3[4] = "678";
	n = 4;
	printf("%s\n", ft_memcpy(d3, s3, n));
	printf("%s\n", memcpy(d3, s3, n));

	char *s4 = NULL;
	char *d4 = NULL;
	n = 6;
	printf("%s\n", ft_memcpy(d4, s4, n));
	printf("%s\n", memcpy(d4, s4, n));
}