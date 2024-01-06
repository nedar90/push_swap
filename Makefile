# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 10:53:44 by nrajabia          #+#    #+#              #
#    Updated: 2023/04/03 10:53:47 by nrajabia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
BONUS		:= checker
CC			:= cc
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
PRINTF		:= ./ft_printf

HEADERS		:= -I ./$(PRINTF) -I ./include -I ./libft -I ./checker_src
LIBP		:= ./ft_printf/libftprintf.a
PS_SRC		:= ./push_swap_main/push_swap.c
PS_OBJC		:= ${PS_SRC:.c=.o}
SRCS		:= $(shell find ./source -iname "*.c")\
				$(shell find ./libft -iname "*.c")
OBJS		:= ${SRCS:.c=.o}
BONUS_SRC	:= $(shell find ./checker_src -iname "*.c")
BONUS_OBJ	:= ${BONUS_SRC:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\ "

$(NAME): $(PS_OBJC) $(OBJS)
	@$(CC) $(PS_OBJC) $(OBJS) $(LIBP) $(HEADERS) -o $(NAME)

$(BONUS): $(BONUS_OBJ) $(OBJS)
	@$(CC) $(BONUS_OBJ) $(OBJS) $(LIBP) $(HEADERS) -o $(BONUS)

all: $(NAME) $(BONUS)

bonus: $(BONUS)

clean:
	@rm -f $(OBJS) $(BONUS_OBJ) $(PS_OBJC)

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: clean all

.PHONY: all, clean, fclean, re
