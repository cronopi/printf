# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

char *ft_itohex(int number)
{
	char	*str;
	int		i;
	int		temp;
	int		nbr;

	i = 0;
	str = 0;
	nbr = number;
	while (number > 0)
	{
		number = number / 16;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	str[i + 1] = '\0';
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

int	main(void)
{
	printf("esto es el main: %s\n", ft_itohex(467));
	return (0);
}

/*
	if (temp >= 10 && temp =< 16)
		str[i] = temp + 87;
	else
		str[i] = temp + '0';

*/
