#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/26 13:47:36 by ssarkisi          #+#    #+#              #
#    Updated: 2017/11/26 13:47:41 by ssarkisi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ssarkisi.filler

OBJSRC = filler_algoritm.c\
		filler_check_side.c\
		filler_field.c\
		filler_malloc.c\
		filler_place.c\
		filler_set_chpos.c\
		filler_shape.c\
		filler_struct.c\
		filler.c\

OBJC = $(OBJSRC:%.c=srcs/%.c)
OBJO = $(OBJSRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIBDIR = libft

%.o: srcs/%.c
	gcc $(CFLAGS) -c $< -I includes

all: $(NAME)

$(NAME): $(OBJO)
	make -C $(LIBDIR)
	gcc $(CFLAGS) -o $(NAME) $(OBJO) -L./$(LIBDIR) -lft -I includes

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJO)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all
