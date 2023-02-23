#include "printf.h"

/* int	ft_check_base(char *base, int i, char *str)
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
 */

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
		every_hex = va_arg(arguments, int);
		ft_hex_print(ft_itohex(every_hex), 1);
	}
	else if (str[i + 1] == 'X')
	{
		every_hex = va_arg(arguments, int);
		ft_hex_print(ft_itohex(every_hex), 2);
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
	nonegativo = 333;
	hex = 938;
	ft_printf("verduras: %c %c %s %i %% %d %u %X", alcachofa, puerro, array, number, numerico, nonegativo, hex);
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


