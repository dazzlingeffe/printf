/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 07:57:23 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/29 07:57:23 by ykirigay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

void	arr_add(int **arr, int index, int nbr)
{
	int		*new;

	if (index <= *ARR_LEN && index >= 0)
	{
		new = (int *)malloc(sizeof(int) * (*ARR_LEN + 4));
		arr_copy(new, *arr);
		new[0]++;
		arr_set(new, index, nbr);
		while (++index <= *ARR_LEN)
			arr_set(new, index, (*arr)[index]);
		free(*arr);
		*arr = new;
	}
}
