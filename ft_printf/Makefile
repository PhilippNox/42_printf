# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 13:35:31 by wgorold           #+#    #+#              #
#    Updated: 2019/06/27 02:51:30 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# How 2 make this Makefile
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c//" | while read x ; do echo "\$(PATH_S)$x.o: $x.c\n\t\$(CC) \$(CFLAGS) $x.c \$(FLAG_PATH_OBJ)" ; done
#
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c//" | while read x ; do echo "\$(PATH_S)$x.o: \$(PATH_T)$x.c\n\t\$(CC) \$(CFLAGS) \$(PATH_T)$x.c \$(FLAG_PATH_OBJ)" ; done
#
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c/\.o/" \
# 	| tr '\n' ' '
#

NAME=libftprintf.a

CC=gcc

FLAGS= -Wall -Wextra -Werror

CFLAGS= -c $(FLAGS)

SRC=	mat_precision_0_init.o mat_precision_1_print.o mat_precision_2_power.o \
			mat_precision_3_sum_frc.o mat_precision_4_sum_ent.o \
			mat_precision_1_print_2.o mat_precision_5_power_tab.o \
			mat_precision_6_get_calc.o mat_precision_7_get_run.o \
			mat_precision_8_round.o \
			ft_atoi.o ft_make_c.o ft_make_d1.o \
			ft_make_d.o ft_make_p.o ft_make_s.o ft_printf.o ft_printf_helper.o \
			ft_printf_task.o ft_printf_task_helper.o \
			ft_put.o ft_put_itoa.o ft_put_num.o ft_put_str.o ft_put_unicode.o \
			ft_make_o.o ft_make_u.o ft_make_x.o \
			ft_make_f.o ft_make_bs.o ft_make_bc.o ft_make__.o ft_boost_write.o \
			mat_boost.o mat_boost_do.o \
			mat_boost_pos_15360.o mat_boost_pos_14336.o \
			mat_boost_pos_12288.o mat_boost_pos_8192.o mat_boost_pos_4096.o \
			mat_boost_neg_15360.o mat_boost_neg_15360_1.o \
			mat_boost_neg_14336.o mat_boost_neg_14336_1.o\
			mat_boost_neg_12288.o mat_boost_neg_12288_1.o \
			mat_boost_neg_8192.o mat_boost_neg_4096.o
PATH_S=./obj/
PATH_SRC= $(patsubst %.o, $(PATH_S)%.o, $(SRC))
FLAG_PATH_OBJ= -o $@

TST=	test_c.o test_cp.o test_c_utf8.o test_d.o test_d_small.o test_i.o \
			test_p.o test_s.o test_s_small.o test_o.o test_u.o test_x.o test_xx.o \
			test_hhd.o test_hd.o test_ld.o test_lld.o \
			test_hhi.o test_hi.o test_li.o test_lli.o \
			test_hho.o test_ho.o test_lo.o test_llo.o \
			test_hhu.o test_hu.o test_lu.o test_llu.o \
			test_hhx.o test_hx.o test_lx.o test_llx.o \
			test_hhxx.o test_hxx.o test_lxx.o test_llxx.o \
			test_f.o test_fs.o test_fr.o test_Lf.o test_ff.o test_Lff.o test_star.o \
			test__.o
PATH_T=./test/
PATH_TST= $(patsubst %.o, $(PATH_S)%.o, $(TST))

all: $(NAME)

$(NAME): $(PATH_SRC)
	ar rc $(NAME) $(PATH_SRC)

$(PATH_S)mat_precision_0_init.o: mat_precision_0_init.c
	$(CC) $(CFLAGS) mat_precision_0_init.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_precision_1_print.o: mat_precision_1_print.c
	$(CC) $(CFLAGS) mat_precision_1_print.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_precision_2_power.o: mat_precision_2_power.c
	$(CC) $(CFLAGS) mat_precision_2_power.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_precision_3_sum_frc.o: mat_precision_3_sum_frc.c
	$(CC) $(CFLAGS) mat_precision_3_sum_frc.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_precision_4_sum_ent.o: mat_precision_4_sum_ent.c
	$(CC) $(CFLAGS) mat_precision_4_sum_ent.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_precision_1_print_2.o: mat_precision_1_print_2.c
	$(CC) $(CFLAGS) mat_precision_1_print_2.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_precision_5_power_tab.o: mat_precision_5_power_tab.c
	$(CC) $(CFLAGS) mat_precision_5_power_tab.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_precision_6_get_calc.o: mat_precision_6_get_calc.c
	$(CC) $(CFLAGS) mat_precision_6_get_calc.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_precision_7_get_run.o: mat_precision_7_get_run.c
	$(CC) $(CFLAGS) mat_precision_7_get_run.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_precision_8_round.o: mat_precision_8_round.c
	$(CC) $(CFLAGS) mat_precision_8_round.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_atoi.o: ft_atoi.c
	$(CC) $(CFLAGS) ft_atoi.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_make_c.o: ft_make_c.c
	$(CC) $(CFLAGS) ft_make_c.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_make_bc.o: ft_make_bc.c
	$(CC) $(CFLAGS) ft_make_bc.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_make_d.o: ft_make_d.c
	$(CC) $(CFLAGS) ft_make_d.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_make_d1.o: ft_make_d1.c
	$(CC) $(CFLAGS) ft_make_d1.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_make_f.o: ft_make_f.c
	$(CC) $(CFLAGS) ft_make_f.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_make_o.o: ft_make_o.c
	$(CC) $(CFLAGS) ft_make_o.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_make_p.o: ft_make_p.c
	$(CC) $(CFLAGS) ft_make_p.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_make_s.o: ft_make_s.c
	$(CC) $(CFLAGS) ft_make_s.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_make_bs.o: ft_make_bs.c
	$(CC) $(CFLAGS) ft_make_bs.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_make_u.o: ft_make_u.c
	$(CC) $(CFLAGS) ft_make_u.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_make_x.o: ft_make_x.c
	$(CC) $(CFLAGS) ft_make_x.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_make__.o: ft_make__.c
	$(CC) $(CFLAGS) ft_make__.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_printf.o: ft_printf.c
	$(CC) $(CFLAGS) ft_printf.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_printf_helper.o: ft_printf_helper.c
	$(CC) $(CFLAGS) ft_printf_helper.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_printf_task.o: ft_printf_task.c
	$(CC) $(CFLAGS) ft_printf_task.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_printf_task_helper.o: ft_printf_task_helper.c
	$(CC) $(CFLAGS) ft_printf_task_helper.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_put.o: ft_put.c
	$(CC) $(CFLAGS) ft_put.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_put_itoa.o: ft_put_itoa.c
	$(CC) $(CFLAGS) ft_put_itoa.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_put_num.o: ft_put_num.c
	$(CC) $(CFLAGS) ft_put_num.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_put_str.o: ft_put_str.c
	$(CC) $(CFLAGS) ft_put_str.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_put_unicode.o: ft_put_unicode.c
	$(CC) $(CFLAGS) ft_put_unicode.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_boost_write.o: ft_boost_write.c
	$(CC) $(CFLAGS) ft_boost_write.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost.o: mat_boost.c
	$(CC) $(CFLAGS) mat_boost.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_do.o: mat_boost_do.c
	$(CC) $(CFLAGS) mat_boost_do.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_pos_15360.o: mat_boost_pos_15360.c
	$(CC) $(CFLAGS) mat_boost_pos_15360.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_pos_14336.o: mat_boost_pos_14336.c
	$(CC) $(CFLAGS) mat_boost_pos_14336.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_pos_12288.o: mat_boost_pos_12288.c
	$(CC) $(CFLAGS) mat_boost_pos_12288.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_pos_8192.o: mat_boost_pos_8192.c
	$(CC) $(CFLAGS) mat_boost_pos_8192.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_pos_4096.o: mat_boost_pos_4096.c
	$(CC) $(CFLAGS) mat_boost_pos_4096.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_neg_15360.o: mat_boost_neg_15360.c
	$(CC) $(CFLAGS) mat_boost_neg_15360.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_neg_15360_1.o: mat_boost_neg_15360_1.c
	$(CC) $(CFLAGS) mat_boost_neg_15360_1.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_neg_14336.o: mat_boost_neg_14336.c
	$(CC) $(CFLAGS) mat_boost_neg_14336.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_neg_14336_1.o: mat_boost_neg_14336_1.c
	$(CC) $(CFLAGS) mat_boost_neg_14336_1.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_neg_12288.o: mat_boost_neg_12288.c
	$(CC) $(CFLAGS) mat_boost_neg_12288.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_neg_12288_1.o: mat_boost_neg_12288_1.c
	$(CC) $(CFLAGS) mat_boost_neg_12288_1.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_neg_8192.o: mat_boost_neg_8192.c
	$(CC) $(CFLAGS) mat_boost_neg_8192.c $(FLAG_PATH_OBJ)
$(PATH_S)mat_boost_neg_4096.o: mat_boost_neg_4096.c
	$(CC) $(CFLAGS) mat_boost_neg_4096.c $(FLAG_PATH_OBJ)

clean:
	@rm -f $(PATH_SRC) $(PATH_TST)

fclean: clean
	@rm -f $(NAME);

re: fclean all
