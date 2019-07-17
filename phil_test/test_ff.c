/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/09 23:09:34 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: F] _F_ %f

#include "tests.h"

void test_ff(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_F_0 ok [%#0 -+10.4F]",
		"test_F_1 ok [%0 -+10.4F]",
		"test_F_2 ok [% -+10.4F]",
		"test_F_3 ok [%-+10.4F]",
		"test_F_4 ok [%+10.4F]",
		"test_F_5 ok [%10.4F]",
		"test_F_6 ok [%.4F]",
		"test_F_7 ok [%10F]",
		"test_F_8 ok [%+.4F]",
		"test_F_9 ok [%+F]",
		"test_F_10 ok [%+10F]",
		"test_F_11 ok [%-10.4F]",
		"test_F_12 ok [%-.4F]",
		"test_F_13 ok [%-F]",
		"test_F_14 ok [%-10F]",
		"test_F_15 ok [%-+.4F]",
		"test_F_16 ok [%-+F]",
		"test_F_17 ok [%-+10F]",
		"test_F_18 ok [% +10.4F]",
		"test_F_19 ok [% 10.4F]",
		"test_F_20 ok [% .4F]",
		"test_F_21 ok [% F]",
		"test_F_22 ok [% 10F]",
		"test_F_23 ok [% +.4F]",
		"test_F_24 ok [% +F]",
		"test_F_25 ok [% +10F]",
		"test_F_26 ok [% -10.4F]",
		"test_F_27 ok [% -.4F]",
		"test_F_28 ok [% -F]",
		"test_F_29 ok [% -10F]",
		"test_F_30 ok [% -+.4F]",
		"test_F_31 ok [% -+F]",
		"test_F_32 ok [% -+10F]",
		"test_F_33 ok [%0-+10.4F]",
		"test_F_34 ok [%0+10.4F]",
		"test_F_35 ok [%010.4F]",
		"test_F_36 ok [%0.4F]",
		"test_F_37 ok [%0F]",
		"test_F_38 ok [%010F]",
		"test_F_39 ok [%0+.4F]",
		"test_F_40 ok [%0+F]",
		"test_F_41 ok [%0+10F]",
		"test_F_42 ok [%0-10.4F]",
		"test_F_43 ok [%0-.4F]",
		"test_F_44 ok [%0-F]",
		"test_F_45 ok [%0-10F]",
		"test_F_46 ok [%0-+.4F]",
		"test_F_47 ok [%0-+F]",
		"test_F_48 ok [%0-+10F]",
		"test_F_49 ok [%0 +10.4F]",
		"test_F_50 ok [%0 10.4F]",
		"test_F_51 ok [%0 .4F]",
		"test_F_52 ok [%0 F]",
		"test_F_53 ok [%0 10F]",
		"test_F_54 ok [%0 +.4F]",
		"test_F_55 ok [%0 +F]",
		"test_F_56 ok [%0 +10F]",
		"test_F_57 ok [%0 -10.4F]",
		"test_F_58 ok [%0 -.4F]",
		"test_F_59 ok [%0 -F]",
		"test_F_60 ok [%0 -10F]",
		"test_F_61 ok [%0 -+.4F]",
		"test_F_62 ok [%0 -+F]",
		"test_F_63 ok [%0 -+10F]",
		"test_F_64 ok [%# -+10.4F]",
		"test_F_65 ok [%#-+10.4F]",
		"test_F_66 ok [%#+10.4F]",
		"test_F_67 ok [%#10.4F]",
		"test_F_68 ok [%#.4F]",
		"test_F_69 ok [%#F]",
		"test_F_70 ok [%#10F]",
		"test_F_71 ok [%#+.4F]",
		"test_F_72 ok [%#+F]",
		"test_F_73 ok [%#+10F]",
		"test_F_74 ok [%#-10.4F]",
		"test_F_75 ok [%#-.4F]",
		"test_F_76 ok [%#-F]",
		"test_F_77 ok [%#-10F]",
		"test_F_78 ok [%#-+.4F]",
		"test_F_79 ok [%#-+F]",
		"test_F_80 ok [%#-+10F]",
		"test_F_81 ok [%# +10.4F]",
		"test_F_82 ok [%# 10.4F]",
		"test_F_83 ok [%# .4F]",
		"test_F_84 ok [%# F]",
		"test_F_85 ok [%# 10F]",
		"test_F_86 ok [%# +.4F]",
		"test_F_87 ok [%# +F]",
		"test_F_88 ok [%# +10F]",
		"test_F_89 ok [%# -10.4F]",
		"test_F_90 ok [%# -.4F]",
		"test_F_91 ok [%# -F]",
		"test_F_92 ok [%# -10F]",
		"test_F_93 ok [%# -+.4F]",
		"test_F_94 ok [%# -+F]",
		"test_F_95 ok [%# -+10F]",
		"test_F_96 ok [%#0-+10.4F]",
		"test_F_97 ok [%#0+10.4F]",
		"test_F_98 ok [%#010.4F]",
		"test_F_99 ok [%#0.4F]",
		"test_F_100 ok [%#0F]",
		"test_F_101 ok [%#010F]",
		"test_F_102 ok [%#0+.4F]",
		"test_F_103 ok [%#0+F]",
		"test_F_104 ok [%#0+10F]",
		"test_F_105 ok [%#0-10.4F]",
		"test_F_106 ok [%#0-.4F]",
		"test_F_107 ok [%#0-F]",
		"test_F_108 ok [%#0-10F]",
		"test_F_109 ok [%#0-+.4F]",
		"test_F_110 ok [%#0-+F]",
		"test_F_111 ok [%#0-+10F]",
		"test_F_112 ok [%#0 +10.4F]",
		"test_F_113 ok [%#0 10.4F]",
		"test_F_114 ok [%#0 .4F]",
		"test_F_115 ok [%#0 F]",
		"test_F_116 ok [%#0 10F]",
		"test_F_117 ok [%#0 +.4F]",
		"test_F_118 ok [%#0 +F]",
		"test_F_119 ok [%#0 +10F]",
		"test_F_120 ok [%#0 -10.4F]",
		"test_F_121 ok [%#0 -.4F]",
		"test_F_122 ok [%#0 -F]",
		"test_F_123 ok [%#0 -10F]",
		"test_F_124 ok [%#0 -+.4F]",
		"test_F_125 ok [%#0 -+F]",
		"test_F_126 ok [%#0 -+10F]",
		"test_fr_1 ok [%F]",
		"test_fr_2 ok [%.5F]",
		"test_fr_3 ok [%.4F]",
		"test_fr_4 ok [%.3F]",
		"test_fr_5 ok [%.2F]",
		"test_fr_6 ok [%.1F]",
		"test_fr_7 ok [%.0F]",
		NULL
	};

	double stop_num = -42;
	double num[] = {
		FLT_MIN,
		FLT_MAX,
		FLT_EPSILON,
		0,
		-0,
		1,
		-1,
		2,
		-2,
		0.2,
		-0.2,
		2.0625,
		3.03125,
		4.09375,
		4.00001,
		1.0 / 0.0,
		-1.0 / 0.0,
		0.0 / 0.0,
		stop_num
	};

	idx = -1;
	while (str[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			fun(str[idx], num[idxn]);
			//fun("\t\t\t\t//\tprintf(\"%s\", %F); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
			fun("\n");
		}
	}
}
