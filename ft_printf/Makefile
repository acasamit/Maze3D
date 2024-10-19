CC = cc
AR = ar rc
FLAGS = -Wall -Wextra -Werror
INC = -I. -Ilibft
SRCS = ft_printf.c i_print.c u_print.c X_print.c c_print.c ft_putptr.c per_print.c s_print.c x_print.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $@ $(OBJS)

%.o: %.c
	@$(CC) $(INC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME) libft.so
	@rm -f libft.a

re: fclean all

.PHONY: clean fclean all
