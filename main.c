/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:40 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/12 18:02:59 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	t = 0;
	int	t2 = 0;
	int	tmp = __LONG_MAX__;
	int	tmp2 = 0;
	t = ft_printf(" %p k", &tmp);
	printf("\n");
	t2 = printf(" %p k", &tmp);
	printf("\n");

	printf("t: %d t2: %d\n", t, t2);
	return (0);
}