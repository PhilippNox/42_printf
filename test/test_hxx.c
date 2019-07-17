/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:35:22 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: hX] _hd %hd

#include "tests.h"

void test_hxx(int (*fun)(const char *format, ...))
{
	int idX;
	int idXn;
	char *str[] = {
		"test_hX_0 ok [%#0 -+10.4hX]",
		"test_hX_1 ok [%0 -+10.4hX]",
		"test_hX_2 ok [% -+10.4hX]",
		"test_hX_3 ok [%-+10.4hX]",
		"test_hX_4 ok [%+10.4hX]",
		"test_hX_5 ok [%10.4hX]",
		"test_hX_6 ok [%.4hX]",
		"test_hX_7 ok [%10hX]",
		"test_hX_8 ok [%+.4hX]",
		"test_hX_9 ok [%+hX]",
		"test_hX_10 ok [%+10hX]",
		"test_hX_11 ok [%-10.4hX]",
		"test_hX_12 ok [%-.4hX]",
		"test_hX_13 ok [%-hX]",
		"test_hX_14 ok [%-10hX]",
		"test_hX_15 ok [%-+.4hX]",
		"test_hX_16 ok [%-+hX]",
		"test_hX_17 ok [%-+10hX]",
		"test_hX_18 ok [% +10.4hX]",
		"test_hX_19 ok [% 10.4hX]",
		"test_hX_20 ok [% .4hX]",
		"test_hX_21 ok [% hX]",
		"test_hX_22 ok [% 10hX]",
		"test_hX_23 ok [% +.4hX]",
		"test_hX_24 ok [% +hX]",
		"test_hX_25 ok [% +10hX]",
		"test_hX_26 ok [% -10.4hX]",
		"test_hX_27 ok [% -.4hX]",
		"test_hX_28 ok [% -hX]",
		"test_hX_29 ok [% -10hX]",
		"test_hX_30 ok [% -+.4hX]",
		"test_hX_31 ok [% -+hX]",
		"test_hX_32 ok [% -+10hX]",
		"test_hX_33 ok [%0-+10.4hX]",
		"test_hX_34 ok [%0+10.4hX]",
		"test_hX_35 ok [%010.4hX]",
		"test_hX_36 ok [%0.4hX]",
		"test_hX_37 ok [%0hX]",
		"test_hX_38 ok [%010hX]",
		"test_hX_39 ok [%0+.4hX]",
		"test_hX_40 ok [%0+hX]",
		"test_hX_41 ok [%0+10hX]",
		"test_hX_42 ok [%0-10.4hX]",
		"test_hX_43 ok [%0-.4hX]",
		"test_hX_44 ok [%0-hX]",
		"test_hX_45 ok [%0-10hX]",
		"test_hX_46 ok [%0-+.4hX]",
		"test_hX_47 ok [%0-+hX]",
		"test_hX_48 ok [%0-+10hX]",
		"test_hX_49 ok [%0 +10.4hX]",
		"test_hX_50 ok [%0 10.4hX]",
		"test_hX_51 ok [%0 .4hX]",
		"test_hX_52 ok [%0 hX]",
		"test_hX_53 ok [%0 10hX]",
		"test_hX_54 ok [%0 +.4hX]",
		"test_hX_55 ok [%0 +hX]",
		"test_hX_56 ok [%0 +10hX]",
		"test_hX_57 ok [%0 -10.4hX]",
		"test_hX_58 ok [%0 -.4hX]",
		"test_hX_59 ok [%0 -hX]",
		"test_hX_60 ok [%0 -10hX]",
		"test_hX_61 ok [%0 -+.4hX]",
		"test_hX_62 ok [%0 -+hX]",
		"test_hX_63 ok [%0 -+10hX]",
		"test_hX_64 ok [%# -+10.4hX]",
		"test_hX_65 ok [%#-+10.4hX]",
		"test_hX_66 ok [%#+10.4hX]",
		"test_hX_67 ok [%#10.4hX]",
		"test_hX_68 ok [%#.4hX]",
		"test_hX_69 ok [%#hX]",
		"test_hX_70 ok [%#10hX]",
		"test_hX_71 ok [%#+.4hX]",
		"test_hX_72 ok [%#+hX]",
		"test_hX_73 ok [%#+10hX]",
		"test_hX_74 ok [%#-10.4hX]",
		"test_hX_75 ok [%#-.4hX]",
		"test_hX_76 ok [%#-hX]",
		"test_hX_77 ok [%#-10hX]",
		"test_hX_78 ok [%#-+.4hX]",
		"test_hX_79 ok [%#-+hX]",
		"test_hX_80 ok [%#-+10hX]",
		"test_hX_81 ok [%# +10.4hX]",
		"test_hX_82 ok [%# 10.4hX]",
		"test_hX_83 ok [%# .4hX]",
		"test_hX_84 ok [%# hX]",
		"test_hX_85 ok [%# 10hX]",
		"test_hX_86 ok [%# +.4hX]",
		"test_hX_87 ok [%# +hX]",
		"test_hX_88 ok [%# +10hX]",
		"test_hX_89 ok [%# -10.4hX]",
		"test_hX_90 ok [%# -.4hX]",
		"test_hX_91 ok [%# -hX]",
		"test_hX_92 ok [%# -10hX]",
		"test_hX_93 ok [%# -+.4hX]",
		"test_hX_94 ok [%# -+hX]",
		"test_hX_95 ok [%# -+10hX]",
		"test_hX_96 ok [%#0-+10.4hX]",
		"test_hX_97 ok [%#0+10.4hX]",
		"test_hX_98 ok [%#010.4hX]",
		"test_hX_99 ok [%#0.4hX]",
		"test_hX_100 ok [%#0hX]",
		"test_hX_101 ok [%#010hX]",
		"test_hX_102 ok [%#0+.4hX]",
		"test_hX_103 ok [%#0+hX]",
		"test_hX_104 ok [%#0+10hX]",
		"test_hX_105 ok [%#0-10.4hX]",
		"test_hX_106 ok [%#0-.4hX]",
		"test_hX_107 ok [%#0-hX]",
		"test_hX_108 ok [%#0-10hX]",
		"test_hX_109 ok [%#0-+.4hX]",
		"test_hX_110 ok [%#0-+hX]",
		"test_hX_111 ok [%#0-+10hX]",
		"test_hX_112 ok [%#0 +10.4hX]",
		"test_hX_113 ok [%#0 10.4hX]",
		"test_hX_114 ok [%#0 .4hX]",
		"test_hX_115 ok [%#0 hX]",
		"test_hX_116 ok [%#0 10hX]",
		"test_hX_117 ok [%#0 +.4hX]",
		"test_hX_118 ok [%#0 +hX]",
		"test_hX_119 ok [%#0 +10hX]",
		"test_hX_120 ok [%#0 -10.4hX]",
		"test_hX_121 ok [%#0 -.4hX]",
		"test_hX_122 ok [%#0 -hX]",
		"test_hX_123 ok [%#0 -10hX]",
		"test_hX_124 ok [%#0 -+.4hX]",
		"test_hX_125 ok [%#0 -+hX]",
		"test_hX_126 ok [%#0 -+10hX]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %hX); // RUN THIS CODE FOR DEBUG\n", str[idX], num[idXn]);
		}
	}
}
