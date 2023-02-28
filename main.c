#include "ft_printf.h"

int	main(void)
{
	//char	puerro;
	//double	numerico;
	//unsigned int	nonegativo;
	//int				hex;
	//void	*pointer;
	char	N_devuelto;

	//puerro = 'b';
	//numerico = 64326;
	//nonegativo = 333;
	//hex = 938;
	//pointer = &number;

	int		number;
	number = 10;
	N_devuelto = ft_printf("verduras: %i ", number);
	ft_printf("\n%i\n", N_devuelto);
	N_devuelto = printf("verduras: %i ", number);
	printf("\n%i\n", N_devuelto);

/* 	char	alcachofa;
	alcachofa = '0';
	ft_printf("verduras: %c %c %c  ", alcachofa, alcachofa, alcachofa);
	N_devuelto = printf("verduras: %c %c %c  ", alcachofa, alcachofa, alcachofa);
	printf("\n%i\n", N_devuelto); */

/* 	char	array[] = "Hello wolrd";
	N_devuelto = ft_printf("verduras: %p ", array);
	printf("\n%i\n", N_devuelto);
	N_devuelto = printf("verduras: %p ", array);
	printf("\n%i\n", N_devuelto);
 */
	return (0);
}


/* 		if (every_integer > 0)
		{
			(*j)++;
			every_integer = every_integer / 10;
		} */
