/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:50:58 by cmois             #+#    #+#             */
/*   Updated: 2021/07/24 14:04:24 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(t_format *format)
{
	format->param_str = NULL;
	format->param_number = 0;
	format->total_length = 0;
	format->zero = 0;
	format->dash = 0;
	format->number = 0;
	format->param_pointer = 0;
}

void	ft_parser(const char *str, t_format *format)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_is_it_letter(*str))
				ft_give_value_of_letter(format, *str);
			if (ft_is_it_letter(*str))
				str++;
		}
		else
		{
			ft_putchar(format, *str);
			str++;
		}
	}
}

int	ft_printf(const char *str, ...)
{
	t_format	*format;
	int			i;

	i = 0;
	format = (t_format *)malloc(sizeof(t_format));
	if (!format)
		return (-1);
	ft_init_struct(format);
	va_start(format->paraminfo, str);
	ft_parser(str, format);
	va_end(format->paraminfo);
	i = format->total_length;
	free(format);
	return (i);
}
