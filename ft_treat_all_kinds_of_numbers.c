/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_all_kinds_of_numbers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 23:46:46 by cmois             #+#    #+#             */
/*   Updated: 2021/07/24 15:37:46 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(t_format *format, long long nbr)
{
	if (nbr < 0)
	{
		ft_putchar(format, '-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(format, nbr / 10);
		ft_putnbr(format, nbr % 10);
	}
	else
		ft_putchar(format, (nbr + 48));
}

void	ft_putnbr_hexa(t_format *format, long long nbr, char c)
{
	if (nbr >= 16)
	{
		ft_putnbr_hexa(format, (nbr / 16), c);
		ft_putnbr_hexa(format, (nbr % 16), c);
	}
	else
	{
		if (c == 'x')
			ft_putchar(format, BASE16_MIN[nbr]);
		if (c == 'X')
			ft_putchar(format, BASE16_MAJ[nbr]);
	}
}

void	ft_putnbr_ptr(t_format *format, long long nbr)
{
	if (nbr >= 16)
	{
		ft_putnbr_ptr(format, (nbr / 16));
		ft_putnbr_ptr(format, (nbr % 16));
	}
	else
		ft_putchar(format, BASE16_MIN[nbr]);
}

void	ft_treat_hexa(t_format *format, char c)
{
	if (c == 'x' || c == 'X')
		ft_putnbr_hexa(format, format->param_number, c);
	if (c == 'p')
		ft_putnbr_ptr(format, format->param_pointer);
}
