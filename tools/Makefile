# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 13:05:09 by yoel-idr          #+#    #+#              #
#    Updated: 2022/11/21 10:52:08 by yoel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tools.a

STOOL :=  ft_isdigit.c ft_strlen.c ft_putchar_fd.c ft_putnbr_fd.c ft_strchr.c ft_strrchr.c ft_strcmp.c \
			ft_strlcpy.c ft_strjoin.c ft_split.c ft_itoa.c get_next_line_utils.c get_next_line.c ft_putstr_fd.c\
			ft_memset.c ft_calloc.c ft_bzero.c \

GSRC := ./lib/tools.a ./src/map.c ./src/map_utils.c ./src/utils.c ./src/so_long.c ./src/main.c \

OBJS := $(STOOL:.c=.o)
SET	 := rm -drf ../lib && mkdir ../lib
FLAG := -Wall -Wextra -Werror

RED    := \033[1;31m
GREEN  := \033[1;32m
YELLOW := \033[1;33m
BLUE   := \033[1;34m
RESET  := \033[0m

all : $(NAME) 
	@mv $(NAME) ../lib

$(NAME) : $(OBJS)
	@$(SET) && ar -rc $(NAME) $^

.c.o :
		@echo " COMPILING SOURCE FILES :  $(YELLOW) $< ... $(RESET)"
		@cc $(FLAG) -c $< -o $@		

clean :
		@echo "$(YELLOW)\nCleaning done successfully$(RESET)"
		@$(RM) $(OBJS)

fclean : clean
		@echo "removinig all"
		@$(RM) $(NAME)
re 	   : fclean all
		@echo "realise"


