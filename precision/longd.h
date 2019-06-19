/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:19:18 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/19 17:26:57 by wgorold          ###   ########.fr       */
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
# define DEBUG_FLOAT_CREATION 0
# define DEBUG_EXP_TAB 0
# define DEBUG_FRC_ADD 0
# define DEBUG_ROUNDING 0
# define SHOW_LAST_TASK 0
# define UTF8COUNT 0

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>

typedef union u_longd {
	long double	ld;
	struct s_parts_ld {
		unsigned long	frac : 63;
		unsigned long	exp : 15;
		unsigned long	sign : 1;
	} t_parts_ld;
} t_longd;

typedef union u_d {
	double	d;
	struct s_parts_d {
		unsigned long	frac : 52;
		unsigned long	exp : 11;
		unsigned long	sign : 1;
	} t_parts_d;
} t_d;

typedef union u_f {
	float	f;
	struct s_parts_f {
		unsigned int	frac : 23;
		unsigned int	exp : 8;
		unsigned int	sign : 1;
	} t_parts_f;
} t_f;

typedef	struct		s_str_f
{
	char	ent[LEN_STR_ENT];
	char	frc[LEN_STR_FRC];
	int		idx_ent;
	int		idx_frc;
	int		exp_ent;
	int		exp_frc;
	char	sign;
} t_str_f;

typedef	struct	s_task
{
	char minus;
	char plus;
	char space;
	char hash;
	char zero;

	int width;
	int precision;
	char length;
	char type;

	char *tmp;
} t_task;

int		ft_printf(const char *format, ...);

void	init_task(t_task *input);
void	print_task(t_task *input);
int		set_task(t_task *input, char *start, va_list *ap);
int		make_task(t_task *input, va_list *ap);

int		make_c(t_task *input, va_list *ap);
int		make_bc(t_task *input, va_list *ap);
int		make_s(t_task *input, va_list *ap);
int		make_bs(t_task *input, va_list *ap);
int		make_p(t_task *input, va_list *ap);
int		make_d(t_task *input, va_list *ap);
int		make_o(t_task *input, va_list *ap);
int		make_u(t_task *input, va_list *ap);
int		make_x(t_task *input, va_list *ap);
int		make_f(t_task *input, va_list *ap);
int		make__(t_task *input);

int		ft_atoi(const char *str, int *add_total);
void	fill(char fill, int len);
int		isOneOf(char target, char * str);
int		length_utf8(char *str);
int		length_unicode(wchar_t *);
int		len_unicode_by_symbole(wchar_t *str, int top);

int		unicodestep(wchar_t tmp);
int		ft_utf8step(char const *s);
int		ft_pututf8(char const *s);
int		ft_putchar(int c);
int		ft_putchar_simple(char c);
void	ft_putnbr(int n);
int		ft_putstr(char const *s);
int		ft_putstrn(char const *s, int len);
void	print_arr(short *list, int size);
void	ft_putunbr(unsigned long n);
void	ft_baseitoa(char *out, unsigned long long target, unsigned char base, char big);
void	ft_baseitoasign(char *out, long long target, unsigned char base);
int		unicode2utf8(wchar_t tmp);
int		ft_putunicode(wchar_t *s, int len);

void	init_t_str_f(t_str_f *input);
void	init_t_str_f_ent(t_str_f *input);
void	init_t_str_f_frc(t_str_f *input);
void	print_t_str_f(t_str_f *input);
void	print_t_str_f_human(t_str_f *input);
void	print_t_str_f_full(t_str_f *input);
void	power2(t_str_f *input, int pwr);
void	power2form(t_str_f *input, int pwr, int curr);
void	sum_t_str_f_frc(t_str_f *result, t_str_f *a, t_str_f *b);
void	sum_t_str_f_ent(t_str_f *result, t_str_f *a, t_str_f *b);
void	set_sign(t_str_f *result, unsigned int sign);

void	show_float(t_longd input);
void	int_power_tab(short	power_tab[FRAC_FLOAT]);
void	set_power_tab(short	power_tab[FRAC_FLOAT], unsigned long vals, short exp, unsigned long mask);
void	debug_print(t_str_f	*add, int power, int curr);
void	debug_print_final(t_str_f	*final);
void	get_fractionnaire(t_str_f *frc, short	power_tab[FRAC_FLOAT]);
void	get_entiere(t_str_f *ent, short	power_tab[FRAC_FLOAT]);
void	get_precision_longd(t_str_f *output, long double input);
void	get_precision_d(t_str_f *output, double input);
void	get_precision_f(t_str_f *output, float input);

void	t_str_f_print_ent(t_str_f *input);
void	t_str_f_print_frc(t_str_f *input, int pos);
void	t_str_f_print_full_simple(t_str_f *input, int pos);
void	t_str_f_round(t_str_f *input, unsigned int pos);

#endif
