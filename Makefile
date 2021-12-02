# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paure <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 13:30:55 by paure             #+#    #+#              #
#    Updated: 2021/01/25 13:30:56 by paure            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc

SOURCES =	edit_env.c \
				free.c \
    		handler_cd.c \
    		handler_execve.c \
    		handler_unset.c \
    		utils.c \
    		handle_pipes.c \
    		handler_echo.c \
    		handler_exit.c \
    		handler_pwd.c \
    		main.c handle_quotes.c \
    		handler_env.c \
    		handler_export.c \
    		handler_signal.c \
            handle_redirect.c \
            utils2.c \
            format_command.c \
            handler_underscore.c \
            utils3.c \
    		minishell.c

GNL_SOURCES = get_next_line.c \
              get_next_line_utils.c

NAME = minishell

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = sources

DIR_GNL = gnl

HD = includes

HD_MINISHELL = ./includes/minishell.h

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

GNL_SRCS = $(addprefix $(DIR_GNL)/,$(GNL_SOURCES))

OBJS = $(addprefix $(DIR_S)/,$(SOURCES:.c=.o))

GNL_OBJS = $(addprefix $(DIR_GNL)/,$(GNL_SOURCES:.c=.o))

all: $(NAME) 

$(NAME): $(OBJS) $(GNL_OBJS) $(HD_MINISHELL)
	@make -C $(LIBFT)
	@$(CC) $(GNL_OBJS) $(OBJS) -I $(HD) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME)
	@echo "minishell executable ready !"

clean:
	@rm -f $(OBJS)
	@rm -f $(GNL_OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
