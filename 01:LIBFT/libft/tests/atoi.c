
#include <stdio.h>
#include "../libft.h"

int main(void)
{
	char str[] = "ksdnfb10293skfj";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));

	char str1[] = "10293skfj";
	printf("%d\n", ft_atoi(str1));
	printf("%d\n", atoi(str1));

	char str2[] = " -+293";
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", atoi(str2));

	char str3[] = "0293";
	printf("%d\n", ft_atoi(str3));

	char str4[] = "10293";
	printf("%d\n", ft_atoi(str4));

	char str5[] = "        \t\r\n2147483649";
	printf("%d\n", ft_atoi(str5));
	printf("%d\n", atoi(str5));
}