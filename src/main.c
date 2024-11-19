/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:40:42 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/19 15:24:49 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

#include <stdio.h>

int main(void)
{
	int t = 0;
	int t2 = 0;


	printf("\n");
	t = ft_printf(" %x %% %h %", 9223372036854775807LL);
	printf("\n");
	t2 = printf("\a %llx ", 9223372036854775807LL);
	printf("\nft_printf: %d\nprintf: %d\n", t, t2);
	return (0);
}