/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:36:46 by rcastano          #+#    #+#             */
/*   Updated: 2023/03/01 10:53:47 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_index(char *str, int i, va_list arguments, int *j)
{
	char			every_char;
	char			*every_string;
	int				every_integer;
	unsigned int	every_unsigned_int;
	int				every_hex;
	void			*every_pointer;
	char			*test;
	char			*test2;
	int				algo;

	if (str[i + 1] == 'c')
	{
		every_char = va_arg(arguments, int);
		ft_putchar(every_char);
		(*j)++;
	}
	else if (str[i + 1] == 's')
	{
		every_string = va_arg(arguments, char *);
		ft_putstr(every_string);
		if (every_string)
		(*j) = (*j) + ft_strlen(every_string);
		else
			(*j) = (*j) + 6;
	}
	else if (str[i + 1] == 'p')
	{
		every_pointer = va_arg(arguments, void *);
		test = ft_hex_print_void(every_pointer, 1);
		algo = ft_strlen(test);
		free(test);
		if (every_pointer != 0)
			(*j) = (*j) + algo + 2;
		else
			(*j) = (*j) + algo;
	}
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
	{
		every_integer = va_arg(arguments, int);
		ft_putnbr_fd(every_integer, 1);
		test = ft_itoa(every_integer);
		(*j) = (*j) + ft_strlen(test);
		free(test);
	}
	else if (str[i + 1] == 'u')
	{
		every_unsigned_int = va_arg(arguments, unsigned int);
		test = ft_print_utoa(every_unsigned_int);
		(*j) = (*j) + ft_strlen(test);
		free(test);
	}
	else if (str[i + 1] == 'x')
	{
		every_hex = va_arg(arguments, int);
		ft_hex_print(test = ft_itohex(every_hex), 1);
		(*j) = (*j) + ft_strlen(test);
		free(test);
	}
	else if (str[i + 1] == 'X')
	{
		every_hex = va_arg(arguments, int);
		ft_hex_print(test = ft_itohex(every_hex), 2);
		(*j) = (*j) + ft_strlen(test);
		free(test);
	}
	else if (str[i + 1] == '%')
	{
		write(1, "%", 1);
		(*j)++;
	}
	i = i + 2;
	return (i);
}

int	ft_string_copy(char *str, va_list arguments)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i = ft_index(str, i, arguments, &j);
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			j++;
		}
	}
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arguments;

	va_start (arguments, str);
	i = ft_string_copy ((char *)str, arguments);
	va_end(arguments);
	return (i);
}
