/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 15:49:45 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

static void	putpreci(t_task *input, int len, int len_num, unsigned long long target)
{
	fill('0', len - len_num);
	if (input->precision != 0 || target != 0)
		ft_putstr(input->tmp);
}

int	make_p(t_task *input, va_list *ap)
{
	char str[65];
	unsigned long target;
	int len;
	int pure_len;

	target = va_arg(*ap, unsigned long);
	ft_baseitoa(str, target, 16, 0);
	input->tmp = str;
	pure_len = length_utf8(str);
	len = (input->precision > pure_len) ? input->precision : pure_len;
	pure_len += 2;
	len += 2;

	if (input->minus)
	{
		ft_putstr("0x");
		putpreci(input, len, pure_len, target);
		fill(' ', input->width - len);
	}
	else
	{
		if (input->zero != ' ' && input->precision == -1)
		{
			ft_putstr("0x");
			fill('0', input->width - len);
		}
		else
		{
			fill(' ', input->width - len);
			ft_putstr("0x");
		}
		putpreci(input, len, pure_len, target);
	}

	return (input->width > len) ? input->width : len;
}
