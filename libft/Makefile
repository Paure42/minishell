# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paure <paure@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 13:31:26 by paure             #+#    #+#              #
#    Updated: 2021/01/25 13:30:48 by paure            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c ft_putstr_fd.c \
		ft_strjoin.c ft_strtrim.c ft_isalnum.c ft_isprint.c ft_memcmp.c \
		ft_putchar_fd.c ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c \
		ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c \
		ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c \
		ft_isascii.c ft_memccpy.c ft_memmove.c ft_putnbr_fd.c \
		ft_strdup.c ft_strlen.c ft_strrchr.c ft_toupper.c \
		ft_countwords.c ft_countletters.c ft_cmpchar.c ft_strmapi.c \
		ft_countnumbers.c ft_strcmp.c ft_strcpy.c ft_double_array_sort.c \
		ft_strdup_double.c ft_strdel_double.c ft_splitstr.c \
		ft_strdel_xy.c ft_countline.c ft_realloc.c ft_realloc_2d.c \
		ft_getenv.c ft_isspace.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_trim_whitespaces.c ft_strdel.c \

NAME    = libft.a

CC      = gcc

HD      = libft.h

CFLAGS  = -Wall -Wextra -Werror

OBJS    = $(SRCS:.c=.o)

all:        ${NAME}


$(NAME):    ${OBJS}
			@ar rc ${NAME} ${OBJS}


clean:
	            @rm -f ${OBJS}

fclean:		clean
	            @rm -f  ${NAME}

re:         fclean all

.PHONY:     all clean fclean re
