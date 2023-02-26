#include "ft_printf.h"
#include <stdint.h>

void	ft_hex_print_void(void *ptr, int upper_lower)
{

	printf("que lo que:%p\n", ptr);
	write(1, "0x", 2);
	ft_hex_print(ft_ptrtohex((unsigned long int)ptr), 1);
}
