/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_mat_precision_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:45:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/24 18:20:57 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

void	int_power_tab(short	power_tab[FRAC_FLOAT])
{
	int idx;

	idx = 0;
	while (++idx < FRAC_FLOAT)
		power_tab[idx] = STOP_SHORT;
}

void	set_power_tab(short	power_tab[FRAC_FLOAT], unsigned long vals, short exp, unsigned long mask)
{
	int idx;

	idx = 0;
	power_tab[idx] = exp;
	while (++idx < FRAC_FLOAT)
		power_tab[idx] = (vals & (mask >> (idx - 1))) ? (exp - idx) : STOP_SHORT;
	if (DEBUG_EXP_TAB)
	{
		print_arr(power_tab, FRAC_FLOAT);
		ft_putstr("\n");
	}
}

void	debug_print_final(t_str_f	*final)
{
	ft_putstr("\t\t\t\t       final: ");
	print_t_str_f_human(final);
	ft_putstr("\n");

}

void	get_fractionnaire(t_str_f *frc, short	power_tab[FRAC_FLOAT])
{
	int idx;
	int curr;
	t_str_f tmp;
	t_str_f add;

	idx = -1;
	curr = 0;
	while (++idx < FRAC_FLOAT)
	{
		if (power_tab[idx] == STOP_SHORT || power_tab[idx] >= 0)
			continue;
		if (curr == 0)
		{
			power2form(&add, power_tab[idx], curr);
			*frc = add;
			curr = power_tab[idx];
			continue;
		}
		power2form(&add, power_tab[idx], curr);
		tmp = *frc;
		sum_t_str_f_frc(frc, &tmp, &add);
		if (DEBUG_FLOAT_CREATION)
			debug_print(&add, power_tab[idx], curr);
		curr = power_tab[idx];
	}
	if (DEBUG_FLOAT_CREATION)
		debug_print_final(frc);
}

void	get_entiere(t_str_f *ent, short	power_tab[FRAC_FLOAT])
{
	int idx;
	int curr;
	t_str_f tmp;
	t_str_f add;

	idx = FRAC_FLOAT;
	curr = 0;
	while (--idx > -1)
	{
		if (power_tab[idx] == STOP_SHORT || power_tab[idx] < 0)
			continue;
		power2form(&add, power_tab[idx], curr);
		tmp = *ent;
		sum_t_str_f_ent(ent, &tmp, &add);
		if (DEBUG_FLOAT_CREATION)
			debug_print(&add, power_tab[idx], curr);
		curr = power_tab[idx];
	}
	if (DEBUG_FLOAT_CREATION)
		debug_print_final(ent);
}

void	mat_for_precision(t_str_f *output, short	power_tab[FRAC_FLOAT], unsigned int sign)
{
	init_t_str_f(output);
	get_fractionnaire(output, power_tab);
	get_entiere(output, power_tab);
	set_sign(output, sign);
}

void get_precision_longd(t_str_f *output, long double input)
{
	t_longd tmp;
	short	power_tab[FRAC_FLOAT];

	tmp.ld = input;
	// TODO denormalized ((short)tmp.t_parts_ld.exp == 0 && (short)tmp.t_parts_ld.sign == 0)
	if ((short)tmp.t_parts_ld.exp == 0 || (short)tmp.t_parts_ld.exp == 32767)
	{
		init_t_str_f(output);
		if ((short)tmp.t_parts_ld.exp == 0)
			output->ent[output->idx_ent++] = 0;
		else if ((short)tmp.t_parts_ld.exp == 32767 && tmp.t_parts_ld.frac == 0)
			output->ent[output->idx_ent++] = 105; //i
		else if ((short)tmp.t_parts_ld.exp == 32767)
			output->ent[output->idx_ent++] = 110; //n
		if (tmp.t_parts_ld.sign)
			output->sign = '-';
		return ;
	}

	set_power_tab(power_tab, tmp.t_parts_ld.frac, (short)tmp.t_parts_ld.exp - 16383, 0x4000000000000000);
	mat_for_precision(output, power_tab, tmp.t_parts_ld.sign);
}

void get_precision_d(t_str_f *output, double input)
{
	t_d tmp;
	short	power_tab[FRAC_FLOAT];

	tmp.d = input;
	// TODO denormalized ((short)tmp.t_parts_d.exp == 0 && (short)tmp.t_parts_d.sign == 0)
	if ((short)tmp.t_parts_d.exp == 0 || (short)tmp.t_parts_d.exp == 2047)
	{
		init_t_str_f(output);
		if ((short)tmp.t_parts_d.exp == 0)
			output->ent[output->idx_ent++] = 0;
		else if ((short)tmp.t_parts_d.exp == 2047 && tmp.t_parts_d.frac == 0)
			output->ent[output->idx_ent++] = 105; //i
		else if ((short)tmp.t_parts_d.exp == 2047)
			output->ent[output->idx_ent++] = 110; //n
		if (tmp.t_parts_d.sign)
			output->sign = '-';
		return ;
	}

	set_power_tab(power_tab, tmp.t_parts_d.frac, (short)tmp.t_parts_d.exp - 1023, 0x0008000000000000);
	mat_for_precision(output, power_tab, tmp.t_parts_d.sign);
}

void get_precision_f(t_str_f *output, float input)
{
	t_f tmp;
	short	power_tab[FRAC_FLOAT];

	tmp.f = input;
	set_power_tab(power_tab, tmp.t_parts_f.frac, (short)tmp.t_parts_f.exp - 127, 0x0000000000400000);
	mat_for_precision(output, power_tab, tmp.t_parts_f.sign);
}
