/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:40 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/13 21:04:08 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int	t = 0;
	int	t2 = 0;

	t = ft_printf(" %x %x %x %x %x %x %x", LONG_MIN, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n");
	t2 = printf(" %x %x %lx %lx %lx %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n");

	printf("ft_printf: %d printf: %d\n", t, t2);
	return (0);
}