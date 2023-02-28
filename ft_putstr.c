#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		write(1, "(null)", 6);
	else
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
}
