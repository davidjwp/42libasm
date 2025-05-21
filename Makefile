NASM = nasm
NFLAGS = -f elf64
CC = gcc
CFLAGS = -g3 -c

SFILS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s
NAME  = test
TFILS = test.c 
SOBJS = $(SFILS:.s=.o)
COBJS = $(TFILS:.c=.o)

$(NAME): $(SOBJS) $(COBJS)
	$(CC) -g $^ -o $@

%.o: %.s
	$(NASM) $(NFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(SOBJS) $(COBJS)

fclean: clean
	rm $(NAME)

re: clean $(NAME)