/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfrjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 08:22:18 by cmeowth           #+#    #+#             */
/*   Updated: 2020/02/29 08:22:18 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strfrjoin(char *s1, char *s2)
{
	size_t	size1;
	size_t	size2;
	char	*new;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	new = ft_strnew(size1 + size2);
	ft_strcpy(new, s1);
	ft_strncat(new, s2, size2);
	free(s1);
	free(s2);
	return (new);
}
