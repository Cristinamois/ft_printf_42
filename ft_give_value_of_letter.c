/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_value_of_letter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 23:14:36 by cmois             #+#    #+#             */
/*   Updated: 2021/07/24 14:04:07 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_give_value_part_one(t_format *format, char c)
{
	if (c == 'c')
	{
		format->param_char = va_arg(format->paraminfo, int);
		if (format->number != 1)
			ft_putchar(format, format->param_char);
	}
	if (c == 's')
	{
		format->param_str = va_arg(format->paraminfo, char *);
		if (format->param_str == NULL)
			format->param_str = "(null)";
		if (format->number != 1)
			ft_putstr(format, format->param_str);
	}
	if (c == 'p')
	{
		format->param_pointer = va_arg(format->paraminfo, long long);
		if (format->number != 1 && format->zero != 1)
		{
			write(1, "0x", 2);
			ft_treat_hexa(format, c);
			format->total_length += 2;
		}
	}
}

void	ft_give_value_part_two(t_format *format, char c)
{
	if (c == 'd' || c == 'i')
	{
		format->param_number = va_arg(format->paraminfo, int);
	}
	if (c == 'u')
		format->param_number = va_arg(format->paraminfo, unsigned int);
	if (format->zero != 1 && format->number != 1)
		ft_putnbr(format, format->param_number);
}

void	ft_give_value_part_three(t_format *format, char c)
{
	if (c == 'x' || c == 'X')
	{
		format->param_number = va_arg(format->paraminfo, unsigned int);
		if (format->zero != 1 && format->number != 1)
			ft_treat_hexa(format, c);
	}
	if (c == '%' && format->zero != 1 && format->number != 1)
		ft_putchar(format, '%');
}

void	ft_give_value_of_letter(t_format *format, char c)
{
	if (c == 'c' || c == 's' || c == 'p')
		ft_give_value_part_one(format, c);
	if (c == 'd' || c == 'i' || c == 'u')
		ft_give_value_part_two(format, c);
	if (c == 'x' || c == 'X' || c == '%')
		ft_give_value_part_three(format, c);
}
