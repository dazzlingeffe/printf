/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:40:19 by cmeowth           #+#    #+#             */
/*   Updated: 2020/02/28 19:40:23 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ulltoa(unsigned long long int n)
{
	uint8_t len;
	char	*res;

	res = NULL;
	len = 0;
	if (n == 0)
		res = ft_strdup("0");
	else
	{
		len = ft_nblen(n);
		if ((res = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		res[len] = '\0';
		while (n != 0)
		{
			res[len - 1] = n % 10 + '0';
			n = n / 10;
			len--;
		}
	}
	return (res);
}
