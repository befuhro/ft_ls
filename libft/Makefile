# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/16 13:27:01 by befuhro      #+#   ##    ##    #+#        #
#    Updated: 2018/12/15 19:03:03 by befuhro     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc

SRCS_PATH = src/
SRCS_NAME = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
	ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	ft_lstmap.c ft_memccpy.c ft_sort_int_tab.c ft_capitalize.c\
	ft_lstadd_at.c ft_lstdup.c ft_print_list.c
SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

OBJS_PATH = obj/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_PATH),$(OBJS_NAME))

HEADERS_PATH = include/
HEADERS_NAME = libft.h
HEADERS = $(addprefix $(HEADERS_PATH),$(HEADERS_NAME))
HEADERS_FLAGS = -include $(HEADERS)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj/
	$(CC) $(FLAGS) $(HEADERS_FLAGS) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJS_PATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
