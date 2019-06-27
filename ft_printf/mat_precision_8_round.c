/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_precision_8_round.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:45:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 16:54:02 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

void	up_rounding(t_str_f *input, unsigned int pos)
{
	t_str_f tmp;
	t_str_f add;

	init_t_str_f(&add);
	tmp = *input;
	if (pos > 0)
	{
		add.frc[0] = 1;
		add.idf = 1;
		add.exp_frc = pos;
		sum_t_str_f_frc(input, &tmp, &add);
		return ;
	}
	add.ent[0] = 1;
	add.idx_ent = 1;
	add.exp_ent = 0;
	sum_t_str_f_ent(input, &tmp, &add);
}

void	t_str_f_round(t_str_f *input, unsigned int pos)
{
	if (pos + 1 > (unsigned int)input->exp_frc)
		return ;
	if (pos + 1 < (unsigned int)input->exp_frc)
	{
		if (input->exp_frc - pos - 1 >= (unsigned int)input->idf)
			return ;
		if (input->frc[input->exp_frc - pos - 1] < 5)
			return ;
		return (up_rounding(input, pos));
	}
	if (input->frc[input->exp_frc - pos - 1] < 5)
		return ;
	if (input->frc[input->exp_frc - pos - 1] > 5)
		return (up_rounding(input, pos));
	if (input->frc[input->exp_frc - pos] % 2 == 0)
		return ;
	else
		return (up_rounding(input, pos));
}
