/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/08 01:00:11 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

static void	putsign(t_task *input, t_str_f *target)
{
	if (input->plus && target->sign == '+')
		ft_putchar('+');
	else if (input->space && target->sign == '+')
		ft_putchar(' ');
	else if (target->sign != '+')
		ft_putchar('-');
}

static void	putdouble(t_task *input, t_str_f *target)
{
	t_str_f_round(target, input->precision);
	t_str_f_print_ent(target);
	if (input->precision > 0 || input->hash)
		ft_putchar('.');
	t_str_f_print_frc(target, input->precision);
}

static void	withminus(t_task *input, t_str_f *target, int idxo)
{
	putsign(input, target);
	putdouble(input, target);
	fill(' ', input->width - idxo);
}

static void	withzeros(t_task *input, t_str_f *target, int idxo)
{
	putsign(input, target);
	fill(input->zero, input->width - idxo);
	putdouble(input, target);
}

static void	withnormal(t_task *input, t_str_f *target, int idxo)
{
	fill(' ', input->width - idxo);
	putsign(input, target);
	putdouble(input, target);
}

static int countlen(t_task *input, t_str_f *target)
{
	int idxo;

	idxo = 0;
	if (input->plus || input->space || target->sign == '-')
		idxo++;
	idxo += (target->idx_ent) ? target->idx_ent : 1;
	if (input->precision > 0 || input->hash)
		idxo += input->precision + 1;
	return (idxo);
}

int	make_f(t_task *input, va_list *ap)
{
	int idxo;
	t_str_f target;

	if (input->length == 'L')
		get_precision_longd(&target, va_arg(*ap, long double));
	else
		get_precision_d(&target, va_arg(*ap, double));

	idxo = countlen(input, &target);

	if (input->minus)
		withminus(input, &target, idxo);
	else if (input->zero != ' ')
		withzeros(input, &target, idxo);
	else
		withnormal(input, &target, idxo);

	return (input->width > idxo) ? input->width : idxo;
}
