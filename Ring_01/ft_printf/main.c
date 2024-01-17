#include "ft_printf.h"

int	main(void)
{
	char	str[] = "hola que tal";
	int		num1;
	int		num2;
	int		num3;

	num1 = 214748364;
	num2 = -214748364;
	num3 = num1;
	ft_printf("%s%s%s", "And ", "some", "joined");
	printf("\n");
	printf("%%");
	printf("\n");
	
	ft_printf("%%c", '0');
	printf("\n");
	printf("%%c", '0');
	printf("\n");
	ft_printf("s: -%s", str);
	printf("\n");
	printf("s: -%s", str);
	printf("\n");
	ft_printf("p: %p", str);
	printf("\n");
	printf("p: %p", str);
	printf("\n");
	ft_printf("d & i: %d & %i", num3, num3);
	printf("\n");
	printf("d & i: %d & %i", num3, num3);
	printf("\n");
	ft_printf("u: %u", num3);
	printf("\n");
	printf("u: %u", num3);
	printf("\n");
	ft_printf("x & X: %x %X", num3, num3);
	printf("\n");
	printf("x & X: %x %X", num3, num3);
	printf("\n");
	ft_printf("percent: %%");
	printf("\n");
	printf("normpercent: %%");
	printf("\n");
	ft_printf("novar: %");
	printf("\n");
	printf("novar: %");
	printf("\n");
	
	return (0);
}