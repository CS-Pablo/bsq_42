CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = bsq
SRCS = main.c ft_strdup.c ft_strlen.c ft_strjoin.c ft_atoi.c
MAP_FILE = maps/map_$(shell date '+%F_%H-%M-%S')

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -o $@ $(SRCS)

.PHONY: all fclean re

fclean:
	-rm -f $(TARGET)

re: fclean all

run: all
	perl perl_map_generator.pl 25 25 10 > "$(MAP_FILE)"
	./bsq "$(MAP_FILE)"