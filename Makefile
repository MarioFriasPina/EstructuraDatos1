NAME = structures

FILE = *.c
CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FILE) $(CFLAG) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

.SILENT: clean fclean $(NAME)
re: fclean all
