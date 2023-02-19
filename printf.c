#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{


	return (1);
}

int	main(void)
{
	int numero;

	numero = printf("patata");
	printf("%i", numero);
	return (0);
}

/*
	imprimir palabros
	imprimir un char
*/

