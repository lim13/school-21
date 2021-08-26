
#include "../libft.h"
#include <string.h>
#include <stdio.h>


int main(void)
{
	char str[5] = "hhhh";
	size_t n = 3;
	ft_bzero(str, n);
	printf("%s\n", str);
}