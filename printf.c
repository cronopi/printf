#include <stdio.h>

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

int	ft_printf(const char *str, ...)
{
	//if ()

	//else if()

	return (1);
}

int	main(void)
{
	char	str[] = "Hello world\n";
	char	*alcachofa;
	int		puerro;
	float	patata;

	ft_printf("verduras: %s %i %d", alcachofa, puerro, patata);
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


