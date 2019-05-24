/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_mat_precision_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:45:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/25 00:55:36 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clear && gcc -Wall -Wextra -Werror ft_put.c t_str_f.c float.c && ./a.out

#include "longd.h"

void	show_float(t_longd input)
{
	ft_putstr("t_longd:\n{");
	ft_putstr("\n\t sign: ");
	ft_putnbr(input.t_parts_ld.sign);
	ft_putstr("\n\t exp : ");
	ft_putnbr(input.t_parts_ld.exp);
	ft_putstr("\n\t frac: ");
	ft_putunbr(input.t_parts_ld.frac);
	ft_putstr("\n}\n");
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

void	debug_print(t_str_f	*add, int power, int curr)
{
	ft_putstr("power_tab[idx]: ");
	ft_putnbr(power);
	ft_putstr("\t curr: ");
	ft_putnbr(curr);
	ft_putstr("\t val: ");
	print_t_str_f_human(add);
	ft_putstr("\n");
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

		power2form(&add, power_tab[idx], curr);
		tmp = *frc;
		sum_t_str_f(frc, &tmp, &add);
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
		sum_t_str_f(ent, &tmp, &add);
		if (DEBUG_FLOAT_CREATION)
			debug_print(&add, power_tab[idx], curr);
		curr = power_tab[idx];
	}
	if (DEBUG_FLOAT_CREATION)
		debug_print_final(ent);
}

void	get_final(t_str_f *ent, t_str_f *frc)
{
	t_str_f tmp;

	tmp = *ent;
	sum_t_str_f(ent, &tmp, frc);
	if (DEBUG_FLOAT_CREATION)
		debug_print_final(ent);
}

void get_precision_longd(t_str_f *output, long double input)
{
	t_longd tmp;
	short	power_tab[FRAC_FLOAT];
	t_str_f frc;

	init_t_str_f(output);
	init_t_str_f(&frc);
	tmp.ld = input;

	//show_float(tmp);
	set_power_tab(power_tab, tmp.t_parts_ld.frac, (short)tmp.t_parts_ld.exp - 16383, 0x4000000000000000);
	get_fractionnaire(&frc, power_tab);
	get_entiere(output, power_tab);
	set_sign(output, tmp.t_parts_ld.sign);
	get_final(output, &frc);
}

void get_precision_d(t_str_f *output, double input)
{
	t_d tmp;
	short	power_tab[FRAC_FLOAT];
	t_str_f frc;

	init_t_str_f(output);
	init_t_str_f(&frc);
	tmp.d = input;

	//show_float(tmp);
	set_power_tab(power_tab, tmp.t_parts_d.frac, (short)tmp.t_parts_d.exp - 1023, 0x0008000000000000);
	get_fractionnaire(&frc, power_tab);
	get_entiere(output, power_tab);
	set_sign(output, tmp.t_parts_d.sign);
	get_final(output, &frc);
}

void get_precision_f(t_str_f *output, float input)
{
	t_f tmp;
	short	power_tab[FRAC_FLOAT];
	t_str_f frc;

	init_t_str_f(output);
	init_t_str_f(&frc);
	tmp.f = input;

	//show_float(tmp);
	set_power_tab(power_tab, tmp.t_parts_f.frac, (short)tmp.t_parts_f.exp - 127, 0x0000000000400000);
	get_fractionnaire(&frc, power_tab);
	get_entiere(output, power_tab);
	set_sign(output, tmp.t_parts_f.sign);
	get_final(output, &frc);
}