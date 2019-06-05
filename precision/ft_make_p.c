/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 20:09:04 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

int	make_p(t_task *input, va_list *ap)
{
	char str[65];
	unsigned long target;
	int len;

	(void)input;
	target = va_arg(*ap, unsigned long);
	ft_baseitoa(str, target, 16, 0);
	len = length_utf8(str) + 2;

	if (input->width > len)
	{
		if (input->minus)
		{
			ft_putstr("0x");
			ft_putstr(str);
			fill(' ', input->width - len);
		}
		else
		{
			fill(' ', input->width - len);
			ft_putstr("0x");
			ft_putstr(str);
		}
	}
	else
	{
		ft_putstr("0x");
		ft_putstr(str);
	}
	return (input->width > len) ? input->width : len;


	return (1);
}
