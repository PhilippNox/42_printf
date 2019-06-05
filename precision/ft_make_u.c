/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 18:47:14 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

static void	putpreci(t_task *input, unsigned int target, int len, int len_num)
{
	fill('0', len - len_num);
	ft_putstr(input->tmp);
}

int	make_u(t_task *input, va_list *ap)
{
	char str[21];
	int target;
	int len;
	int len_num;

	target = va_arg(*ap, int);
	ft_baseitoa(str, (unsigned int)target, 10);
	input->tmp = str;

	len_num = length_utf8(str);
	len = (input->precision > len_num) ? input->precision : len_num;

	if (input->minus)
	{
		putpreci(input, (unsigned int)target, len, len_num);
		fill(' ', input->width - len);
	}
	else
	{
		if (input->precision == -1)
			fill(input->zero, input->width - len);
		else
			fill(' ', input->width - len);
		putpreci(input, (unsigned int)target, len, len_num);
	}
	return (input->width > len) ? input->width : len;

	return (1);
}
