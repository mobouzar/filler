FLAGS = #-Wall -Werror -Wextra
NAME = visu
OBJECTS = main.o read_infos.o menu00.o menu01.o menu02.o \
			print_map00.o print_map01.o print_map02.o menu.o

LIBFT = ../libft/libft.a
NCURSES = -lncurses
all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
		@gcc $(FLAGS) $(NCURSES) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o : %.c
		@gcc $(FLAGS) -ggdb -c $<
$(LIBFT):
		@make -C ../libft/
clean :
		@make clean -C ../libft/
		@rm -f $(OBJECTS)

fclean : clean
		@rm -f $(NAME)
		@make fclean -C ../libft/

re : fclean all