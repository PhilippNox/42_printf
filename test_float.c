/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:09:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/21 20:14:58 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// clear && gcc -Wall -Wextra -Werror ft_put.c t_str_f.c float.c test_float.c && ./a.out

int	main()
{
	t_float2p	input;
	short	power_tab[FRAC_FLOAT];
	t_str_f ent;
	t_str_f frc;

	input.f = -1.5;
	input.f = -1.5078125;
	input.f = 24.1250019073486328125;
	input.f = 3.9497802E24;
	input.f = 1.20609785E20;
	input.f = 3;
	input.f = -3.0156252384185791015625;
	input.f = -12359.015625;
	input.f = 12359.015625;
	input.f = -6.550091E37;
	input.f = -3.1568031E38;
	//input.f = -2.1810147E-38;

	show_float(input);

	set_power_tab(power_tab, input.t_parts.frac, (short)input.t_parts.exp - 127);

	get_fractionnaire(&frc, power_tab);
	get_entiere(&ent, power_tab);
	get_final(&ent, &frc, input.t_parts.sign);
	ft_putstr("\n\nfinal= ");
	print_t_str_f_human(&ent);
}
