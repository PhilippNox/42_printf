/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make__.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/13 16:22:24 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	make__(t_task *input)
{
	char c;

	c = input->type;
	if (input->width < 2)
	{
		if (c == '\0')
			return (0);
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
