# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 21:53:52 by jjuarez-          #+#    #+#              #
#    Updated: 2024/03/04 22:45:57 by javgao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror 
RM			= rm -rf
BUILTINS	= builtin.c ft_echo.c ft_cd.c ft_pwd.c ft_env.c #ft_export.c ft_unset.c ft_env.c ft_exit.c
INIT		= init.c
PARSER		= arry_chr.c arry_strs1.c arry_strs2.c parser.c
PIPEX		= pipex_bonus.c pipex_utils_bonus.c
SIGNALS		= signals.c
SOURCES		= src/main.c $(addprefix ./src/builtins/, $(BUILTINS)) $(addprefix ./src/init/, $(INIT)) \
			$(addprefix ./src/parser/, $(PARSER)) $(addprefix ./src/pipex/, $(PIPEX)) $(addprefix ./src/signals/, $(SIGNALS))
LIBFT		= Libft/libft.a
INCLUDE		= ./include/

OBJECTS		= $(SOURCES:.c=.o)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) $(LIBFT) -I $(INCLUDE) -o $(NAME)

$(LIBFT):
	make -C libft

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

all : $(NAME)

re: fclean all

.PHONY: all clean fclean re
