/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:19:18 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/23 17:19:31 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define LEN_STR_NUM 400
# define STOP_SHORT -32768
# define FRAC_FLOAT 23 + 1
# define DEBUG_POWER 0
# define DEBUG_FLOAT_CREATION 1
# define DEBUG_EXP_TAB 1

# include <stdio.h>
# include <string.h>

union Data {
	int i;
	char str[4];
	float f;
};

typedef union u_float2p {
	float	f;
	struct s_parts {
		unsigned int	frac : 23;
		unsigned int	exp : 8;
		unsigned int	sign : 1;
	} t_parts;
} t_float2p;

typedef	struct		s_str_f
{
	char	ent[LEN_STR_NUM];
	char	frc[LEN_STR_NUM];
	int		idx_ent;
	int		idx_frc;
	char	sign;
} t_str_f;

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char const *s);
void	print_arr(short *list, int size);

void	init_t_str_f(t_str_f *input);
void	print_t_str_f(t_str_f *input);
void	print_t_str_f_human(t_str_f *input);
void	power2(t_str_f *input, int pwr);
void	power2form(t_str_f *input, int pwr, int curr);
void	sum_t_str_f(t_str_f *result, t_str_f *a, t_str_f *b);
void	set_sign(t_str_f *result, unsigned int sign);

void	show_float(t_float2p input);
void	set_power_tab(short	power_tab[FRAC_FLOAT], unsigned int vals, short exp);
void	debug_print(t_str_f	*add, int power, int curr);
void	debug_print_final(t_str_f	*final);
void	get_fractionnaire(t_str_f *frc, short	power_tab[FRAC_FLOAT]);
void	get_entiere(t_str_f *ent, short	power_tab[FRAC_FLOAT]);
void	get_final(t_str_f *ent, t_str_f *frc, unsigned int sign);

#endif
