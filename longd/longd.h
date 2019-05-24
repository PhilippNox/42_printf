/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:19:18 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/24 19:59:51 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://en.wikipedia.org/wiki/Extended_precision

#ifndef LONGD_H
# define LONGD_H
# define LEN_STR_FRC 16500
# define LEN_STR_ENT 5000
# define STOP_SHORT 30000
# define FRAC_FLOAT 63 + 1
# define DEBUG_POWER 0
# define DEBUG_POWER_IDX 0
# define DEBUG_FLOAT_CREATION 0
# define DEBUG_EXP_TAB 1

# include <stdio.h>
# include <string.h>

typedef union u_longd {
	long double	ld;
	struct s_parts {
		unsigned long	frac : 63;
		unsigned long	exp : 15;
		unsigned long	sign : 1;
	} t_parts;
} t_longd;

typedef	struct		s_str_f
{
	char	ent[LEN_STR_ENT];
	char	frc[LEN_STR_FRC];
	int		idx_ent;
	int		idx_frc;
	char	sign;
} t_str_f;

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char const *s);
void	print_arr(short *list, int size);
void	ft_putunbr(unsigned long n);

void	init_t_str_f(t_str_f *input);
void	print_t_str_f(t_str_f *input);
void	print_t_str_f_human(t_str_f *input);
void	power2(t_str_f *input, int pwr);
void	power2form(t_str_f *input, int pwr, int curr);
void	sum_t_str_f(t_str_f *result, t_str_f *a, t_str_f *b);
void	set_sign(t_str_f *result, unsigned int sign);

void	show_float(t_longd input);
void	set_power_tab(short	power_tab[FRAC_FLOAT], unsigned long vals, short exp);
void	debug_print(t_str_f	*add, int power, int curr);
void	debug_print_final(t_str_f	*final);
void	get_fractionnaire(t_str_f *frc, short	power_tab[FRAC_FLOAT]);
void	get_entiere(t_str_f *ent, short	power_tab[FRAC_FLOAT]);
void	get_final(t_str_f *ent, t_str_f *frc, unsigned int sign);

#endif
