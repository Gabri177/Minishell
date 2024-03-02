SRCS =
CFILE = $(addprefix ./srcs/, $(SRCS))
OFILE = $(CFILE:.c=.o)
INCLUDE = ./include
NAME = Minishell
CFLAG = -Wall -Werror -Wextra
CC = gcc

all:$(NAME)
$(NAME): $(OFILE)
	$(CC) $(CFLAG) $(OFILE) -I $(INCLUDE) -o $@
%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@
clean:
	$(RM) $(OFILE)
fclean:clean
	$(RM) $(NAME)
re:fclean all

.PHONY: re clean fclean