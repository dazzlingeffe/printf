/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 03:50:20 by cmeowth           #+#    #+#             */
/*   Updated: 2020/02/28 19:43:17 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			wildcard(const char **format, t_info *info)
{
	if (*(*format - 1) != '.')
	{
		info->width = va_arg(info->ap, int);
		if (info->width < 0)
		{
			info->minus = 1;
			info->width *= -1;
		}
	}
	else
		info->precision = va_arg(info->ap, int);
	(*format)++;
}
