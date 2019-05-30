/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/30 16:43:17 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

int	make_s(t_task *input, va_list *ap)
{
	char *str;
	int len;

	str = va_arg(*ap, char *);
	len = length_utf8(str);
	if (input->precision != -1 && input->precision < len)
		len = input->precision;

	if (input->width > len)
	{
		if (input->minus)
		{
			ft_putstrn(str, len);
			fill(' ', input->width - len);
		}
	}
	else
	{
		fill(input->zero, input->width - len);
		ft_putstrn(str, len);
	}
	return (input->width > len) ? input->width : len;
}
