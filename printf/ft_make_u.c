/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/19 17:28:29 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putpreci(t_task *input, int len, int len_num, unsigned long long target)
{
	fill('0', len - len_num);
	if (input->precision != 0 || target != 0)
		ft_putstr(input->tmp);
}

int	make_u(t_task *input, va_list *ap)
{
	char str[65];
	unsigned long long target;
	int len;
	int len_num;

	if (input->type == 'U')
		target = (unsigned long)va_arg(*ap, long);
	else if (input->length == 'i')
		target = (unsigned char)va_arg(*ap, int);
	else if (input->length == 'h')
		target = (unsigned short)va_arg(*ap, int);
	else if (input->length == 'l')
		target = (unsigned long)va_arg(*ap, long);
	else if (input->length == 'm')
		target = (unsigned long long)va_arg(*ap, long long);
	else if (input->length == 'z')
		target = (size_t)va_arg(*ap, long long);
	else if (input->length == 'j')
		target = (intmax_t)va_arg(*ap, long long);
	else
		target = (unsigned int)va_arg(*ap, int);
	ft_baseitoa(str, target, 10, 0);
	input->tmp = str;

	len_num = length_utf8(str);
	len = (input->precision > len_num) ? input->precision : len_num;
	if (input->precision == 0 && target == 0)
		len = 0;
	if (input->minus)
	{
		putpreci(input, len, len_num, target);
		fill(' ', input->width - len);
	}
	else
	{
		if (input->precision == -1)
			fill(input->zero, input->width - len);
		else
			fill(' ', input->width - len);
		putpreci(input, len, len_num, target);
	}
	return (input->width > len) ? input->width : len;

	return (1);
}
