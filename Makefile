# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twagner <twagner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 15:32:48 by twagner           #+#    #+#              #
#    Updated: 2021/11/26 16:16:36 by twagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                               PARAMS & COLORS                                #
################################################################################
OS			=  $(shell uname -s)

ifneq (,$(findstring xterm,${TERM}))
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	BLUE         := $(shell tput -Txterm setaf 6)
	RESET		 := $(shell tput -Txterm sgr0)
else
	GREEN        := ""
	YELLOW       := ""
	BLUE         := ""
	RESET        := ""
endif

################################################################################
#                                 COMMANDS                                     #
################################################################################
RM			= rm -f
CC			= gcc
AR			= ar rcs

################################################################################
#                                 SOURCES                                      #
################################################################################
SRCS		= srcs/main.c \
			  srcs/parser/lexer/lexer.c \
			  srcs/parser/lexer/split_qu.c \
			  srcs/parser/lexer/split_qu2.c \
			  srcs/parser/lexer/replace_var.c \
			  srcs/parser/lexer/replace_var2.c \
			  srcs/parser/parser/table_utils.c \
			  srcs/parser/parser/stack_utils.c \
			  srcs/parser/parser/ast_utils.c \
			  srcs/parser/parser/ast_builder.c \
			  srcs/parser/parser/builder_utils.c \
			  srcs/parser/parser/parser.c \
			  srcs/interpreter/interpreter.c \
			  srcs/interpreter/exec_pipeline.c \
			  srcs/interpreter/exec_command.c \
			  srcs/interpreter/exec_simple_command.c \
			  srcs/interpreter/exec_comb_command.c \
			  srcs/interpreter/utils/arg_array_utils.c \
			  srcs/interpreter/utils/path_utils.c \
			  srcs/interpreter/utils/builtins_utils.c \
			  srcs/history/raw_mode.c \
			  srcs/history/readline.c \
			  srcs/history/utils/readline_handlers.c \
			  srcs/history/utils/readline_utils.c \
			  srcs/history/utils/readline_utils_2.c \
			  srcs/history/utils/history_utils.c \
			  srcs/builtins/cd.c \
			  srcs/builtins/echo.c \
			  srcs/builtins/env.c \
			  srcs/builtins/exit.c \
			  srcs/builtins/pwd.c \
			  srcs/builtins/export.c \
			  srcs/builtins/unset.c

OBJS		= $(SRCS:.c=.o)

################################################################################
#                           EXECUTABLES & LIBRARIES                            #
################################################################################
NAME		= minishell
LFT			= libft.a

################################################################################
#                                 DIRECTORIES                                  #
################################################################################
HEADERS		= includes/ 
LFTDIR		= libft/

################################################################################
#                                     FLAGS                                    #
################################################################################
CFLAGS		:= -Wall -Wextra -Werror
LFTFLAGS	:= -L. -lft
LADDFLAGS	:= -lreadline -ltermcap

ifeq ($(DEBUG), true)
	CFLAGS	+= -fsanitize=address -g3 -O0
endif

################################################################################
#                                    RULES                                     #
################################################################################
.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS) -I$(LFTDIR)

$(NAME):	$(LFT) $(OBJS)
			@printf  "$(BLUE)Creating $(RESET) $(YELLOW)[$(NAME)]$(RESET)" 
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS) $(LFTFLAGS) $(LADDFLAGS)
			@echo " : $(GREEN)OK !$(RESET)"

all:		$(NAME)

clean:
			@printf "$(BLUE)Cleaning $(RESET) $(YELLOW)[objects & libraries]$(RESET)"
			@$(RM) $(OBJS) $(LFT)
			@echo " : $(GREEN)OK !$(RESET)"

fclean:		clean
			@printf "$(BLUE)Cleaning $(RESET) $(YELLOW)[executable(s)]$(RESET)"
			@$(RM) $(NAME)
			@echo " : $(GREEN)OK !$(RESET)"

re:			fclean all

$(LFT):	
			@printf "$(BLUE)Compiling$(RESET) $(YELLOW)[$(LFT)]$(RESET)"
			@make -s -C $(LFTDIR)
			@make clean -s -C $(LFTDIR)
			@mv $(LFTDIR)$(LFT) .
			@echo " : $(GREEN)OK !$(RESET)"

.PHONY:		all clean fclean c.o re
