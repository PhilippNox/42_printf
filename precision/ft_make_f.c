/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/07 16:41:01 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

int	make_f(t_task *input, va_list *ap)
{
	t_str_f target;
	int idxo;
	char out[LEN_STR_FRC];
	int prc;

	idxo = 0;
	prc = input->precision;
	if (input->length == 'L')
		get_precision_longd(&target, va_arg(*ap, long double));
	else
		get_precision_d(&target, va_arg(*ap, double));

	t_str_f_round(&target, (unsigned int)prc);
	t_str_f_print_full(&target, out, &idxo, prc);
	//while (prc-- > target.idx_frc)
	//	out[idxo++] = '0';
	write(1, out, idxo);


	return (idxo);
}
