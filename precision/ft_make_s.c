/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 01:44:07 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

int	make_s(t_task *input, va_list *ap)
{
	char *str;
	int len;

	str = va_arg(*ap, char *);
	if (str)
		len = length_utf8(str);
	else
		len = 6;
	if (input->precision != -1 && input->precision < len)
		len = input->precision;

	if (input->width > len)
	{
		if (input->minus)
		{
			(str) ? ft_putstrn(str, len) : ft_putstrn("(null)", len);
			fill(' ', input->width - len);
		}
		else
		{
			fill(input->zero, input->width - len);
			(str) ? ft_putstrn(str, len) : ft_putstrn("(null)", len);
		}
	}
	else
		(str) ? ft_putstrn(str, len) : ft_putstrn("(null)", len);
	return (input->width > len) ? input->width : len;
}
