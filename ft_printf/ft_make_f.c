/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 20:23:20 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

static void	putsign(t_task *input, t_str_f *target)
{
	if (target->idx_ent && target->ent[0] == 'n')
		return ;
	if (input->plus && target->sign == '+')
		ft_putchar('+');
	else if (input->space && target->sign == '+')
		ft_putchar(' ');
	else if (target->sign != '+')
		ft_putchar('-');
}

static void	putdouble(t_task *input, t_str_f *target)
{
	if (target->idx_ent && target->ent[0] > 9)
	{
		if (target->ent[0] == 'i' && input->type == 'F')
			ft_putstr("INF");
		else if (target->ent[0] == 'i')
			ft_putstr("inf");
		else if (target->ent[0] == 'n' && input->type == 'F')
			ft_putstr("NAN");
		else if (target->ent[0] == 'n')
			ft_putstr("nan");
		return ;
	}
	t_str_f_round(target, input->precision);
	t_str_f_print_ent(target);
	if (input->precision > 0 || input->hash)
		ft_putchar('.');
	t_str_f_print_frc(target, input->precision);
}

static void	job_f(t_task *input, t_str_f *target, int idxo, char type)
{
	if (type == '-')
	{
		fill(' ', input->width - idxo);
		putsign(input, target);
		putdouble(input, target);
	}
	else if (type == '0')
	{
		putsign(input, target);
		fill(input->zero, input->width - idxo);
		putdouble(input, target);
	}
	else if (type == ' ')
	{
		fill(' ', input->width - idxo);
		putsign(input, target);
		putdouble(input, target);
	}
}

static int	countlen(t_task *input, t_str_f *target)
{
	int idxo;

	idxo = 0;
	if ((input->plus || input->space || target->sign == '-')
		&& !(target->idx_ent && target->ent[0] == 'n'))
		idxo++;
	idxo += (target->idx_ent) ? target->idx_ent : 1;
	if (target->idx_ent && target->ent[0] > 9)
	{
		idxo += 2;
		return (idxo);
	}
	if (input->precision > 0 || input->hash)
		idxo += input->precision + 1;
	return (idxo);
}

int			make_f(t_task *input, va_list *ap)
{
	int		idxo;
	t_str_f	target;

	if (input->length == 'L')
		get_precision_longd(&target, va_arg(*ap, long double));
	else
		get_precision_d(&target, va_arg(*ap, double));
	idxo = countlen(input, &target);
	if (input->minus)
		job_f(input, &target, idxo, '-');
	else if (input->zero != ' ' && !(target.idx_ent && target.ent[0] > 9))
		job_f(input, &target, idxo, '0');
	else
		job_f(input, &target, idxo, ' ');
	return (input->width > idxo) ? input->width : idxo;
}
