CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libftget.a

SRCS =get_next_line_utils.c get_next_line.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re

.SILENT:
