/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:40:42 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/19 12:29:30 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int main(void)
{
	int t= 0;
	int t2 = 0;
	void *tmp = NULL;
	
	t = ft_printf(" %y ", tmp);
	// t2 = printf(" %y ");
	printf("\nft_printf: %d\nprintf: %d\n", t, t2);
	return (0);
}