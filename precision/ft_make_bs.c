/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_bs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 21:05:11 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

int	make_bs(t_task *input, va_list *ap)
{
	wchar_t *str;
	int len;

	str = va_arg(*ap, wchar_t *);
	if (!str)
		str = L"(null)";
	len = length_unicode(str);
	if (input->precision != -1 && input->precision < len)
		len = input->precision;

	if (input->width > len)
	{
		if (input->minus)
		{
			ft_putunicode(str, len);
			fill(' ', input->width - len);
		}
		else
		{
			fill(input->zero, input->width - len);
			ft_putunicode(str, len);
		}
	}
	else
		ft_putunicode(str, len);
	return (input->width > len) ? input->width : len;
}
