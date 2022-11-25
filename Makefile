# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 13:05:09 by yoel-idr          #+#    #+#              #
#    Updated: 2022/11/21 12:00:46 by yoel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  := so_long
BNAME := so_long_bonus 

MSRC := ./src/map.c ./src/map_utils.c ./src/utils.c ./src/so_long.c ./src/main.c
BSRC := ./src/map_bonus.c ./src/map_utils_bonus.c ./src/utils_bonus.c ./src/so_long_bonus.c ./src/main_bonus.c

FLAG := -Wall -Wextra -Werror
LIBX := -lmlx -framework OpenGL -framework AppKit
RM   := rm -drf
CC   := cc

RED    := \033[1;31m
GREEN  := \033[1;32m
YELLOW := \033[1;33m
BLUE   := \033[1;34m
RESET  := \033[0m

all : $(NAME)
	 @echo "\n $(GREEN) YOU CAN USE SO_LONG \n$(RESET)"

$(NAME) : $(TOOLS) $(MSRC)
	      @$(MAKE) -C tools
		  @echo "\n COMPILING SOURCE FILES :  $(YELLOW) $(MSRC) \n\t\t\t    tools.a  ... $(RESET)"
		  @$(CC) $(FLAG) $(LIBX) $(MSRC) ./lib/tools.a  -o $(NAME)
	
bonus : $(BNAME)
		@echo "\n$(GREEN) YOU CAN USE SO_LONG \n $(RESET)"

$(BNAME) : $(TOOLS) $(BSRC)
		@$(MAKE) -C tools
		@echo "\n COMPILING SOURCE FILES :  $(YELLOW) $(BSRC) \n\t\t\t    tools.a  ... $(RESET)"
		@$(CC) $(FLAG) $(LIBX) $(BSRC) ./lib/tools.a  -o $(BNAME)

clean :
		@echo "$(GREEN)\n REMOVE OBJECT AND EXECUTABLE $(RESET)\n"
		@$(RM) ./tools/*.o $(NAME) $(BNAME)

fclean : clean
		@echo "$(GREEN) CLEANING DONE SUCCESSFULLY $(RESET)\n"
		@$(RM) lib

re 	   : fclean all
		@echo "\n$(BLUE) REALISE SUCCESSFULLY $(RESET)"
