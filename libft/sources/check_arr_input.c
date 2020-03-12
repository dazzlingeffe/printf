/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arr_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 07:59:08 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/29 07:59:08 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

static int	is_number(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int			check_arr_input(char *nbr)
{
	if (!is_number(nbr) || !ft_isinteger(nbr))
		return (1);
	return (0);
}
