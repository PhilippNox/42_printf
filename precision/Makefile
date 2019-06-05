# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 13:35:31 by wgorold           #+#    #+#              #
#    Updated: 2019/06/05 20:26:10 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# How 2 make this Makefile
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c//" \
# 	| while read x ; do echo "$x.o:\n\t\$(CC) \$(CFLAGS) $x.c" ; done
#
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c/\.o/" \
# 	| tr '\n' ' '
#

NAME=run_test

LIBNAME=libftprintf.a

CC=gcc

#FLAGS= -Wall -Wextra -Werror
FLAGS= -Wall -Wextra

CFLAGS= -c $(FLAGS)

SRC=	1_mat_precision_1.o 2_mat_precision_2.o ft_atoi.o ft_make_c.o \
			ft_make_d.o ft_make_p.o ft_make_s.o ft_printf.o ft_printf_helper.o \
			ft_printf_task.o ft_put.o ft_make_o.o ft_make_u.o ft_make_x.o \
			ft_make_xx.o

TST=	test_c_utf8.o test_d.o test_d_small.o test_i.o \
			test_p.o test_s.o test_s_small.o test_o.o test_u.o test_x.o test_xx.o \
			test_hhd.o test_hd.o test_ld.o test_lld.o

all: $(LIBNAME)

tst: $(NAME) clean
	sh ./z_check.sh

tstc: $(NAME) clean
	sh ./z_check.sh -d;
	@rm -f $(NAME) $(LIBNAME);

$(LIBNAME): $(SRC)
	ar rc $(LIBNAME) $(SRC)

$(NAME): $(SRC) $(TST)
	@$(CC) $(FLAGS) $(SRC) $(TST) test_run.c -o $(NAME)

1_mat_precision_1.o:
	$(CC) $(CFLAGS) 1_mat_precision_1.c
2_mat_precision_2.o:
	$(CC) $(CFLAGS) 2_mat_precision_2.c
ft_atoi.o:
	$(CC) $(CFLAGS) ft_atoi.c
ft_make_c.o:
	$(CC) $(CFLAGS) ft_make_c.c
ft_make_d.o:
	$(CC) $(CFLAGS) ft_make_d.c
ft_make_p.o:
	$(CC) $(CFLAGS) ft_make_p.c
ft_make_s.o:
	$(CC) $(CFLAGS) ft_make_s.c
ft_make_o.o:
	$(CC) $(CFLAGS) ft_make_o.c
ft_make_u.o:
	$(CC) $(CFLAGS) ft_make_u.c
ft_make_x.o:
	$(CC) $(CFLAGS) ft_make_x.c
ft_make_xx.o:
	$(CC) $(CFLAGS) ft_make_xx.c
ft_printf.o:
	$(CC) $(CFLAGS) ft_printf.c
ft_printf_helper.o:
	$(CC) $(CFLAGS) ft_printf_helper.c
ft_printf_task.o:
	$(CC) $(CFLAGS) ft_printf_task.c
ft_put.o:
	$(CC) $(CFLAGS) ft_put.c

test_c_utf8.o:
	$(CC) $(CFLAGS) test_c_utf8.c
test_d.o:
	$(CC) $(CFLAGS) test_d.c
test_d_small.o:
	$(CC) $(CFLAGS) test_d_small.c
test_i.o:
	$(CC) $(CFLAGS) test_i.c
test_p.o:
	$(CC) $(CFLAGS) test_p.c
test_s.o:
	$(CC) $(CFLAGS) test_s.c
test_s_small.o:
	$(CC) $(CFLAGS) test_s_small.c
test_o.o:
	$(CC) $(CFLAGS) test_o.c
test_u.o:
	$(CC) $(CFLAGS) test_u.c
test_x.o:
	$(CC) $(CFLAGS) test_x.c
test_xx.o:
	$(CC) $(CFLAGS) test_xx.c
test_hhd.o:
	$(CC) $(CFLAGS) test_hhd.c
test_hd.o:
	$(CC) $(CFLAGS) test_hd.c
test_ld.o:
	$(CC) $(CFLAGS) test_ld.c
test_lld.o:
	$(CC) $(CFLAGS) test_lld.c

clean:
	@rm -f $(SRC) $(TST)

fclean: clean
	@rm -f $(NAME) $(LIBNAME);

re: fclean all
