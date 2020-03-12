/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 03:50:28 by cmeowth           #+#    #+#             */
/*   Updated: 2020/02/28 19:43:40 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		buffer_full(t_buffer *buffer)
{
	return (buffer->index == BUFF_SIZE);
}

void	print_buffer(t_buffer *buffer)
{
	write(buffer->fd, buffer->content, buffer->index);
	buffer->index = 0;
}

void	write_char(t_buffer *buffer, char c)
{
	if (buffer_full(buffer) == 1)
		print_buffer(buffer);
	buffer->content[buffer->index++] = c;
	buffer->length++;
}

void	write_str(t_buffer *buffer, char *str, int length)
{
	if (str)
		while (*str && length--)
			write_char(buffer, *str++);
}
