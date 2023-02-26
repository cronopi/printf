#include "ft_printf.h"

int	main(void)
{
	char	array[] = "Hello world";
	char	alcachofa;
	char	puerro;
	int		number;
	double	numerico;
	unsigned int	nonegativo;
	int				hex;
	void	*pointer;
	//char	N_devuelto;

	alcachofa = '0';
	puerro = 'b';
	number = 5;
	numerico = 64326;
	nonegativo = 333;
	hex = 938;
	pointer = &number;
	ft_printf("verduras: %c %c %s %i %% %d %u %X %p", alcachofa, puerro, array, number, numerico, nonegativo, hex, pointer);
	//printf("este el void pointer:%p\n", str);
	//N_devuelto = ft_printf("verduras: %c %c", alcachofa, puerro);
	return (0);
}
