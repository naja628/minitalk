# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najacque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 21:05:30 by najacque          #+#    #+#              #
#    Updated: 2021/10/12 21:05:53 by najacque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
   	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
   	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
   	ft_split.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strmapi.c \
   	ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c \
	ft_toupper.c ft_putstr_fd.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
	ft_strchr.c ft_strrchr.c
BONUS_SRC=ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
		  ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstadd_back.c
BONUS_OBJ=${BONUS_SRC:.c=.o} 
OBJ=${SRC:.c=.o}
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a

.c.o:
	gcc -c ${CFLAGS} $<

$(NAME):	${OBJ}
	ar rcs ${NAME} ${OBJ}

all:$(NAME) 

bonus:$(NAME) $(BONUS_OBJ)
	ar rcs ${NAME} ${BONUS_OBJ}

clean:
	rm -f ${OBJ}
	rm -f ${BONUS_OBJ}

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
