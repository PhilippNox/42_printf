/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 19:43:17 by wgorold          ###   ########.fr       */
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

void		make_d_job(t_task *input, int len, int len_num, long long target)
{
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
}
