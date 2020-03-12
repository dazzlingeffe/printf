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

static void				specs_handler(t_info *info)
{
	info->hash = 0;
	if (info->point == 0)
		info->precision = 6;
}

char					*worst_way(t_info *info, long double num)
{
	char				*bdot_a;
	char				*after_dot;

	if ((bdot_a = ft_before_dot(num)) == NULL)
		return (NULL);
	if (info->precision != 0 || info->hash == 1)
	{
		if ((bdot_a = ft_strfrjoin(bdot_a, ft_strdup("."))) == NULL)
			return (NULL);
	}
	if (info->precision != 0)
	{
		if ((after_dot = f_after_dot_prec(info, 0)) == NULL)
			return (NULL);
		bdot_a = ft_strfrjoin(bdot_a, after_dot);
	}
	return (bdot_a);
}

char					*no_way(t_info *info, unsigned long long bdot,
								char *after_dot)
{
	char				*bdot_a;

	if (info->precision == 0)
	{
		if (after_dot[0] == '5')
		{
			if ((bdot % 2) == 1 || ft_strlen(after_dot) > 1)
				bdot++;
		}
		else if (after_dot[0] > '5' && after_dot[0] <= '9')
			bdot++;
	}
	else if (info->round == 1)
		bdot++;
	if ((bdot_a = ft_ulltoa(bdot)) == NULL)
		return (NULL);
	if (info->precision != 0 || info->hash == 1)
		bdot_a = ft_strfrjoin(bdot_a, ft_strdup("."));
	if (info->precision != 0)
		bdot_a = ft_strfrjoin(bdot_a, after_dot);
	else
		free(after_dot);
	return (bdot_a);
}

char					*bad_way(t_info *info, long double num)
{
	char				*after_dot;
	unsigned long long	bdot;

	num *= (num < 0) ? -1 : 1;
	if (num > (long double)1000000L * 1000000L * 1000000L)
		return (worst_way(info, num));
	bdot = (long long int)num;
	if ((after_dot = f_after_dot_prec(info, num - bdot)) == NULL)
		return (NULL);
	return (no_way(info, bdot, after_dot));
}

void					type_f(const char **format, t_info *info)
{
	long double			number;
	t_data				data;

	info->type = **format;
	get_f(&number, info);
	specs_handler(info);
	if (!number)
		data.str = ft_strdup("0.");
	else if (number != number)
		data.str = ft_strdup("nan");
	else if (number == (number + number) && number > 0)
		data.str = ft_strdup("inf");
	else if (number == (number + number) && number < 0)
		data.str = ft_strdup("-inf");
	else
		data.str = bad_way(info, number);
	data.negative = number < 0;
	data.length = ft_strlen(data.str);
	apply_specs(info, &data);
}
