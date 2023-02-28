#include "ft_printf.h"

char *ft_itohex(int number)
{
	char	*str;
	int		i;
	int		temp;
	unsigned int		nbr;

	i = 0;
	if (number == 0)
		i = 1;
	str = 0;
	nbr = (unsigned int)(4294967296 + number);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	nbr = (unsigned int)(4294967296 + number);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		if (nbr >= 0)
		{
			temp = nbr % 16;
			if (temp >= 10 && temp <= 16)
				str[i] = temp + 87;
			else
				str[i] = temp + '0';
			nbr = nbr / 16;
		}
	}
	return (str);
}
