NASM = nasm
NFLAGS = -f elf64
CC = gcc
CFLAGS = -g3 -c

SFILS = ft_strlen.s ft_strcpy.s ft_strcmp.s
TFILS = test.c 
SOBJS = $(SFILS:.s=.o)
COBJS = $(TFILS:.c=.o)

test: $(SOBJS) $(COBJS)
	$(CC) -g $^ -o $@

%.o: %.s
	$(NASM) $(NFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(SOBJS) $(COBJS) test

re: clean test