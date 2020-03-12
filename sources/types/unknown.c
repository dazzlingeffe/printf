/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknown.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 03:53:42 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/28 20:00:40 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		specs_handler(t_info *info)
{
	info->hash = 0;
	if (ft_strchr("BbCcDdFfIiOoSsUuXx", info->type) == NULL)
		info->space = 0;
}

void			unknown(const char **format, t_info *info)
{
	t_data		data;

	info->type = **format;
	specs_handler(info);
	data.str = (char *)*format;
	data.length = 1;
	data.negative = 0;
	apply_specs(info, &data);
}
