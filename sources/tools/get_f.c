/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 03:50:45 by cmeowth           #+#    #+#             */
/*   Updated: 2020/02/28 19:43:49 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_f(long double *number, t_info *info)
{
	if (info->length & LENGTH_LLL)
		*number = (long double)va_arg(info->ap, long double);
	else
		*number = (double)va_arg(info->ap, double);
}
