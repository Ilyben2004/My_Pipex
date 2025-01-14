NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c pipex_utils.c pipex_utils2.c ft_split.c pipex_utils3.c ft_check_command.c free_splited.c free_struct.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
