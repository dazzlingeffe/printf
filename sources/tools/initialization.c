/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 03:51:27 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/28 19:46:04 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_buffer(t_buffer *buffer, int fd)
{
	buffer->index = 0;
	buffer->length = 0;
	buffer->fd = fd;
}

void	initialize_specs(t_info *info)
{
	info->width = 0;
	info->length = 0;
	info->precision = 0;
	initialize_flags(info);
}

void	initialize_flags(t_info *info)
{
	info->hash = 0;
	info->zero = 0;
	info->plus = 0;
	info->minus = 0;
	info->space = 0;
	info->point = 0;
}
