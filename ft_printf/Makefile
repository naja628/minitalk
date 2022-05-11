FT_DIR=libft
SRC= ft_format_one.c ft_hexstr.c ft_printf.c printf_utils.c t_fspec.c t_sarg.c 
FT_SRC=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c \
	   ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
	   ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	   ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	   ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	   ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	   ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	   ft_tolower.c ft_toupper.c 
FT_OBJ=${FT_SRC:.c=.o}
OBJ=${SRC:.c=.o}
CFLAGS=-Wall -Wextra -Werror
CC=gcc
NAME=libftprintf.a

all: ${OBJ} ${addprefix $(FT_DIR)/, $(FT_OBJ)}
	ar rcs libftprintf.a $^

$(NAME): all
	@#empty

bonus: all
	@#empty

clean: 
	rm -rf ${OBJ} ${addprefix ${FT_DIR}/, ${FT_OBJ}}

fclean: clean
	rm -f libftprintf.a

re: fclean all
	@#empty

.PHONY: all re fclean clean bonus all
