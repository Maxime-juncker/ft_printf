/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:15:36 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/14 18:38:01 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

/*
	TODO: remove unsused include
	TODO: check if main.c of .vscode is in git or any useless files
	TODO: norminette...
	TODO: refactor everything
	TODO: make makefile for libft along folder for bin, obj, src, include
	TODO: Check every malloc protection
*/

static size_t	uget_nb_len(unsigned int n)
{
	size_t		i;
	long int	nb;

	nb = (long)n;
	i = 1;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb / 10 > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char	*u_ft_itoa(unsigned int n)
{
	unsigned long int	nb;
	char		*res;
	size_t		i;
	size_t		len;

	len = uget_nb_len(n);
	nb = (unsigned long)n;
	res = malloc(len + 1);
	i = 0;
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
	}
	while (nb > 0)
	{
		res[len - i++ - 1] = (nb % 10) + '0';
		nb /= 10;
	}
	res[len] = '\0';
	return (res);
}

void	ft_putnbr_hex(unsigned long int nbr, char *base, int fd, int *count)
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
			if (*s == '%')
			{
				ft_putchar_fd('%', 1);
				nb_write++;
			}
			if (*s == 'd' || *s == 'i')
			{
				tmp = (void *)ft_itoa(va_arg(ptr, int));
				ft_putstr_fd((char *)tmp, 1);
				nb_write += ft_strlen((char *)tmp);
				free(tmp);
			}
			if (*s == 'u')
			{
				unsigned int t = va_arg(ptr, unsigned int);
				tmp = (void *)u_ft_itoa(t);
				ft_putstr_fd((char *)tmp, 1);
				nb_write += ft_strlen((char *)tmp);
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
				{
					ft_putstr_fd("(nil)", 1);
					nb_write += 5;
				}
				else
					nb_write += putaddr((long int)tmp, "0123456789abcdef", 1) + 1;
			}
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

