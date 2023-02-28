#include "ft_printf.h"
#include <stdint.h>

char	*ft_hex_print_void(void *ptr, int upper_lower)
{
	char	*str;
	if (ptr == 0)
		str = ft_strdup("(null)");
	else
	{
		str = ft_ptrtohex((unsigned long int)ptr);
		write(1, "0x", 2);
	}
		ft_hex_print(str, 1);
	return (str);
}
