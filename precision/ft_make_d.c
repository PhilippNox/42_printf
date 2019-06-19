/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/19 17:10:39 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

static void	putpreci(t_task *input, int len, int len_num, long long target)
{
	fill('0', len - len_num);
	if (input->precision != 0 || target != 0)
		ft_putstr(input->tmp);
}

static void	putsign(t_task *input, long long target)
{
	if (input->plus && target >= 0)
		ft_putchar('+');
	else if (input->space && target >= 0)
		ft_putchar(' ');
	else if (target < 0)
		ft_putchar('-');
}

static void	fillsign(t_task *input, long long target, char c, int len)
{
	if (input->plus || input->space || target < 0)
		fill(c, input->width - len - 1);
	else
		fill(c, input->width - len);
}


int	make_d(t_task *input, va_list *ap)
{
	char str[65];
	long long target;
	int len;
	int len_num;

	if (input->type == 'D')
		target = (long)va_arg(*ap, long);
	else if (input->length == 'i')
		target = (char)va_arg(*ap, int);
	else if (input->length == 'h')
		target = (short)va_arg(*ap, int);
	else if (input->length == 'l')
		target = (long)va_arg(*ap, long);
	else if (input->length == 'm')
		target = (long long)va_arg(*ap, long long);
	else if (input->length == 'z')
		target = (size_t)va_arg(*ap, long long);
	else
		target = va_arg(*ap, int);
	ft_baseitoasign(str, target, 10);
	input->tmp = str;

	len_num = length_utf8(str);
	len = (input->precision > len_num) ? input->precision : len_num;
	if (input->precision == 0 && target == 0)
		len = 0;
	if (input->minus)
	{
		putsign(input, target);
		putpreci(input, len, len_num, target);
		fillsign(input, target, ' ', len);
	}
	else
	{
		if (input->zero != ' ' && input->precision == -1)
		{
			putsign(input, target);
			fillsign(input, target, '0', len);
			putpreci(input, len, len_num, target);
		}
		else
		{
			fillsign(input, target, ' ', len);
			putsign(input, target);
			putpreci(input, len, len_num, target);
		}
	}
	if (input->plus || input->space || target < 0)
		len++;
	return (input->width > len) ? input->width : len;

	return (1);
}
