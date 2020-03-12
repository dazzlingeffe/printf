/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 07:58:07 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/29 07:58:07 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

int		arr_get(int *arr, int index)
{
	if (index < ARR_LEN && index >= 0)
		return (arr[index + 1]);
	else
		return (0);
}
