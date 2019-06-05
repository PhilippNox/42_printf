/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 19:21:33 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

static void	putpreci(t_task *input, int len, int len_num)
{
	fill('0', len - len_num);
	ft_putstr(input->tmp);
}

static void	puthash(t_task *input, unsigned int target)
{
	if (target != 0 && input->hash)
		ft_putstr("0X");
}

int	make_X(t_task *input, va_list *ap)
{
	char str[21];
	int target;
	int len;
	int len_num;

	target = va_arg(*ap, int);
	ft_baseitoa(str, (unsigned int)target, 16, 1);
	input->tmp = str;

	len_num = length_utf8(str);
	len = (input->precision > len_num) ? input->precision : len_num;
	if (target != 0 && input->hash)
	{
		len += 2;
		len_num += 2;
	}
	if (input->minus)
	{
		puthash(input, (unsigned int)target);
		putpreci(input, len, len_num);
		fill(' ', input->width - len);
	}
	else
	{
		if (input->zero != ' ' && input->precision == -1)
		{
			puthash(input, (unsigned int)target);
			fill('0', input->width - len);
		}
		else
		{
			fill(' ', input->width - len);
			puthash(input, (unsigned int)target);
		}
		putpreci(input, len, len_num);
	}
	return (input->width > len) ? input->width : len;
}
