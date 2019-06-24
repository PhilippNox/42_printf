/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:45:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/21 20:10:40 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clear && gcc -Wall -Wextra -Werror ft_put.c t_str_f.c float.c && ./a.out

#include "printf.h"

void	show_float(t_float2p input)
{
	ft_putstr("t_float2p:\n{");
	ft_putstr("\n\t sign: ");
	ft_putnbr(input.t_parts.sign);
	ft_putstr("\n\t exp : ");
	ft_putnbr(input.t_parts.exp);
	ft_putstr("\n\t frac: ");
	ft_putnbr(input.t_parts.frac);
	ft_putstr("\n}\n");
}

void	set_power_tab(short	power_tab[FRAC_FLOAT], unsigned int vals, short exp)
{
	int idx;
	int mask;

	mask = 0x00400000;
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

void	get_final(t_str_f *ent, t_str_f *frc, unsigned int sign)
{
	t_str_f tmp;

	tmp = *ent;
	sum_t_str_f(ent, &tmp, frc);
	set_sign(ent, sign);
	if (DEBUG_FLOAT_CREATION)
		debug_print_final(ent);
}
