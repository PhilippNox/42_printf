# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 13:35:31 by wgorold           #+#    #+#              #
#    Updated: 2019/07/17 19:35:06 by wgorold          ###   ########.fr        #
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

TSTNAME=run_test

CC=gcc

#FLAGS= -Wall -Wextra -Werror
FLAGS= -Wall -Wextra

CFLAGS= -c $(FLAGS)

PATH_S=./obj/
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

# https://www.gnu.org/software/make/manual/html_node/Text-Functions.html

all: $(PATH_TST)
	$(CC) $(CFLAGS) main_test.c ./obj/* -o run_test -I${args} -L${args} -lftprintf

$(PATH_S)test_c.o: $(PATH_T)test_c.c
	$(CC) $(CFLAGS) $(PATH_T)test_c.c $(FLAG_PATH_OBJ)
$(PATH_S)test_c_utf8.o: $(PATH_T)test_c_utf8.c
	$(CC) $(CFLAGS) $(PATH_T)test_c_utf8.c $(FLAG_PATH_OBJ)
$(PATH_S)test_cp.o: $(PATH_T)test_cp.c
	$(CC) $(CFLAGS) $(PATH_T)test_cp.c $(FLAG_PATH_OBJ)
$(PATH_S)test_d.o: $(PATH_T)test_d.c
	$(CC) $(CFLAGS) $(PATH_T)test_d.c $(FLAG_PATH_OBJ)
$(PATH_S)test_d_small.o: $(PATH_T)test_d_small.c
	$(CC) $(CFLAGS) $(PATH_T)test_d_small.c $(FLAG_PATH_OBJ)
$(PATH_S)test_f.o: $(PATH_T)test_f.c
	$(CC) $(CFLAGS) $(PATH_T)test_f.c $(FLAG_PATH_OBJ)
$(PATH_S)test_ff.o: $(PATH_T)test_ff.c
	$(CC) $(CFLAGS) $(PATH_T)test_ff.c $(FLAG_PATH_OBJ)
$(PATH_S)test_fr.o: $(PATH_T)test_fr.c
	$(CC) $(CFLAGS) $(PATH_T)test_fr.c $(FLAG_PATH_OBJ) -I../ft_printf
$(PATH_S)test_fs.o: $(PATH_T)test_fs.c
	$(CC) $(CFLAGS) $(PATH_T)test_fs.c $(FLAG_PATH_OBJ)
$(PATH_S)test_hd.o: $(PATH_T)test_hd.c
	$(CC) $(CFLAGS) $(PATH_T)test_hd.c $(FLAG_PATH_OBJ)
$(PATH_S)test_hhd.o: $(PATH_T)test_hhd.c
	$(CC) $(CFLAGS) $(PATH_T)test_hhd.c $(FLAG_PATH_OBJ)
$(PATH_S)test_hhi.o: $(PATH_T)test_hhi.c
	$(CC) $(CFLAGS) $(PATH_T)test_hhi.c $(FLAG_PATH_OBJ)
$(PATH_S)test_hho.o: $(PATH_T)test_hho.c
	$(CC) $(CFLAGS) $(PATH_T)test_hho.c $(FLAG_PATH_OBJ)
$(PATH_S)test_hhu.o: $(PATH_T)test_hhu.c
	$(CC) $(CFLAGS) $(PATH_T)test_hhu.c $(FLAG_PATH_OBJ)
$(PATH_S)test_hhx.o: $(PATH_T)test_hhx.c
	$(CC) $(CFLAGS) $(PATH_T)test_hhx.c $(FLAG_PATH_OBJ)
$(PATH_S)test_hhxx.o: $(PATH_T)test_hhxx.c
	$(CC) $(CFLAGS) $(PATH_T)test_hhxx.c $(FLAG_PATH_OBJ)
$(PATH_S)test_hi.o: $(PATH_T)test_hi.c
	$(CC) $(CFLAGS) $(PATH_T)test_hi.c $(FLAG_PATH_OBJ)
$(PATH_S)test_ho.o: $(PATH_T)test_ho.c
	$(CC) $(CFLAGS) $(PATH_T)test_ho.c $(FLAG_PATH_OBJ)
$(PATH_S)test_hu.o: $(PATH_T)test_hu.c
	$(CC) $(CFLAGS) $(PATH_T)test_hu.c $(FLAG_PATH_OBJ)
$(PATH_S)test_hx.o: $(PATH_T)test_hx.c
	$(CC) $(CFLAGS) $(PATH_T)test_hx.c $(FLAG_PATH_OBJ)
$(PATH_S)test_hxx.o: $(PATH_T)test_hxx.c
	$(CC) $(CFLAGS) $(PATH_T)test_hxx.c $(FLAG_PATH_OBJ)
$(PATH_S)test_i.o: $(PATH_T)test_i.c
	$(CC) $(CFLAGS) $(PATH_T)test_i.c $(FLAG_PATH_OBJ)
$(PATH_S)test_ld.o: $(PATH_T)test_ld.c
	$(CC) $(CFLAGS) $(PATH_T)test_ld.c $(FLAG_PATH_OBJ)
$(PATH_S)test_Lf.o: $(PATH_T)test_Lf.c
	$(CC) $(CFLAGS) $(PATH_T)test_Lf.c $(FLAG_PATH_OBJ)
$(PATH_S)test_Lff.o: $(PATH_T)test_Lff.c
	$(CC) $(CFLAGS) $(PATH_T)test_Lff.c $(FLAG_PATH_OBJ)
$(PATH_S)test_li.o: $(PATH_T)test_li.c
	$(CC) $(CFLAGS) $(PATH_T)test_li.c $(FLAG_PATH_OBJ)
$(PATH_S)test_lld.o: $(PATH_T)test_lld.c
	$(CC) $(CFLAGS) $(PATH_T)test_lld.c $(FLAG_PATH_OBJ)
$(PATH_S)test_lli.o: $(PATH_T)test_lli.c
	$(CC) $(CFLAGS) $(PATH_T)test_lli.c $(FLAG_PATH_OBJ)
$(PATH_S)test_llo.o: $(PATH_T)test_llo.c
	$(CC) $(CFLAGS) $(PATH_T)test_llo.c $(FLAG_PATH_OBJ)
$(PATH_S)test_llu.o: $(PATH_T)test_llu.c
	$(CC) $(CFLAGS) $(PATH_T)test_llu.c $(FLAG_PATH_OBJ)
$(PATH_S)test_llx.o: $(PATH_T)test_llx.c
	$(CC) $(CFLAGS) $(PATH_T)test_llx.c $(FLAG_PATH_OBJ)
$(PATH_S)test_llxx.o: $(PATH_T)test_llxx.c
	$(CC) $(CFLAGS) $(PATH_T)test_llxx.c $(FLAG_PATH_OBJ)
$(PATH_S)test_lo.o: $(PATH_T)test_lo.c
	$(CC) $(CFLAGS) $(PATH_T)test_lo.c $(FLAG_PATH_OBJ)
$(PATH_S)test_longd.o: $(PATH_T)test_longd.c
	$(CC) $(CFLAGS) $(PATH_T)test_longd.c $(FLAG_PATH_OBJ)
$(PATH_S)test_lu.o: $(PATH_T)test_lu.c
	$(CC) $(CFLAGS) $(PATH_T)test_lu.c $(FLAG_PATH_OBJ)
$(PATH_S)test_lx.o: $(PATH_T)test_lx.c
	$(CC) $(CFLAGS) $(PATH_T)test_lx.c $(FLAG_PATH_OBJ)
$(PATH_S)test_lxx.o: $(PATH_T)test_lxx.c
	$(CC) $(CFLAGS) $(PATH_T)test_lxx.c $(FLAG_PATH_OBJ)
$(PATH_S)test_o.o: $(PATH_T)test_o.c
	$(CC) $(CFLAGS) $(PATH_T)test_o.c $(FLAG_PATH_OBJ)
$(PATH_S)test_p.o: $(PATH_T)test_p.c
	$(CC) $(CFLAGS) $(PATH_T)test_p.c $(FLAG_PATH_OBJ)
$(PATH_S)test_s.o: $(PATH_T)test_s.c
	$(CC) $(CFLAGS) $(PATH_T)test_s.c $(FLAG_PATH_OBJ)
$(PATH_S)test_s_small.o: $(PATH_T)test_s_small.c
	$(CC) $(CFLAGS) $(PATH_T)test_s_small.c $(FLAG_PATH_OBJ)
$(PATH_S)test_u.o: $(PATH_T)test_u.c
	$(CC) $(CFLAGS) $(PATH_T)test_u.c $(FLAG_PATH_OBJ)
$(PATH_S)test_x.o: $(PATH_T)test_x.c
	$(CC) $(CFLAGS) $(PATH_T)test_x.c $(FLAG_PATH_OBJ)
$(PATH_S)test_xx.o: $(PATH_T)test_xx.c
	$(CC) $(CFLAGS) $(PATH_T)test_xx.c $(FLAG_PATH_OBJ)
$(PATH_S)test__.o: $(PATH_T)test__.c
	$(CC) $(CFLAGS) $(PATH_T)test__.c $(FLAG_PATH_OBJ)
$(PATH_S)test_star.o: $(PATH_T)test_star.c
	$(CC) $(CFLAGS) $(PATH_T)test_star.c $(FLAG_PATH_OBJ)

clean:
	@rm -f $(PATH_TST)

fclean: clean
	@rm -f $(TSTNAME)

re: fclean all
