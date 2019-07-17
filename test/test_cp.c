/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:58:57 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: %] _cp_ %c

#include "tests.h"

void test_cp(int (*fun)(const char *format, ...))
{
	int idx;
	char *str[] = {
		"test_cp_0 ok [%#0 -+10.4%]",
		"test_cp_1 ok [%0 -+10.4%]",
		"test_cp_2 ok [% -+10.4%]",
		"test_cp_3 ok [%-+10.4%]",
		"test_cp_4 ok [%+10.4%]",
		"test_cp_5 ok [%10.4%]",
		"test_cp_6 ok [%.4%]",
		"test_cp_7 ok [%10%]",
		"test_cp_8 ok [%+.4%]",
		"test_cp_9 ok [%+%]",
		"test_cp_10 ok [%+10%]",
		"test_cp_11 ok [%-10.4%]",
		"test_cp_12 ok [%-.4%]",
		"test_cp_13 ok [%-%]",
		"test_cp_14 ok [%-10%]",
		"test_cp_15 ok [%-+.4%]",
		"test_cp_16 ok [%-+%]",
		"test_cp_17 ok [%-+10%]",
		"test_cp_18 ok [% +10.4%]",
		"test_cp_19 ok [% 10.4%]",
		"test_cp_20 ok [% .4%]",
		"test_cp_21 ok [% %]",
		"test_cp_22 ok [% 10%]",
		"test_cp_23 ok [% +.4%]",
		"test_cp_24 ok [% +%]",
		"test_cp_25 ok [% +10%]",
		"test_cp_26 ok [% -10.4%]",
		"test_cp_27 ok [% -.4%]",
		"test_cp_28 ok [% -%]",
		"test_cp_29 ok [% -10%]",
		"test_cp_30 ok [% -+.4%]",
		"test_cp_31 ok [% -+%]",
		"test_cp_32 ok [% -+10%]",
		"test_cp_33 ok [%0-+10.4%]",
		"test_cp_34 ok [%0+10.4%]",
		"test_cp_35 ok [%010.4%]",
		"test_cp_36 ok [%0.4%]",
		"test_cp_37 ok [%0%]",
		"test_cp_38 ok [%010%]",
		"test_cp_39 ok [%0+.4%]",
		"test_cp_40 ok [%0+%]",
		"test_cp_41 ok [%0+10%]",
		"test_cp_42 ok [%0-10.4%]",
		"test_cp_43 ok [%0-.4%]",
		"test_cp_44 ok [%0-%]",
		"test_cp_45 ok [%0-10%]",
		"test_cp_46 ok [%0-+.4%]",
		"test_cp_47 ok [%0-+%]",
		"test_cp_48 ok [%0-+10%]",
		"test_cp_49 ok [%0 +10.4%]",
		"test_cp_50 ok [%0 10.4%]",
		"test_cp_51 ok [%0 .4%]",
		"test_cp_52 ok [%0 %]",
		"test_cp_53 ok [%0 10%]",
		"test_cp_54 ok [%0 +.4%]",
		"test_cp_55 ok [%0 +%]",
		"test_cp_56 ok [%0 +10%]",
		"test_cp_57 ok [%0 -10.4%]",
		"test_cp_58 ok [%0 -.4%]",
		"test_cp_59 ok [%0 -%]",
		"test_cp_60 ok [%0 -10%]",
		"test_cp_61 ok [%0 -+.4%]",
		"test_cp_62 ok [%0 -+%]",
		"test_cp_63 ok [%0 -+10%]",
		"test_cp_64 ok [%# -+10.4%]",
		"test_cp_65 ok [%#-+10.4%]",
		"test_cp_66 ok [%#+10.4%]",
		"test_cp_67 ok [%#10.4%]",
		"test_cp_68 ok [%#.4%]",
		"test_cp_69 ok [%#%]",
		"test_cp_70 ok [%#10%]",
		"test_cp_71 ok [%#+.4%]",
		"test_cp_72 ok [%#+%]",
		"test_cp_73 ok [%#+10%]",
		"test_cp_74 ok [%#-10.4%]",
		"test_cp_75 ok [%#-.4%]",
		"test_cp_76 ok [%#-%]",
		"test_cp_77 ok [%#-10%]",
		"test_cp_78 ok [%#-+.4%]",
		"test_cp_79 ok [%#-+%]",
		"test_cp_80 ok [%#-+10%]",
		"test_cp_81 ok [%# +10.4%]",
		"test_cp_82 ok [%# 10.4%]",
		"test_cp_83 ok [%# .4%]",
		"test_cp_84 ok [%# %]",
		"test_cp_85 ok [%# 10%]",
		"test_cp_86 ok [%# +.4%]",
		"test_cp_87 ok [%# +%]",
		"test_cp_88 ok [%# +10%]",
		"test_cp_89 ok [%# -10.4%]",
		"test_cp_90 ok [%# -.4%]",
		"test_cp_91 ok [%# -%]",
		"test_cp_92 ok [%# -10%]",
		"test_cp_93 ok [%# -+.4%]",
		"test_cp_94 ok [%# -+%]",
		"test_cp_95 ok [%# -+10%]",
		"test_cp_96 ok [%#0-+10.4%]",
		"test_cp_97 ok [%#0+10.4%]",
		"test_cp_98 ok [%#010.4%]",
		"test_cp_99 ok [%#0.4%]",
		"test_cp_100 ok [%#0%]",
		"test_cp_101 ok [%#010%]",
		"test_cp_102 ok [%#0+.4%]",
		"test_cp_103 ok [%#0+%]",
		"test_cp_104 ok [%#0+10%]",
		"test_cp_105 ok [%#0-10.4%]",
		"test_cp_106 ok [%#0-.4%]",
		"test_cp_107 ok [%#0-%]",
		"test_cp_108 ok [%#0-10%]",
		"test_cp_109 ok [%#0-+.4%]",
		"test_cp_110 ok [%#0-+%]",
		"test_cp_111 ok [%#0-+10%]",
		"test_cp_112 ok [%#0 +10.4%]",
		"test_cp_113 ok [%#0 10.4%]",
		"test_cp_114 ok [%#0 .4%]",
		"test_cp_115 ok [%#0 %]",
		"test_cp_116 ok [%#0 10%]",
		"test_cp_117 ok [%#0 +.4%]",
		"test_cp_118 ok [%#0 +%]",
		"test_cp_119 ok [%#0 +10%]",
		"test_cp_120 ok [%#0 -10.4%]",
		"test_cp_121 ok [%#0 -.4%]",
		"test_cp_122 ok [%#0 -%]",
		"test_cp_123 ok [%#0 -10%]",
		"test_cp_124 ok [%#0 -+.4%]",
		"test_cp_125 ok [%#0 -+%]",
		"test_cp_126 ok [%#0 -+10%]",
		NULL
	};



	idx = -1;
	while (str[++idx])
	{
		fun(str[idx]);
		fun("\n");
	}
}
