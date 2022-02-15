/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:44:37 by cmois             #+#    #+#             */
/*   Updated: 2021/07/24 15:35:42 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# define BASE16_MIN	"0123456789abcdef"
# define BASE16_MAJ "0123456789ABCDEF"

typedef struct s_format
{
	va_list		paraminfo;
	int			zero;
	int			dash;
	int			number;
	char		*param_str;
	char		param_char;
	int			total_length;
	long long	param_number;
	long long	param_pointer;

}	t_format;

int		ft_printf(const char *str, ...);
int		ft_is_it_letter(char c);
int		ft_strlen(char *str);
void	ft_putchar(t_format *format, char c);
void	ft_putstr(t_format *format, char *str);
void	ft_give_value_of_letter(t_format *format, char c);
void	ft_putnbr(t_format *format, long long nbr);
void	ft_treat_hexa(t_format *format, char c);

#endif
