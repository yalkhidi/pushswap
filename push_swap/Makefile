CC:= cc
CCFLAGS:= -Wall -Werror -Wextra
FILES:= \
		operations/swap.c \
		operations/push.c \
		operations/rotate.c \
		operations/reverse_rotate.c \
		stack/stack_ops.c \
		stack/stack_utils.c \
		utils/ft_split.c \
		utils/utils.c \
		arg_validation.c \
		input_handler.c \
		sort_three.c \
		main.c \
		sort.c \
		chunk.c \
		push_to_a.c
# MAIN:= main.c
FT_PRINTF_LIB:= ft_printf/libftprintf.a
BONUS:= 

HEADER:= push_swap.h
NAME:= push_swap.a

OFILES:= $(FILES:.c=.o)
OBONUS:= $(BONUS:.c=.o)

all: $(FT_PRINTF_LIB) $(NAME) push_swap

%.o: %.c $(HEADER)
	$(CC) $(CCFLAGS) -c $< -o $@

$(FT_PRINTF_LIB):
	make -C ft_printf

$(NAME): $(OFILES)
	ar -crs $(NAME) $(OFILES) 

bonus: $(OBONUS) 
	ar -crs $(NAME) $(OBONUS)
	
push_swap: $(NAME)
	$(CC) $(CCFLAGS) $(NAME) $(FT_PRINTF_LIB) -o push_swap

clean:
	make clean -C ft_printf
	rm -f $(OFILES) $(OBONUS)

fclean: clean
	make fclean -C ft_printf
	rm -f $(NAME) push_swap

re: fclean all

.PHONY: all clean fclean re