#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 17:12:23 by ssarkisi          #+#    #+#              #
#    Updated: 2017/11/08 17:12:25 by ssarkisi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

OBJ = ft_atoi.o\
		ft_atoin.o\
		ft_bzero.o\
		ft_isalnum.o\
		ft_isalpha.o\
		ft_isascii.o\
		ft_isdigit.o\
		ft_isprint.o\
		ft_itoa.o\
		ft_itoa_base.o\
		ft_lstadd.o\
		ft_lstdel.o\
		ft_lstdelone.o\
		ft_lstiter.o\
		ft_lstmap.o\
		ft_lstnew.o\
		ft_memalloc.o\
		ft_memccpy.o\
		ft_memchr.o\
		ft_memcmp.o\
		ft_memcpy.o\
		ft_memdel.o\
		ft_memmove.o\
		ft_memset.o\
		ft_mod.o\
		ft_putchar.o\
		ft_putchar_fd.o\
		ft_putendl.o\
		ft_putendl_fd.o\
		ft_putnstr.o\
		ft_putstr.o\
		ft_putstr_fd.o\
		ft_putstr_in_upper.o\
		ft_putnbr.o\
		ft_putnbr_fd.o\
		ft_strcat.o\
		ft_strchr.o\
		ft_strclr.o\
		ft_strcmp.o\
		ft_strcpy.o\
		ft_strdel.o\
		ft_strdup.o\
		ft_strequ.o\
		ft_striter.o\
		ft_striteri.o\
		ft_strlcat.o\
		ft_strlen.o\
		ft_strmap.o\
		ft_strmapi.o\
		ft_strncat.o\
		ft_strncmp.o\
		ft_strncpy.o\
		ft_strndup.o\
		ft_strnequ.o\
		ft_strnew.o\
		ft_strnstr.o\
		ft_strrchr.o\
		ft_strsplit.o\
		ft_strstr.o\
		ft_strsub.o\
		ft_strtrim.o\
		ft_tolower.o\
		ft_toupper.o\
		ft_strjoin.o\
		ft_numbercount.o\
		ft_notnumbercount.o\
		ft_onlytext.o\
		ft_onlynumber.o\
		ft_arrsize.o\
		ft_unicode.o\
		ft_sizeof_unicode.o\
		ft_counter.o\
		pf_find_flags.o\
		pf_find_width.o\
		pf_find_precision.o\
		pf_find_length.o\
		pf_find_type.o\
		pf_is_type.o\
		pf_to_struct.o\
		pf_add_0x.o\
		pf_add_to_start.o\
		pf_add_to_end_char.o\
		pf_add_to_end.o\
		pf_set_wight.o\
		pf_set_precision_num.o\
		pf_set_precision_str.o\
		pf_read_s.o\
		pf_read_p.o\
		pf_read_c.o\
		pf_read_di.o\
		pf_read_uox.o\
		pf_read_percent.o\
		pf_next_type.o\
		pf_del_struct.o\
		pf_next_type_pos.o\
		ft_printf.o\
		get_next_line.o

NAME = libft.a
INCLUDES = ../includes/libft.h ../includes/get_next_line.h
CFLAGS = -Wall -Werror -Wextra

%.o: %.c $(INCLUDES)
	gcc $(CFLAGS) -c $< -I ../includes

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
