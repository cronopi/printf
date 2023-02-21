#include "printf.h"

int	ft_index(char *str, int i)
{
	if (str[i + 1] == 'c')
	{
		printf("check de c\n");
		//va_start(,str);
		//imprime un solo caracter
		//ft_putchar(char c)
	}
	else if (str[i + 1] == 's')
	{
		printf("check de s\n");
		//Imprime una string
		//
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
		printf("check de i\n");
		//mprime un entero en base 10.
		//ft_putnbr_fd(int n, int fd);
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
		printf("check de porcentaje\n");
		//para imprimir el símbolo del porcentaje.
		//
	}
	i = i + 2;
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == '%')
		{
			i = ft_index(str, i);
		}
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int i;
	char every_char;
	va_list arguments;


	va_start(arguments,str);
	every_char = va_arg(arguments, int);
	printf("que imprime esto?:%c\n", every_char);
	i = ft_putstr((char *)str);
	return (i);
}

int	main(void)
{
	//char	str[] = "Hello world\n";
	int	alcachofa;
	int		puerro;
	//int		N_devuelto;

	alcachofa = 'a';
	puerro = 5;
	ft_printf("verduras: %c %i", alcachofa, puerro);
	//N_devuelto = ft_printf("hola\n");
	//printf("hola\n");
	return (0);
}
/*
	imprimir palabros
	imprimir un char

	va_list son los puntos suspensivos
	patata,puerro acachofa nodos de la lista
	los parámetros se almacenan(al menos en este caso) en direcciones de memoria contiguas.


	va_start= dos parámetros: una lista de argumentos y el otro es la variable anterior.
	va_list = es un tipo de variable, que almacena una lista de argumentos variables.
	no sabes que tipo de variable es ni cuantas tengo, ni nada.
	va_arg = la forma de extraer argumentos de la lista, recibe 2 parámetros.
	el primero es la lista. y el segundo, es el tipo de variable.
	una vez extrae el argumento de la lista avanza al siguiente nodo(o posición)
<
	me falta saber que tipo de variable es cada una para poder extraerla bien, y poder trabajar con ella.

	cuando deje de usar las listas, tengo que usar va_end como si fuese un close(fd)



*/


