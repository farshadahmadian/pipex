# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 12:28:02 by fahmadia          #+#    #+#              #
#    Updated: 2023/08/11 20:19:12 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = ./src

SRCS = pipex.c\
	handle_first_child_process.c\
	find_command_file.c\
	free.c\
	handle_second_child_process.c\
	error.c\
	exec.c\
	file.c\
	wait.c\

OBJS_DIR = ./objs

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

MY_LIB_PATH = ./my_lib

MY_LIB = $(MY_LIB_PATH)/libmylib.a

INCLUDE = -I./include -I./my_lib/ft_printf -I./my_lib/get_next_line -I./my_lib/libft

all: $(NAME)

$(NAME): $(OBJS) $(MY_LIB) Makefile
	$(CC) $(CFLAGS) $(OBJS) -lmylib -L$(MY_LIB_PATH) -o $(NAME) 

$(OBJS_DIR)/%.o: %.c Makefile
	mkdir -p $(OBJS_DIR)
	cc -c $(CFLAGS) $(INCLUDE) $< -o $@
	
$(MY_LIB):
	make -C $(MY_LIB_PATH)

clean:
	make clean -C $(MY_LIB_PATH)
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(MY_LIB_PATH)

re: fclean all

.PHONY: all clean fclean re
