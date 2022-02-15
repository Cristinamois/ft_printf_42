NAME	=	libftprintf.a

CFLAGS	=	-Wall -Werror -Wextra -c

CC		=	gcc

SRCS	=	ft_give_value_of_letter.c ft_printf.c \
			ft_treat_all_kinds_of_numbers.c ft_utils.c \

INCLUDES	=	ft_printf.h \

OBJS	=	$(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS) $(INCLUDES)
		@ar crs $@ $(OBJS)

%.o : %.c
		@$(CC) $(CFLAGS) $< -o $@

clean	:
		@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:		fclean all
