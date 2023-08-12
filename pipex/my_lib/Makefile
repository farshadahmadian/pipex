# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 15:20:22 by fahmadia          #+#    #+#              #
#    Updated: 2023/07/09 16:53:55 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmylib.a
COPY_DEST = ./
OBJS = ./*.o

LIBFT_LIB = ./libft/libft.a
LIBFT = ./libft

LIBFTPRINTF_LIB = ./ft_printf/libftprintf.a
LIBFTPRINTF = ./ft_printf

GETNEXTLINE_LIB = ./get_next_line/getnextline.a
GETNEXTLINE = ./get_next_line

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(LIBFTPRINTF_LIB) $(GETNEXTLINE_LIB) extract

extract:
	cp $(LIBFT_LIB) $(COPY_DEST)
	cp $(LIBFTPRINTF_LIB) $(COPY_DEST)
	cp $(GETNEXTLINE_LIB) $(COPY_DEST)
	ar x ./libft.a
	ar x ./libftprintf.a
	ar x ./getnextline.a
	ar rcs $(NAME) *.o
	rm -f $(OBJS) "__.SYMDEF SORTED" ./libft.a ./libftprintf.a ./getnextline.a

$(LIBFT_LIB):
	make bonus -C $(LIBFT)

$(LIBFTPRINTF_LIB):
	make -C $(LIBFTPRINTF)

$(GETNEXTLINE_LIB):
	make -C $(GETNEXTLINE)

clean: 
	rm -f $(OBJS)
	make clean -C $(LIBFT)
	make clean -C $(LIBFTPRINTF)
	make clean -C $(GETNEXTLINE)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(LIBFTPRINTF)
	make fclean -C $(GETNEXTLINE)

re: 
	make fclean
	make $(NAME)

bonus: 

.PHONY: all clean fclean re
