CC = cc
AR = ar rc
FLAGS = -Wall -Wextra -Werror -g
INC = -I.
SRCS = ft_strcat.c is_white_space.c get_next_line.c get_next_line_utils.c ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c ft_isalpha.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c
OBJS = $(SRCS:.c=.o)
BONUS = ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c
OBONUS = $(BONUS:.c=.o)
NAME = libft.a

all: bonus

$(NAME): $(OBJS)
	@$(AR) $@ $^

%.o: %.c
	@$(CC) $(INC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBONUS)

bonus: $(OBJS) $(OBONUS)
	@$(AR) $(NAME) $^
fclean: clean
	@rm -f $(NAME) libft.so

re: fclean all

.PHONY: clean fclean all
