#include "printf.h"

int	ft_check_base(char *base, int i, char *str)
{
	int	j;

	j = 0;
	while (str[i] != base[j] && base[j] != '\0')
		j++;
	return (j);
}

int	ft_check_parameters2(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_parameters1(char *str, int i, char *base)
{
	int	sign;

	sign = 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	if (ft_check_parameters2(base) == 0)
		return (0);
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	lengh;
	int	i;
	int	j;
	int	nbr;
	int	sign;

	lengh = 0;
	nbr = 0;
	i = 0;
	sign = ft_check_parameters1(str, i, base);
	if (sign == 0)
		return (0);
	while (base[lengh] != '\0')
		lengh++;
	while (str[i] != base[ft_check_base (base, i, str)])
		i++;
	while (str[i] != '\0' && str[i] == base[ft_check_base (base, i, str)])
	{
		j = 0;
		while (str[i] != base[j])
			j++;
		nbr = nbr * lengh + j;
		i++;
	}
	return (sign * nbr);
}

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

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
		ft_putchar(n + 48);
}

void	fill_string(long int nbr, char *str, int i)
{
	int	temp;

	temp = 0;
	while (i-- > 0)
	{
		if (nbr >= 0)
		{
			temp = nbr % 10;
			str[i] = temp + '0';
			nbr = nbr / 10;
		}
	}
}

int	string_size(long long int n, int i)
{
	if (n == 0)
		i = 1;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	itoa_sign(int n)
{
	if (n >= 0)
		return (0);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	long long int	nbr;
	int				sign;

	sign = itoa_sign(n);
	i = 0;
	nbr = (long long int)n;
	i = string_size(nbr, i);
	if (nbr < 0)
		nbr = nbr * -1;
	str = malloc(sizeof(char) * (i + sign + 1));
	if (!str)
		return (NULL);
	str[i + sign] = '\0';
	fill_string(nbr, str, i + sign);
	if (sign)
		str[0] = '-';
	return (str);
}

double	ft_decimal(double number)
{
	char *str;
	int i;

	i = 0;
	str = ft_itoa(number);
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (number);
}

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

void	ft_hex_print(char *str)
{
	int i;

	i = 0;

	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_index(char *str, int i, va_list arguments)
{
	char	every_char;
	char	*every_string;
	int		every_integer;
	double	every_double;
	unsigned int every_unsigned_int;
	int		every_hex;

	if (str[i + 1] == 'c')
	{
		every_char = va_arg(arguments, int);
		ft_putchar(every_char);
	}
	else if (str[i + 1] == 's')
	{
		every_string = va_arg(arguments, char *);
		ft_putstr(every_string);
	}
	else if (str[i + 1] == 'p')
	{
		printf("check de p\n");
		//El puntero void * dado como argumento se imprime en formato hexadecimal.
		//
	}
	else if (str[i + 1] == 'd')
	{
		every_double = va_arg(arguments, double);
		ft_decimal(every_double);
	}
	else if (str[i + 1] == 'i')
	{
		every_integer = va_arg(arguments, int);
		ft_putnbr_fd(every_integer, 1);
	}
	else if (str[i + 1] == 'u')
	{
		every_unsigned_int = va_arg(arguments, unsigned int);
		ft_decimal(every_unsigned_int);
	}
	else if (str[i + 1] == 'x')
	{
		printf("checkeo de x\n");
		every_hex = va_arg(arguments, int);
		printf("%s\n", ft_itohex(every_hex));
		//printf("que imprime el hex:%s\n", ft_itoa(ft_atoi_base(ft_itoa(every_hex), "0123456789abcdef")));
	}
	else if (str[i + 1] == 'X')
	{
		printf("check de X\n");
		every_hex = va_arg(arguments, int);
		//
	}
	else if (str[i + 1] == '%')
	{
		write(1, "%", 1);
	}
	i = i + 2; // puede dar problemas cuando es la última posición.
	return (i);
}

int	ft_string_copy(char *str, va_list arguments)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == '%')
		{
			i = ft_index(str, i, arguments);
		}
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int i;
	va_list arguments;

	va_start(arguments,str);
	i =ft_string_copy((char *)str, arguments);
	va_end(arguments);
	return (i);
}

int	main(void)
{
	char	array[] = "Hello world";
	char	alcachofa;
	char	puerro;
	int		number;
	double	numerico;
	unsigned int	nonegativo;
	int				hex;
	//char	N_devuelto;

	alcachofa = 'a';
	puerro = 'b';
	number = 5;
	numerico = 64326;
	nonegativo = 4444444;
	hex = 10;
	ft_printf("verduras: %c %c %s %i %% %d %u %x", alcachofa, puerro, array, number, numerico, nonegativo, hex);
	//N_devuelto = ft_printf("verduras: %c %c", alcachofa, puerro);
	return (0);
}

/*

	va_list son los puntos suspensivos
	patata,puerro acachofa nodos de la lista
	los parámetros se almacenan(al menos en este caso) en direcciones de memoria contiguas.

	va_start= dos parámetros: una lista de argumentos y el otro es la variable anterior.
	va_list = es un tipo de variable, que almacena una lista de argumentos variables.
	no sabes que tipo de variable es ni cuantas tengo, ni nada.
	va_arg = la forma de extraer argumentos de la lista, recibe 2 parámetros.
	el primero es la lista. y el segundo, es el tipo de variable.
	una vez extrae el argumento de la lista avanza al siguiente nodo(o posición)

	me falta saber que tipo de variable es cada una para poder extraerla bien, y poder trabajar con ella.

	cuando deje de usar las listas, tengo que usar va_end como si fuese un close(fd)

	every_char = va_arg(arguments, int); // asignas a la variable el contenido del argumento y avanzas una posición. (extraes con va la siguiente variable de la lista de argumentos y la asignas a otra variable)
	printf("que imprime esto?:%c\n", every_char);
*/


