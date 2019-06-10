# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 13:35:31 by wgorold           #+#    #+#              #
#    Updated: 2019/06/10 23:14:17 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# How 2 make this Makefile
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c//" | while read x ; do echo "$x.o: $x.c\n\t\$(CC) \$(CFLAGS) $x.c \$(FLAG_PATH_OBJ)" ; done
#
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c//" | while read x ; do echo "$x.o: \$(PATH_T)$x.c\n\t\$(CC) \$(CFLAGS) \$(PATH_T)$x.c \$(FLAG_PATH_OBJ)" ; done
#
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c/\.o/" \
# 	| tr '\n' ' '
#

NAME=run_test

RND=roundnig

RNDL=roundnig_long

LIBNAME=libftprintf.a

CC=gcc

#FLAGS= -Wall -Wextra -Werror
FLAGS= -Wall -Wextra

CFLAGS= -c $(FLAGS)

SRC=	1_mat_precision_1.o 2_mat_precision_2.o 3_mat_precision_print.o \
			ft_atoi.o ft_make_c.o \
			ft_make_d.o ft_make_p.o ft_make_s.o ft_printf.o ft_printf_helper.o \
			ft_printf_task.o ft_put.o ft_make_o.o ft_make_u.o ft_make_x.o \
			ft_make_f.o
PATH_S=./obj/
PATH_SRC= $(patsubst %.o, $(PATH_S)%.o, $(SRC))
FLAG_PATH_OBJ= -o $(PATH_S)$@

TST=	test_c.o test_cp.o test_c_utf8.o test_d.o test_d_small.o test_i.o \
			test_p.o test_s.o test_s_small.o test_o.o test_u.o test_x.o test_xx.o \
			test_hhd.o test_hd.o test_ld.o test_lld.o \
			test_hhi.o test_hi.o test_li.o test_lli.o \
			test_hho.o test_ho.o test_lo.o test_llo.o \
			test_hhu.o test_hu.o test_lu.o test_llu.o \
			test_hhx.o test_hx.o test_lx.o test_llx.o \
			test_hhxx.o test_hxx.o test_lxx.o test_llxx.o \
			test_f.o test_fs.o test_fr.o test_Lf.o test_ff.o test_Lff.o
PATH_T=./test/
PATH_TST= $(patsubst %.o, $(PATH_S)%.o, $(TST))

# https://www.gnu.org/software/make/manual/html_node/Text-Functions.html

all: $(LIBNAME)

tst: $(NAME)
	sh ./z_check.sh

tstc: $(NAME) clean
	sh ./z_check.sh -d;
	@rm -f $(NAME) $(LIBNAME);

run: $(NAME) clean
	./run_test
	@rm -f $(NAME) $(LIBNAME);

rnd: $(RND) clean
	./roundnig
	@rm -f $(RND) $(LIBNAME);

rndl: $(RNDL) clean
	./roundnig_long
	@rm -f $(RNDL) $(LIBNAME);

rrr: $(SRC)
	echo $(OBJS)

$(LIBNAME): $(SRC)
	ar rc $(LIBNAME) $(PATH_SRC)

$(NAME): $(SRC) $(TST)
	@$(CC) $(FLAGS) $(PATH_SRC) $(PATH_TST) $(PATH_T)main_test.c -o $(NAME) -I./

$(RND): $(SRC) $(TST)
	@$(CC) $(FLAGS) $(SRC) $(TST) $(PATH_TST)test_f_rounding.c -o $(RND)

$(RNDL): $(SRC) $(TST)
	@$(CC) $(FLAGS) $(SRC) $(TST) $(PATH_TST)test_Lf_rounding.c -o $(RNDL)

1_mat_precision_1.o: 1_mat_precision_1.c
	$(CC) $(CFLAGS) 1_mat_precision_1.c $(FLAG_PATH_OBJ)
2_mat_precision_2.o: 2_mat_precision_2.c
	$(CC) $(CFLAGS) 2_mat_precision_2.c $(FLAG_PATH_OBJ)
3_mat_precision_print.o: 3_mat_precision_print.c
	$(CC) $(CFLAGS) 3_mat_precision_print.c $(FLAG_PATH_OBJ)
ft_atoi.o: ft_atoi.c
	$(CC) $(CFLAGS) ft_atoi.c $(FLAG_PATH_OBJ)
ft_make_c.o: ft_make_c.c
	$(CC) $(CFLAGS) ft_make_c.c $(FLAG_PATH_OBJ)
ft_make_d.o: ft_make_d.c
	$(CC) $(CFLAGS) ft_make_d.c $(FLAG_PATH_OBJ)
ft_make_f.o: ft_make_f.c
	$(CC) $(CFLAGS) ft_make_f.c $(FLAG_PATH_OBJ)
ft_make_o.o: ft_make_o.c
	$(CC) $(CFLAGS) ft_make_o.c $(FLAG_PATH_OBJ)
ft_make_p.o: ft_make_p.c
	$(CC) $(CFLAGS) ft_make_p.c $(FLAG_PATH_OBJ)
ft_make_s.o: ft_make_s.c
	$(CC) $(CFLAGS) ft_make_s.c $(FLAG_PATH_OBJ)
ft_make_u.o: ft_make_u.c
	$(CC) $(CFLAGS) ft_make_u.c $(FLAG_PATH_OBJ)
ft_make_x.o: ft_make_x.c
	$(CC) $(CFLAGS) ft_make_x.c $(FLAG_PATH_OBJ)
ft_printf.o: ft_printf.c
	$(CC) $(CFLAGS) ft_printf.c $(FLAG_PATH_OBJ)
ft_printf_helper.o: ft_printf_helper.c
	$(CC) $(CFLAGS) ft_printf_helper.c $(FLAG_PATH_OBJ)
ft_printf_task.o: ft_printf_task.c
	$(CC) $(CFLAGS) ft_printf_task.c $(FLAG_PATH_OBJ)
ft_put.o: ft_put.c
	$(CC) $(CFLAGS) ft_put.c $(FLAG_PATH_OBJ)


test_c.o: $(PATH_T)test_c.c
	$(CC) $(CFLAGS) $(PATH_T)test_c.c $(FLAG_PATH_OBJ)
test_c_utf8.o: $(PATH_T)test_c_utf8.c
	$(CC) $(CFLAGS) $(PATH_T)test_c_utf8.c $(FLAG_PATH_OBJ)
test_cp.o: $(PATH_T)test_cp.c
	$(CC) $(CFLAGS) $(PATH_T)test_cp.c $(FLAG_PATH_OBJ)
test_d.o: $(PATH_T)test_d.c
	$(CC) $(CFLAGS) $(PATH_T)test_d.c $(FLAG_PATH_OBJ)
test_d_small.o: $(PATH_T)test_d_small.c
	$(CC) $(CFLAGS) $(PATH_T)test_d_small.c $(FLAG_PATH_OBJ)
test_f.o: $(PATH_T)test_f.c
	$(CC) $(CFLAGS) $(PATH_T)test_f.c $(FLAG_PATH_OBJ)
test_ff.o: $(PATH_T)test_ff.c
	$(CC) $(CFLAGS) $(PATH_T)test_ff.c $(FLAG_PATH_OBJ)
test_fr.o: $(PATH_T)test_fr.c
	$(CC) $(CFLAGS) $(PATH_T)test_fr.c $(FLAG_PATH_OBJ) -I./
test_fs.o: $(PATH_T)test_fs.c
	$(CC) $(CFLAGS) $(PATH_T)test_fs.c $(FLAG_PATH_OBJ)
test_hd.o: $(PATH_T)test_hd.c
	$(CC) $(CFLAGS) $(PATH_T)test_hd.c $(FLAG_PATH_OBJ)
test_hhd.o: $(PATH_T)test_hhd.c
	$(CC) $(CFLAGS) $(PATH_T)test_hhd.c $(FLAG_PATH_OBJ)
test_hhi.o: $(PATH_T)test_hhi.c
	$(CC) $(CFLAGS) $(PATH_T)test_hhi.c $(FLAG_PATH_OBJ)
test_hho.o: $(PATH_T)test_hho.c
	$(CC) $(CFLAGS) $(PATH_T)test_hho.c $(FLAG_PATH_OBJ)
test_hhu.o: $(PATH_T)test_hhu.c
	$(CC) $(CFLAGS) $(PATH_T)test_hhu.c $(FLAG_PATH_OBJ)
test_hhx.o: $(PATH_T)test_hhx.c
	$(CC) $(CFLAGS) $(PATH_T)test_hhx.c $(FLAG_PATH_OBJ)
test_hhxx.o: $(PATH_T)test_hhxx.c
	$(CC) $(CFLAGS) $(PATH_T)test_hhxx.c $(FLAG_PATH_OBJ)
test_hi.o: $(PATH_T)test_hi.c
	$(CC) $(CFLAGS) $(PATH_T)test_hi.c $(FLAG_PATH_OBJ)
test_ho.o: $(PATH_T)test_ho.c
	$(CC) $(CFLAGS) $(PATH_T)test_ho.c $(FLAG_PATH_OBJ)
test_hu.o: $(PATH_T)test_hu.c
	$(CC) $(CFLAGS) $(PATH_T)test_hu.c $(FLAG_PATH_OBJ)
test_hx.o: $(PATH_T)test_hx.c
	$(CC) $(CFLAGS) $(PATH_T)test_hx.c $(FLAG_PATH_OBJ)
test_hxx.o: $(PATH_T)test_hxx.c
	$(CC) $(CFLAGS) $(PATH_T)test_hxx.c $(FLAG_PATH_OBJ)
test_i.o: $(PATH_T)test_i.c
	$(CC) $(CFLAGS) $(PATH_T)test_i.c $(FLAG_PATH_OBJ)
test_ld.o: $(PATH_T)test_ld.c
	$(CC) $(CFLAGS) $(PATH_T)test_ld.c $(FLAG_PATH_OBJ)
test_Lf.o: $(PATH_T)test_Lf.c
	$(CC) $(CFLAGS) $(PATH_T)test_Lf.c $(FLAG_PATH_OBJ)
test_Lff.o: $(PATH_T)test_Lff.c
	$(CC) $(CFLAGS) $(PATH_T)test_Lff.c $(FLAG_PATH_OBJ)
test_li.o: $(PATH_T)test_li.c
	$(CC) $(CFLAGS) $(PATH_T)test_li.c $(FLAG_PATH_OBJ)
test_lld.o: $(PATH_T)test_lld.c
	$(CC) $(CFLAGS) $(PATH_T)test_lld.c $(FLAG_PATH_OBJ)
test_lli.o: $(PATH_T)test_lli.c
	$(CC) $(CFLAGS) $(PATH_T)test_lli.c $(FLAG_PATH_OBJ)
test_llo.o: $(PATH_T)test_llo.c
	$(CC) $(CFLAGS) $(PATH_T)test_llo.c $(FLAG_PATH_OBJ)
test_llu.o: $(PATH_T)test_llu.c
	$(CC) $(CFLAGS) $(PATH_T)test_llu.c $(FLAG_PATH_OBJ)
test_llx.o: $(PATH_T)test_llx.c
	$(CC) $(CFLAGS) $(PATH_T)test_llx.c $(FLAG_PATH_OBJ)
test_llxx.o: $(PATH_T)test_llxx.c
	$(CC) $(CFLAGS) $(PATH_T)test_llxx.c $(FLAG_PATH_OBJ)
test_lo.o: $(PATH_T)test_lo.c
	$(CC) $(CFLAGS) $(PATH_T)test_lo.c $(FLAG_PATH_OBJ)
test_longd.o: $(PATH_T)test_longd.c
	$(CC) $(CFLAGS) $(PATH_T)test_longd.c $(FLAG_PATH_OBJ)
test_lu.o: $(PATH_T)test_lu.c
	$(CC) $(CFLAGS) $(PATH_T)test_lu.c $(FLAG_PATH_OBJ)
test_lx.o: $(PATH_T)test_lx.c
	$(CC) $(CFLAGS) $(PATH_T)test_lx.c $(FLAG_PATH_OBJ)
test_lxx.o: $(PATH_T)test_lxx.c
	$(CC) $(CFLAGS) $(PATH_T)test_lxx.c $(FLAG_PATH_OBJ)
test_o.o: $(PATH_T)test_o.c
	$(CC) $(CFLAGS) $(PATH_T)test_o.c $(FLAG_PATH_OBJ)
test_p.o: $(PATH_T)test_p.c
	$(CC) $(CFLAGS) $(PATH_T)test_p.c $(FLAG_PATH_OBJ)
test_run.o: $(PATH_T)test_run.c
	$(CC) $(CFLAGS) $(PATH_T)test_run.c $(FLAG_PATH_OBJ)
test_s.o: $(PATH_T)test_s.c
	$(CC) $(CFLAGS) $(PATH_T)test_s.c $(FLAG_PATH_OBJ)
test_s_small.o: $(PATH_T)test_s_small.c
	$(CC) $(CFLAGS) $(PATH_T)test_s_small.c $(FLAG_PATH_OBJ)
test_u.o: $(PATH_T)test_u.c
	$(CC) $(CFLAGS) $(PATH_T)test_u.c $(FLAG_PATH_OBJ)
test_x.o: $(PATH_T)test_x.c
	$(CC) $(CFLAGS) $(PATH_T)test_x.c $(FLAG_PATH_OBJ)
test_xx.o: $(PATH_T)test_xx.c
	$(CC) $(CFLAGS) $(PATH_T)test_xx.c $(FLAG_PATH_OBJ)

clean:
	@rm -f $(PATH_SRC) $(PATH_TST)

fclean: clean
	@rm -f $(NAME) $(LIBNAME);

re: fclean all
