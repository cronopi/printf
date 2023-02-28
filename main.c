#include "ft_printf.h"

int	main(void)
{
	//char	puerro;
	//double	numerico;
	//void	*pointer;
	//unsigned int	nonegativo;
	char	N_devuelto;

	//nonegativo = -555;
	//puerro = 'b';
	//numerico = 64326;
	//pointer = &number;

	int		hex;
	hex = 0;
	N_devuelto = ft_printf("verduras: %x  ", hex);
	ft_printf("\n%i\n", N_devuelto);
	N_devuelto = printf("verduras: %x  ", hex);
	printf("\n%i\n", N_devuelto);

/* 	char	alcachofa;
	alcachofa = '0';
	ft_printf("verduras: %c %c %c  ", alcachofa, alcachofa, alcachofa);
	N_devuelto = printf("verduras: %c %c %c  ", alcachofa, alcachofa, alcachofa);
	printf("\n%i\n", N_devuelto); */


/* 	N_devuelto = ft_printf("verduras: %s ", NULL);
	printf("\n%i\n", N_devuelto);
	N_devuelto = printf("verduras: %s ", NULL);
	printf("\n%i\n", N_devuelto);
 */

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
