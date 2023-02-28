#include "ft_printf.h"

void	ft_hex_print(char *str, int upper_lower)
{
	int i;

	i = 0;

	while(str[i] != '\0')
	{
		if (upper_lower == 2)
		{
			if (str[i] >= 'a' &&  str[i] <= 'f')
				str[i] = str[i] - 32;
		}
		write(1, &str[i], 1);
		i++;
	}
	free(str);
}
