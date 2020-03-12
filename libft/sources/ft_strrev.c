/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:39:43 by cmeowth           #+#    #+#             */
/*   Updated: 2020/02/28 19:39:47 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *res)
{
	size_t	i;
	size_t	len;
	char	tmp;

	len = ft_strlen(res);
	i = 0;
	while (i < len / 2)
	{
		tmp = res[i];
		res[i] = res[len - 1 - i];
		res[len - 1 - i] = tmp;
		i++;
	}
	return (res);
}
