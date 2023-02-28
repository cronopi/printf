#include "ft_printf.h"

int	ft_index(char *str, int i, va_list arguments, int *j)
{
	char	every_char;
	char	*every_string;
	int		every_integer;
	double	every_double;
	unsigned int every_unsigned_int;
	int		every_hex;
	void	*every_pointer;
	char	*test;
	char	*test2;

	if (str[i + 1] == 'c')
	{
		every_char = va_arg(arguments, int);
		ft_putchar(every_char);
		(*j)++;
	}
	else if (str[i + 1] == 's')
	{
		every_string = va_arg(arguments, char *);
		ft_putstr(every_string);
		(*j) = (*j) + ft_strlen(every_string);
	}
	else if (str[i + 1] == 'p')
	{
		every_pointer = va_arg(arguments, void *);
		ft_hex_print_void(every_pointer, 1);
		//(*j) = (*j) + ft_strlen(every_pointer);
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
		(*j) = (*j) + ft_strlen(test = ft_itoa(every_integer));
		free(test);
	}
	else if (str[i + 1] == 'u')
	{
		every_unsigned_int = va_arg(arguments, unsigned int);
		ft_decimal(every_unsigned_int);
		(*j) = (*j) + ft_strlen(test = ft_itoa(every_integer));
		free(test);
	}
	else if (str[i + 1] == 'x')
	{
		every_hex = va_arg(arguments, int);
		ft_hex_print(ft_itohex(every_hex), 1);
		(*j) = (*j) + ft_strlen(test = ft_itoa(every_integer));
		free(test);
	}
	else if (str[i + 1] == 'X')
	{
		every_hex = va_arg(arguments, int);
		ft_hex_print(ft_itohex(every_hex), 2);
		(*j) = (*j) + ft_strlen(test = ft_itoa(every_integer));
		free(test);
	}
	else if (str[i + 1] == '%')
	{
		write(1, "%", 1);
		(*j)++;
	}
	i = i + 2; // puede dar problemas cuando es la última posición.

	return (i);
}

int	ft_string_copy(char *str, va_list arguments)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i = ft_index(str, i, arguments, &j);
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			j++;
		}
	}
	return (j);
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


