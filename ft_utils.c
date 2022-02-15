/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:58:40 by cmois             #+#    #+#             */
/*   Updated: 2021/07/17 21:56:03 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(t_format *format, char c)
{
	write(1, &c, 1);
	format->total_length++;
}

void	ft_putstr(t_format *format, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(format, str[i++]);
}

int	ft_is_it_letter(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
