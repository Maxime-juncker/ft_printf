/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:15:36 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/12 18:00:59 by mjuncker         ###   ########.fr       */
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

void	ft_putnbr_hex(long int nbr, char *base, int fd, int *count)
{
	if (nbr / 16 > 0)
	{
		ft_putnbr_hex(nbr / 16, base, fd, count);
		(*count)++;
		ft_putnbr_hex((nbr % 16), base, fd, count);
	}
	else
		ft_putchar_fd(base[nbr], fd);
}

int	putaddr(long int nbr, char *base, int fd)
{
	int count = 2;
	ft_putstr_fd("0x", 1);
	ft_putnbr_hex(nbr, base, fd, &count);
	return count;
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
			{
				nb_write += putaddr(va_arg(ptr, long int), "0123456789abcdef", 1);
			}
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

