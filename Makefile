# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 16:51:26 by russelenc         #+#    #+#              #
#    Updated: 2023/04/02 17:46:17 by russelenc        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
VIOLET	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m

#NAME
NAME = so_long

#DIR
SRC_DIR = src

 #src

SRC = ft_put_image.c so_long.c ft_check_file_format.c ft_check_map.c ft_check_map_utils.c \
		ft_get_map.c get_next_line.c get_next_line_utils.c ft_hook_key.c \
		ft_moov.c ft_check_path.c








#obj
SRCCO = $(SRCS:.c=.o)
CHECK_CO = $(CHECK_SRCS:.c=.o)

 #srcs
SRCS = $(addprefix $(SRC_DIR)/,$(SRC))


 #compil
CFLAGS =  -Wall -Werror -Wextra
CC = cc -g
GCC = gcc -g


all: $(NAME) 


$(NAME) : $(SRCCO)
	@echo "$(RED)____  ____       _     ____  _      _____\n/ ___\/  _ \     / \   /  _ \/ \  /|/  __/\n|    \| / \|     | |   | / \|| |\ ||| |  _\n\___ || \_/|     | |_/\| \_/|| | \||| |_//\n\____/\____/_____\____/\____/\_/  \|\____\\n"            \____\                        
	@echo "$(VIOLET)Building  so_long ..."
	@$(GCC) $(SRCCO) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(BLUE)so_long done."


	
%.o : %.c 
	@$(GCC)  -Imlx -c $< -o $@

clean: 
	rm -f $(SRCCO) 
	rm -f $(CHECK_CO) 

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECK_NAME)

re: fclean all

.PHONY: all clean fclean re