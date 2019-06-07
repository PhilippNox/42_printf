/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_mat_precision_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:45:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/07 16:42:47 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clear && gcc -Wall -Wextra -Werror ft_put.c t_str_f.c float.c && ./a.out

#include "longd.h"

void	t_str_f_round(t_str_f *input, unsigned int pos)
{
	print_t_str_f(input);
	if (input->exp_frc - 1 - pos < 0)
		return ;

	return;
}

void	t_str_f_print_ent(t_str_f *input, char *out, int *idxo)
{
	int		idx;

	if (input->sign == '-')
		out[(*idxo)++] = '-';
	idx = input->idx_ent;
	while (--idx > -1)
		out[(*idxo)++] = input->ent[idx] + 48;
}

void	t_str_f_print_full(t_str_f *input, char *out, int *idxo, int pos)
{
	int		idx;

	t_str_f_print_ent(input, out, idxo);
	out[(*idxo)++] = '.';

	idx = -1;
	while (++idx < pos)
	{
		if (input->exp_frc - 1 - idx > input->idx_frc)
			out[(*idxo)++] = '0';
		else if (input->exp_frc - 1 - idx >= 0)
			out[(*idxo)++] = input->frc[input->exp_frc - 1 - idx] + 48;
		else
			out[(*idxo)++] = '0';
	}

	/*
	idx = input->exp_frc + 1;
	while (--idx > input->idx_frc)
		out[(*idxo)++] = '0';
	while (--idx > -1)
		out[(*idxo)++] = input->frc[idx] + 48;
		*/
}
