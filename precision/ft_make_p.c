/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/03 14:48:44 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

int	make_p(t_task *input, va_list *ap)
{
	char str[21];
	unsigned long target;

	(void)input;
	target = va_arg(*ap, unsigned long);
	ft_baseitoa(str, target, 16);
	ft_putstr("0x");
	ft_putstr(str);

	return (1);
}
