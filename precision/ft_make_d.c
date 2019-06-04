/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/04 19:33:33 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

void	putpres(char *str, int len, int len_num)
{
	fill('0', len - len_num);
	ft_putstr(str);
}

void	putsign(t_task *input, int target)
{
	if (input->plus && target >= 0)
		ft_putchar('+');
	else if (input->space && target >= 0)
		ft_putchar(' ');
	else if (target < 0)
		ft_putchar('-');
}

void	fillsign(t_task *input, int target, char c, int len)
{
	if (input->plus || input->space || target < 0)
		fill(c, input->width - len - 1);
	else
		fill(c, input->width - len);
}


int	make_d(t_task *input, va_list *ap)
{
	char str[21];
	int target;
	int len;
	int len_num;

	(void)input;
	target = va_arg(*ap, int);
	ft_baseitoasign(str, target, 10);

	len_num = length_utf8(str);
	len = (input->precision > len_num) ? input->precision : len_num;

	if (input->width > len)
	{
		if (input->minus)
		{
			putsign(input, target);
			putpres(str, len, len_num);
			fillsign(input, target, ' ', len);
		}
		else
		{
			if (input->zero != ' ')
			{
				if (input->precision == -1)
				{
					putsign(input, target);
					fillsign(input, target, '0', len);
					putpres(str, len, len_num);
				}
				else
				{
					fillsign(input, target, ' ', len);
					putsign(input, target);
					putpres(str, len, len_num);
				}
			}
			else
			{
				fillsign(input, target, ' ', len);
				putsign(input, target);
				putpres(str, len, len_num);
			}
		}
	}
	else
	{
		putsign(input, target);
		putpres(str, len, len_num);
	}
	if (input->plus || input->space || target < 0)
		len++;
	return (input->width > len) ? input->width : len;


	return (1);
}
