/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_specs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 03:50:15 by cmeowth           #+#    #+#             */
/*   Updated: 2020/02/28 19:43:02 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_number(const char **format)
{
	int			number;

	number = 0;
	while (ft_isdigit(**format))
	{
		number = (number * 10) + (**format - '0');
		(*format)++;
	}
	return (number);
}

void			digit(const char **format, t_info *info)
{
	if (*(*format - 1) != '.')
		set_width(format, info);
}

void			set_width(const char **format, t_info *info)
{
	info->width = get_number(format);
}

void			set_precision(const char **format, t_info *info)
{
	(*format)++;
	info->point = 1;
	info->precision = get_number(format);
}
