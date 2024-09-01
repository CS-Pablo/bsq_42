CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = bsq
SRCS = main.c ft_strdup.c ft_strlen.c ft_strjoin.c ft_atoi.c

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -o $@ $(SRCS)

.PHONY: all fclean re

fclean:
	-rm -f $(TARGET)

re: fclean all
