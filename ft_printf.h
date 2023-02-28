#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
void	ft_putstr(char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);
void	ft_hex_print(char *str, int upper_lower);
char	*ft_itohex(int number);
char	*ft_hex_print_void(void *ptr, int upper_lower);
char	*ft_ptrtohex(unsigned long int number);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*ft_print_utoa(unsigned int number);
char	*ft_strdup(const char *s);

#endif
