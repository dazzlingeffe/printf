/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 03:52:27 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/28 19:59:52 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_str_spam(const char *s, int repetitions)
{
	int			i;
	size_t		len;
	char		*res;

	len = ft_strlen(s);
	res = (char*)malloc(sizeof(char) * (len * repetitions + 1));
	if (res != NULL)
	{
		i = 0;
		while (i < (int)(len * repetitions))
		{
			res[i] = s[i % len];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}

static char		*after_prec_2(t_info *info, char *a_dot, int b)
{
	while (a_dot[b] > '9')
	{
		a_dot[b] = '0';
		if (b > 0)
			a_dot[--b]++;
		else
		{
			info->round = 1;
			break ;
		}
	}
	b = 0;
	while (++b < info->precision)
		if (a_dot[b] > '9')
			a_dot[b] = '0';
	b = info->precision;
	if (b == 0)
		b = 3;
	a_dot[b] = '\0';
	return (a_dot);
}

char			*f_after_dot_prec(t_info *info, long double num)
{
	int			len;
	int			b;
	int			i;
	char		*a_dot;

	a_dot = f_after_dot(num);
	len = (int)ft_strlen(a_dot);
	if (info->precision >= len)
	{
		a_dot = ft_strfrjoin(a_dot,
				ft_str_spam("0", info->precision - len + 3));
	}
	b = info->precision;
	if (a_dot[b] == '4' && len > info->precision && (i = 1) == 1)
	{
		while (b + i < len && a_dot[b + i] == '9')
			i++;
		if (a_dot[b + i] >= '5' && a_dot[b + i] <= '9' && i > 8)
			a_dot[b - 1]++;
	}
	if (a_dot[b] >= '5' && len > info->precision && b > 0)
		a_dot[b - 1]++;
	b = b - (b >= 1);
	info->round = 0;
	return (after_prec_2(info, a_dot, b));
}

char			*f_after_dot(long double num)
{
	int		i;
	char	b;
	char	a[5000];

	ft_bzero(a, 5000);
	i = 0;
	if (num == 0)
		return (ft_strdup(""));
	while (num > 0 && i < 5000)
	{
		num = num * 10;
		b = (char)num;
		num -= b;
		a[i] = b + '0';
		i++;
	}
	return (ft_strdup(a));
}
