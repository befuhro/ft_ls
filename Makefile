NAME = ft_ls

SRCS_PATH = srcs/
SRCS_NAME = main.c sort.c recursive.c
SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

OBJS_PATH =	objs/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_PATH),$(OBJS_NAME))

LIBFT_FLAGS = -L libft -lft
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

INC = -I include -I $(LIBFT_PATH)/include
INC_PATH = include $(LIBFT_PATH)/include

CC = clang
CFLAGS = -g -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(INC) $(LIBFT_FLAGS) $^ -o $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC_PATH)
	@mkdir -p objs
	$(CC) $(CFLAGS) $(INC)  -o $@ -c $<

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	rm -rf $(OBJS_PATH)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all
