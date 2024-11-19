/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:15:36 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/19 12:43:13 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_printf(const char *s, ...)
{
	size_t			nb_write;
	va_list			ptr;
	void			*tmp;

	nb_write = 0;
	va_start(ptr, s);
	tmp = NULL;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
				nb_write += ft_putchar_fd('%', 1);
			if (*s == 'd' || *s == 'i')
				nb_write += ft_putnbr_fd(va_arg(ptr, int), 1);
			if (*s == 'u')
			{
				tmp = (char *)u_ft_itoa(va_arg(ptr, unsigned int));
				nb_write += ft_putstr_fd(tmp, 1);
				free(tmp);
			}
			if (*s == 'c')
			{
				ft_putchar_fd(va_arg(ptr, int) % 256, 1);
				nb_write++;
			}
			if (*s == 's')
			{
				tmp = va_arg(ptr, void *);
				if (!tmp)
				{
					s++;
					nb_write += ft_putstr_fd("(null)", 1);
					continue ;
				}
				nb_write += ft_putstr_fd((char *)tmp, 1);
				s++;
				continue ;
			}
			if (*s == 'x' || *s == 'X')
			{
				int count = 1;
				if (*s == 'x')
					ft_putnbr_hex(va_arg(ptr, unsigned int), "0123456789abcdef", 1, &count);
				else
					ft_putnbr_hex(va_arg(ptr, unsigned int), "0123456789ABCDEF", 1, &count);
				nb_write += count;
			}
			if (*s == 'p')
			{
				tmp = va_arg(ptr, void *);
				if (tmp == 0)
					nb_write += ft_putstr_fd("(nil)", 1);
				else
					nb_write += ft_putaddr((long int)tmp, "0123456789abcdef", 1) + 1;
			}
		}
		else
			nb_write += ft_putchar_fd(*s, 1);
		s++;
	}
	return (nb_write);
}
