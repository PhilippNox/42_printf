/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/04 18:16:18 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

void	putplus(int *len, char target)
{
	ft_putchar(target);
	*len += 1;
}

void	nozero(t_task *input, int target, int *len, char str[21])
{
	if (target >= 0 && (input->plus || input->space))
		fill(' ', input->width - *len - 1);
	else
		fill(' ', input->width - *len);
	if (input->plus && target >= 0)
		putplus(len, '+');
	else if(input->space && target >= 0)
		putplus(len, ' ');
	ft_putstr(str);
}

void zeronominus(t_task *input, int target, int *len, char str[21])
{
	if (target < 0)
		ft_putchar('-');
	else if (input->plus && target >= 0)
		putplus(len, '+');
	else if(input->space && target >= 0)
		putplus(len, ' ');
	fill('0', input->width - *len);
	if (target < 0)
		ft_putstr(str + 1);
	else
		ft_putstr(str);
}

int	make_d(t_task *input, va_list *ap)
{
	char str[21];
	int target;
	int len;

	(void)input;
	target = va_arg(*ap, int);
	ft_baseitoasign(str, target, 10);
	len = length_utf8(str);

	if (input->width > len)
	{
		if (input->minus)
		{
			if (input->plus && target >= 0)
				putplus(&len, '+');
			else if(input->space && target >= 0)
				putplus(&len, ' ');
			ft_putstr(str);
			fill(' ', input->width - len);
		}
		else
		{
			if (input->zero != ' ')
				zeronominus(input, target, &len, str);
			else
				nozero(input, target, &len, str);
		}
	}
	else
	{
		if (input->plus && target >= 0)
			putplus(&len, '+');
		else if(input->space && target >= 0)
			putplus(&len, ' ');
		ft_putstr(str);
	}
	return (input->width > len) ? input->width : len;


	return (1);
}
