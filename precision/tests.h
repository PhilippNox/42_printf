/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:19:18 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:10:48 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <string.h>
# include <stdio.h>

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

#endif
