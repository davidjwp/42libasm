NASM = nasm
NFLAGS = -f elf64
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(SRCS:.s=.o)
NAME = libasm.a
TEST = test
TEST_SRC = test.c

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.s
	$(NASM) $(NFLAGS) $< -o $@

test: $(NAME)
	$(CC) $(CFLAGS) $(TEST_SRC) -L. -lasm -o $(TEST)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re test