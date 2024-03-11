# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 21:53:52 by jjuarez-          #+#    #+#              #
#    Updated: 2024/03/11 04:02:52 by javgao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
BUILTINS	= builtin.c ft_echo.c ft_cd.c ft_pwd.c ft_export.c ft_unset.c ft_env.c ft_exit.c
INIT		= init.c loop.c
PARSER		= arry_chr1.c arry_chr2.c arry_strs1.c arry_strs2.c arry_utils.c parser.c arry_outfile.c arry_cmd.c expand.c arry_infile.c expand1.c arry_argss.c
PIPEX		= pipex_bonus.c pipex_utils_bonus.c
ERROR		= print_error.c
HASH		= hash_list.c hash_utils.c hash.c
EXECUTE		= execute.c single_command.c not_builtin.c multiple_commands.c
SIGNALS		= sig_func.c
FREE		= ft_free_four.c free_arr.c
UTILS		= ft_lower.c
SOURCES		= src/main.c $(addprefix ./src/builtins/, $(BUILTINS)) $(addprefix ./src/init/, $(INIT)) \
			$(addprefix ./src/parser/, $(PARSER)) $(addprefix ./src/pipex/, $(PIPEX)) $(addprefix ./src/signals/, $(SIGNALS)) \
			$(addprefix ./src/error/, $(ERROR)) $(addprefix ./src/hash/, $(HASH)) $(addprefix ./src/execute/, $(EXECUTE)) \
			$(addprefix ./src/free/, $(FREE)) $(addprefix ./src/utils/, $(UTILS))
			
LIBFT		= Libft/libft.a
INCLUDE		= ./include/

OBJECTS		= $(SOURCES:.c=.o)

DIR_READLINE ?= $(shell brew --prefix readline)
READLINE_LIB ?= -L$(DIR_READLINE)/lib -lreadline -lhistory
READLINE_INC ?= -I$(DIR_READLINE)/include

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(READLINE_LIB) $(READLINE_INC) -I $(INCLUDE) -o $(NAME)

$(LIBFT):
	make -C libft

%.o:%.c
	$(CC) $(CFLAGS) -c $< $(READLINE_INC) -I $(INCLUDE) -o $@ 

clean:
	$(RM) $(OBJECTS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

all : $(NAME)

re: fclean all

.PHONY: all clean fclean re
