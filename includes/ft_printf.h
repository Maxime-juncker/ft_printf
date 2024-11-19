/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:18:15 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/19 15:30:31 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <libft.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);

#endif