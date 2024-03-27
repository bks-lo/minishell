# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 10:46:39 by dscriabi          #+#    #+#              #
#    Updated: 2022/03/07 17:10:11 by rponsonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

NC = \033[0m
RED = \033[0;91m
ORANGE = \033[93m
GREEN = \033[32m
PURPLE = \033[0;95m
BLUE = \033[0;34m
BOLD = \033[1m
CYAN = \033[36m

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c\
ft_toupper.c ft_flag_checks.c ft_flag_filter.c ft_flag_interpret.c ft_print_char.c\
ft_print_hexa.c ft_print_int.c ft_print_percent.c ft_print_pointer.c ft_print_str_precision.c\
ft_print_string.c ft_print_uint.c ft_print_width.c ft_printf.c ft_ptoa.c ft_utoa.c\
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_get_next_line_utils.c\
ft_get_next_line.c ft_isoutofintrange.c ft_stringcomp.c ft_strisnum.c \
ft_free_all_split.c ft_atof.c ft_strcmp.c ft_realloc.c ft_strcpy.c

OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

$(NAME):	${OBJS}
			@ar -rcs ${NAME} ${OBJS}
			@printf "${GREEN}[DONE]${NC}\n"

%.o: %.c
			@${CC} -c ${CFLAGS} -o $@ $<
			@printf "${GREEN}[ OK ] ${<:.s=.o}${NC}                \r"

all:		${NAME}

clean:
			@${RM} ${OBJS} ${BOBJS}

fclean:		clean
			@${RM} libft.a
			@printf "${GREEN}[ OK ]${NC}${RED} LIBFT.A DELETED\n"

re:			fclean all
