/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:15:36 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/12 17:34:04 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_char(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

void	ft_putnbr_hex(long int nbr, char *base, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_hex(nbr * -1, base, fd);
		return ;
	}
	if (nbr / 16 > 0)
	{
		ft_putnbr_hex(nbr / 16, base, fd);
		ft_putnbr_hex((nbr % 16), base, fd);
	}
	else
		ft_putchar_fd(base[nbr], fd);
}

void	putaddr(long int nbr, char *base, int fd)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_hex(nbr, base, fd);
}


int	ft_printf(const char *s, ...)
{
	size_t	nb_write = 0;
	va_list ptr;
	va_start(ptr, s);
	void	*tmp;

	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'd')
				ft_putnbr_fd(va_arg(ptr, int), 1);
			if (*s == 'c')
				ft_putchar_fd(va_arg(ptr, int) % 256, 1);
			if (*s == 's')
			{
				tmp = va_arg(ptr, void *);
				if (!tmp)
				{
					s++;
					nb_write += 6;
					ft_putstr_fd("(null)", 1);
					continue;
				}
				while (*(char *)tmp)
				{
					ft_putchar_fd(*(char *)tmp, 1);
					tmp++;
					nb_write++;
				}
				s++;

				continue;
			}
			if (*s == 'p')
				putaddr((long int)tmp, "0123456789abcdef", 1);
			nb_write++;
		}
		else
		{
			ft_putchar_fd(*s, 1);
			nb_write++;
		}
		s++;
	}
	return nb_write;
}

