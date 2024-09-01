CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = bsq
SRCS = main.c ft_strdup.c ft_strlen.c ft_strjoin.c ft_atoi.c

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -c $@ $(OBJS)

%.c%.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: all fclean re

fclean:
	-rm -f $(TARGET)

re: fclean all
