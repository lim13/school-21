
#include <string.h>
#include <stdio.h>
#include "../libft.h"

int main(void)
{
	char s1[5] =
			"1234";
	char d1[5] = "1235";
	size_t n = 5;
	printf("%s\n", ft_memccpy(d1, s1, 51,  n));
	printf("%s\n", memccpy(d1, s1, 51, n));

	char s2[4] = "123";
	char d2[5] = "1239";
	n = 3;
	printf("%s\n", ft_memccpy(d2, s2, 51, n));
	printf("%s\n", memccpy(d2, s2, 51, n));

	char s3[4] = "123";
	char d3[4] = "123";
	n = 2;
	printf("%s\n", ft_memccpy(d3, s3, 50, n));
	printf("%s\n", memccpy(d3, s3, 50, n));

	char *s4 = NULL;
	char *d4 = NULL;
	n = 0;
	printf("%s\n", ft_memccpy(d4, s4, 50, n));
	printf("%s\n", memccpy(d4, s4, 50, n));

	char s5[4] = "1239";
	char d5[5] = "1239";
	n = 5;
	printf("%s\n", ft_memccpy(d5, s5, 15, n));
	printf("%s\n", memccpy(d5, s5, 15, n));



}