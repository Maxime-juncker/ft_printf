/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:40 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/12 17:42:45 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	t = 0;
	int	t2 = 0;
	int	tmp = -1;
	t = ft_printf(" %p ", &tmp);
	printf("\n");
	t2 = printf(" %p ", &tmp);
	printf("\n");

	printf("t: %d t2: %d\n", t, t2);
	return (0);
}


