#include "printf.h"

void	ft_index(char *str, int i)
{
	if (str[i + 1] == 's')
	{

	}
	else if (str[i + 1] == 'i')
	{
		//escribe los números del parámetro contiene los números enteros
	}
	else if (str[i + 1] == 'd')
	{
		//escribe los numeros y decimales del parámetro que es un decimal
	}
	else if (str[i + 1] == 'c')
	{
		//escribe el caracter del parámetro que es una letra
	/*	void	ft_putchar(char c)
		{
			write(1, &c, 1);
		}
		*/
	}
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			ft_index(s, i);
			/*
				en caso de que encuentre un % yo quiero:
					comprobar en la siguinte posición[i + 1] si es una c d i x etc
					que i avance 2 posiciones puesto que yo no quiero imprimir el %c
			*/
		}
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	i = ft_putstr((char *)str);
	return (i);
}

int	main(void)
{
	//char	str[] = "Hello world\n";
	//char	*alcachofa;
	//int		puerro;
	//float	patata;
	int		N_devuelto;

	//ft_printf("verduras: %s %i %d", alcachofa, puerro, patata);
	N_devuelto = ft_printf("hola\n");
	//printf("hola\n");
	return (0);
}
/*
	imprimir palabros
	imprimir un char

	va_list son los puntos suspensivos
	patata,puerro acachofa nodos de la lista
	los parámetros se almacenan(al menos en este caso) en direcciones de memoria contiguas.


	va_start= dos parámetros en una lista de argumentos y el otro es la variable anterior.
	va_list = es un tipo de variable, que almacena una lista de argumentos variables.
	no sabes que tipo de variable es ni cuantas tengo, ni nada.
	va_arg = la forma de extraer argumentos de la lista, recibe 2 parámetros.
	el primero es la lista. y el segundo, es el tipo de variable.
	una vez extrae el argumento de la lista avanza al siguiente nodo(o posición)
<
	me falta saber que tipo de variable es cada una para poder extraerla bien, y poder trabajar con ella.


	if (str[i] = %)
	{
		if(str[i + 1] = s)
		{
			funcion_strings()
		}
		else if(str[i + 1] = i)
		{

		}
		else if(str[i + 1] = d)
		{

		}
	}
	cuando deje de usar las listas, tengo que usar va_end como si fuese un close(fd)



*/


