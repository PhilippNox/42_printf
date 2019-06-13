/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:19:18 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/13 15:05:42 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <string.h>
# include <float.h>
# include <stdio.h>

void	test_c(int (*fun)(const char *format, ...));
void	test_cp(int (*fun)(const char *format, ...));
void	test_c_utf8(int (*fun)(const char *format, ...));
void	test_s_small(int (*fun)(const char *format, ...));
void	test_s(int (*fun)(const char *format, ...));
void	test_p(int (*fun)(const char *format, ...));
void	test_d_small(int (*fun)(const char *format, ...));
void	test_d(int (*fun)(const char *format, ...));
void	test_i(int (*fun)(const char *format, ...));
void	test_o(int (*fun)(const char *format, ...));
void	test_u(int (*fun)(const char *format, ...));
void	test_x(int (*fun)(const char *format, ...));
void	test_X(int (*fun)(const char *format, ...));
void	test_hhd(int (*fun)(const char *format, ...));
void	test_hd(int (*fun)(const char *format, ...));
void	test_ld(int (*fun)(const char *format, ...));
void	test_lld(int (*fun)(const char *format, ...));
void	test_hhi(int (*fun)(const char *format, ...));
void	test_hi(int (*fun)(const char *format, ...));
void	test_li(int (*fun)(const char *format, ...));
void	test_lli(int (*fun)(const char *format, ...));
void	test_hho(int (*fun)(const char *format, ...));
void	test_ho(int (*fun)(const char *format, ...));
void	test_lo(int (*fun)(const char *format, ...));
void	test_llo(int (*fun)(const char *format, ...));
void	test_hhu(int (*fun)(const char *format, ...));
void	test_hu(int (*fun)(const char *format, ...));
void	test_lu(int (*fun)(const char *format, ...));
void	test_llu(int (*fun)(const char *format, ...));
void	test_hhx(int (*fun)(const char *format, ...));
void	test_hx(int (*fun)(const char *format, ...));
void	test_lx(int (*fun)(const char *format, ...));
void	test_llx(int (*fun)(const char *format, ...));
void	test_hhxx(int (*fun)(const char *format, ...));
void	test_hxx(int (*fun)(const char *format, ...));
void	test_lxx(int (*fun)(const char *format, ...));
void	test_llxx(int (*fun)(const char *format, ...));
void	test_f(int (*fun)(const char *format, ...));
void	test_fs(int (*fun)(const char *format, ...));
void	test_fr(int (*fun)(const char *format, ...));
void	test_Lf(int (*fun)(const char *format, ...));
void	test_ff(int (*fun)(const char *format, ...));
void	test_Lff(int (*fun)(const char *format, ...));
void	test_star(int (*fun)(const char *format, ...));
void	test__(int (*fun)(const char *format, ...));


#endif
