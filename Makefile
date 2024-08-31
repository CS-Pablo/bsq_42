CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = bsq
SRCS = main.c ft_strdup.c ft_strlen.c ft_strjoin.c
OBJS = main.o ft_strdup.o ft_strlen.o ft_strjoin.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.c%.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean re
clean:
	-rm -f $(OBJS)

fclean:
	-rm -f $(TARGET) $(OBJS)

re: fclean all
