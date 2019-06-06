/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:04:15 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

static void	putpreci(t_task *input, unsigned long long target, int len, int len_num)
{
	fill('0', len - len_num);
	if (target != 0 && input->hash)
		ft_putchar('0');
	ft_putstr(input->tmp);
}

int	make_o(t_task *input, va_list *ap)
{
	char str[65];
	unsigned long long target;
	int len;
	int len_num;

	if (input->length == 'i')
		target = (unsigned char)va_arg(*ap, int);
	else if (input->length == 'h')
		target = (unsigned short)va_arg(*ap, int);
	else if (input->length == 'l')
		target = (unsigned long)va_arg(*ap, long);
	else if (input->length == 'm')
		target = (unsigned long long)va_arg(*ap, long long);
	else
		target = va_arg(*ap, int);
	ft_baseitoa(str, target, 8, 0);
	input->tmp = str;

	len_num = length_utf8(str);
	if (target != 0 && input->hash)
		len_num++;
	len = (input->precision > len_num) ? input->precision : len_num;

	if (input->minus)
	{
		putpreci(input, target, len, len_num);
		fill(' ', input->width - len);
	}
	else
	{
		if (input->precision == -1)
			fill(input->zero, input->width - len);
		else
			fill(' ', input->width - len);
		putpreci(input, target, len, len_num);
	}
	return (input->width > len) ? input->width : len;

	return (1);
}
