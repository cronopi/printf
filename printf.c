#include "printf.h"

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

int	ft_index(char *str, int i, va_list arguments)
{
	char	every_char;
	char	*every_string;
	int		every_integer;

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
		printf("check de d\n");
		//Imprime un número decimal (base 10)
		//
	}
	else if (str[i + 1] == 'i')
	{
		every_integer = va_arg(arguments, int);
		ft_putnbr_fd(every_integer, 1);
	}
	else if (str[i + 1] == 'u')
	{
		printf("check de u\n");
		//Imprime un número decimal (base 10) sin signo.
		//
	}
	else if (str[i + 1] == 'x')
	{
		printf("check de x\n");
		// Imprime un número hexadecimal (base 16) en minúsculas.
		//
	}
	else if (str[i + 1] == 'X')
	{
		printf("check de X\n");
		// Imprime un número hexadecimal (base 16) en mayúsculas.
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
	//char	N_devuelto;

	alcachofa = 'a';
	puerro = 'b';
	number = 5;
	ft_printf("verduras: %c %c %s %i %%", alcachofa, puerro, array, number);
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


