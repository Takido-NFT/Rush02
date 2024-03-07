EXEC = rush-02
FLAGS = -Wall -Wextra -Werror
PATH_SRC = ./srcs/
SRC = $(PATH_SRC)ft_putchar.c $(PATH_SRC)ft_putstr.c $(PATH_SRC)ft_atoi.c \
		$(PATH_SRC)ft_strlen.c $(PATH_SRC)ft_itoa.c $(PATH_SRC)ft_get_num_split.c \
			$(PATH_SRC)ft_split.c $(PATH_SRC)ft_strjoin.c $(PATH_SRC)lower_case.c $(PATH_SRC)is_numeric.c
OBJ = $(SRC:.c=.o)
CC = gcc

all: $(EXEC)

$(EXEC) : $(OBJ) 
	$(CC) -g $(FLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(EXEC)

.PHONY: all clean fclean