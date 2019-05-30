/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/30 15:37:17 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

int	make_c(t_task *input, va_list *ap)
{
	char c;

	c = va_arg(*ap, int);
	if (input->width == 0)
	{
		ft_putchar(c);
		return (1);
	}
	if (input->minus)
	{
		ft_putchar(c);
		fill(' ', input->width - 1);
	}
	else
	{
		fill(input->zero, input->width - 1);
		ft_putchar(c);
	}
	return (input->width) ? input->width : 1;
}
