/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 03:53:28 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/28 20:00:24 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			type_u(const char **format, t_info *info)
{
	uintmax_t	number;
	t_data		data;

	info->type = **format;
	info->hash = 0;
	get_ui(&number, info);
	data.str = ft_uitoa_base_static(number, 10, 0);
	data.length = (number == 0 && info->width == 0 && info->point == 1
					&& info->precision == 0) ? 0 : ft_strlen(data.str);
	data.negative = 0;
	apply_specs(info, &data);
}
