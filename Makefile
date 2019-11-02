# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 23:01:31 by mobouzar          #+#    #+#              #
#    Updated: 2019/09/25 22:37:19 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = mobouzar.filler
OBJECTS = srcs/create_heat_map.o srcs/get_player_info.o srcs/get_position.o \
			srcs/trapping_enemy.o srcs/count_score.o srcs/main.o
LIBFT = libft/libft.a
all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
		@gcc $(FLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
		@echo "\033[0;32m-------------------------------------------------------------------------------\033[0m"
		@echo "\033[0;32m| >>>>>>>>>>>>>>>>>>>>>>>>>> Compiled Successfully <<<<<<<<<<<<<<<<<<<<<<<<<< |\033[0m"
		@echo "\033[0;32m-------------------------------------------------------------------------------\033[0m"

%.o : %.c
		@gcc $(FLAGS) -g -c $< -o $@
$(LIBFT):
		@make -C libft/
clean :
		@make clean -C libft/
		@rm -f $(OBJECTS)
		@echo "\033[1;33m-------------------------------------------------------------------------------\033[0m"
		@echo "\033[1;33m| >>>>>>>>>>>>>>>>>>>>>>>>>>  Cleaned Successfully <<<<<<<<<<<<<<<<<<<<<<<<<< |\033[0m"
		@echo "\033[1;33m-------------------------------------------------------------------------------\033[0m"

fclean : clean
		@rm -f $(NAME)
		@make fclean -C libft/

re : fclean all