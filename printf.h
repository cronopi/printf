#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putstr(char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);
void	ft_hex_print(char *str, int upper_lower);
char	*ft_itohex(int number);
double	ft_decimal(double number);

#endif
