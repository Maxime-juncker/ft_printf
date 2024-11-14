/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:40 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/14 14:11:36 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int	t = 0;
	int	t2 = 0;

	t = ft_printf(" %x ", LONG_MAX);
	printf("\n");
	t2 = printf(" %lx ", LONG_MAX);
	printf("\n");

	printf("ft_printf: %d printf: %d\n", t, t2);
	return (0);
}