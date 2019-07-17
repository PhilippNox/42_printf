/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hhxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:35:27 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: hhX] _hhd %hhd

#include "tests.h"

void test_hhxx(int (*fun)(const char *format, ...))
{
	int idX;
	int idXn;
	char *str[] = {
		"test_hhX_0 ok [%#0 -+10.4hhX]",
		"test_hhX_1 ok [%0 -+10.4hhX]",
		"test_hhX_2 ok [% -+10.4hhX]",
		"test_hhX_3 ok [%-+10.4hhX]",
		"test_hhX_4 ok [%+10.4hhX]",
		"test_hhX_5 ok [%10.4hhX]",
		"test_hhX_6 ok [%.4hhX]",
		"test_hhX_7 ok [%10hhX]",
		"test_hhX_8 ok [%+.4hhX]",
		"test_hhX_9 ok [%+hhX]",
		"test_hhX_10 ok [%+10hhX]",
		"test_hhX_11 ok [%-10.4hhX]",
		"test_hhX_12 ok [%-.4hhX]",
		"test_hhX_13 ok [%-hhX]",
		"test_hhX_14 ok [%-10hhX]",
		"test_hhX_15 ok [%-+.4hhX]",
		"test_hhX_16 ok [%-+hhX]",
		"test_hhX_17 ok [%-+10hhX]",
		"test_hhX_18 ok [% +10.4hhX]",
		"test_hhX_19 ok [% 10.4hhX]",
		"test_hhX_20 ok [% .4hhX]",
		"test_hhX_21 ok [% hhX]",
		"test_hhX_22 ok [% 10hhX]",
		"test_hhX_23 ok [% +.4hhX]",
		"test_hhX_24 ok [% +hhX]",
		"test_hhX_25 ok [% +10hhX]",
		"test_hhX_26 ok [% -10.4hhX]",
		"test_hhX_27 ok [% -.4hhX]",
		"test_hhX_28 ok [% -hhX]",
		"test_hhX_29 ok [% -10hhX]",
		"test_hhX_30 ok [% -+.4hhX]",
		"test_hhX_31 ok [% -+hhX]",
		"test_hhX_32 ok [% -+10hhX]",
		"test_hhX_33 ok [%0-+10.4hhX]",
		"test_hhX_34 ok [%0+10.4hhX]",
		"test_hhX_35 ok [%010.4hhX]",
		"test_hhX_36 ok [%0.4hhX]",
		"test_hhX_37 ok [%0hhX]",
		"test_hhX_38 ok [%010hhX]",
		"test_hhX_39 ok [%0+.4hhX]",
		"test_hhX_40 ok [%0+hhX]",
		"test_hhX_41 ok [%0+10hhX]",
		"test_hhX_42 ok [%0-10.4hhX]",
		"test_hhX_43 ok [%0-.4hhX]",
		"test_hhX_44 ok [%0-hhX]",
		"test_hhX_45 ok [%0-10hhX]",
		"test_hhX_46 ok [%0-+.4hhX]",
		"test_hhX_47 ok [%0-+hhX]",
		"test_hhX_48 ok [%0-+10hhX]",
		"test_hhX_49 ok [%0 +10.4hhX]",
		"test_hhX_50 ok [%0 10.4hhX]",
		"test_hhX_51 ok [%0 .4hhX]",
		"test_hhX_52 ok [%0 hhX]",
		"test_hhX_53 ok [%0 10hhX]",
		"test_hhX_54 ok [%0 +.4hhX]",
		"test_hhX_55 ok [%0 +hhX]",
		"test_hhX_56 ok [%0 +10hhX]",
		"test_hhX_57 ok [%0 -10.4hhX]",
		"test_hhX_58 ok [%0 -.4hhX]",
		"test_hhX_59 ok [%0 -hhX]",
		"test_hhX_60 ok [%0 -10hhX]",
		"test_hhX_61 ok [%0 -+.4hhX]",
		"test_hhX_62 ok [%0 -+hhX]",
		"test_hhX_63 ok [%0 -+10hhX]",
		"test_hhX_64 ok [%# -+10.4hhX]",
		"test_hhX_65 ok [%#-+10.4hhX]",
		"test_hhX_66 ok [%#+10.4hhX]",
		"test_hhX_67 ok [%#10.4hhX]",
		"test_hhX_68 ok [%#.4hhX]",
		"test_hhX_69 ok [%#hhX]",
		"test_hhX_70 ok [%#10hhX]",
		"test_hhX_71 ok [%#+.4hhX]",
		"test_hhX_72 ok [%#+hhX]",
		"test_hhX_73 ok [%#+10hhX]",
		"test_hhX_74 ok [%#-10.4hhX]",
		"test_hhX_75 ok [%#-.4hhX]",
		"test_hhX_76 ok [%#-hhX]",
		"test_hhX_77 ok [%#-10hhX]",
		"test_hhX_78 ok [%#-+.4hhX]",
		"test_hhX_79 ok [%#-+hhX]",
		"test_hhX_80 ok [%#-+10hhX]",
		"test_hhX_81 ok [%# +10.4hhX]",
		"test_hhX_82 ok [%# 10.4hhX]",
		"test_hhX_83 ok [%# .4hhX]",
		"test_hhX_84 ok [%# hhX]",
		"test_hhX_85 ok [%# 10hhX]",
		"test_hhX_86 ok [%# +.4hhX]",
		"test_hhX_87 ok [%# +hhX]",
		"test_hhX_88 ok [%# +10hhX]",
		"test_hhX_89 ok [%# -10.4hhX]",
		"test_hhX_90 ok [%# -.4hhX]",
		"test_hhX_91 ok [%# -hhX]",
		"test_hhX_92 ok [%# -10hhX]",
		"test_hhX_93 ok [%# -+.4hhX]",
		"test_hhX_94 ok [%# -+hhX]",
		"test_hhX_95 ok [%# -+10hhX]",
		"test_hhX_96 ok [%#0-+10.4hhX]",
		"test_hhX_97 ok [%#0+10.4hhX]",
		"test_hhX_98 ok [%#010.4hhX]",
		"test_hhX_99 ok [%#0.4hhX]",
		"test_hhX_100 ok [%#0hhX]",
		"test_hhX_101 ok [%#010hhX]",
		"test_hhX_102 ok [%#0+.4hhX]",
		"test_hhX_103 ok [%#0+hhX]",
		"test_hhX_104 ok [%#0+10hhX]",
		"test_hhX_105 ok [%#0-10.4hhX]",
		"test_hhX_106 ok [%#0-.4hhX]",
		"test_hhX_107 ok [%#0-hhX]",
		"test_hhX_108 ok [%#0-10hhX]",
		"test_hhX_109 ok [%#0-+.4hhX]",
		"test_hhX_110 ok [%#0-+hhX]",
		"test_hhX_111 ok [%#0-+10hhX]",
		"test_hhX_112 ok [%#0 +10.4hhX]",
		"test_hhX_113 ok [%#0 10.4hhX]",
		"test_hhX_114 ok [%#0 .4hhX]",
		"test_hhX_115 ok [%#0 hhX]",
		"test_hhX_116 ok [%#0 10hhX]",
		"test_hhX_117 ok [%#0 +.4hhX]",
		"test_hhX_118 ok [%#0 +hhX]",
		"test_hhX_119 ok [%#0 +10hhX]",
		"test_hhX_120 ok [%#0 -10.4hhX]",
		"test_hhX_121 ok [%#0 -.4hhX]",
		"test_hhX_122 ok [%#0 -hhX]",
		"test_hhX_123 ok [%#0 -10hhX]",
		"test_hhX_124 ok [%#0 -+.4hhX]",
		"test_hhX_125 ok [%#0 -+hhX]",
		"test_hhX_126 ok [%#0 -+10hhX]",
		NULL
	};

	int stop_num = -42;
	int num[] = {
		-2147483648,
		-111778123,
		-123,
		-1,
		0,
		1,
		123,
		111778123,
		2147483647,
		stop_num
	};

	idX = -1;
	while (str[++idX])
	{
		idXn = -1;
		while (num[++idXn] != stop_num)
		{
			fun(str[idX], num[idXn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %hhX); // RUN THIS CODE FOR DEBUG\n", str[idX], num[idXn]);
		}
	}
}
