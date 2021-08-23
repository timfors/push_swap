NAME 				= push_swap
LIBFT_NAME			= libft.a

HEADER				= include/push_swap.h

SRC_DIR				= source/
SRC 				= parse.c main.c do_push.c do_swap.c do_roll.c do_reverce_roll.c string.c elem_main.c elem_get.c markup_index.c markup_value.c push_to_b.c elem_get_2.c push_to_a.c rotate.c
OBJ_DIR				= objects/
OBJ 				= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR			= libft/
LIBFT				= $(LIBFT_DIR)$(LIBFT_NAME)

FLAGS 				= -Werror -Wall -Wextra
HEADER 				= includes/push_swap.h


all : sub_dir $(LIBFT) $(NAME) 

sub_dir :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@  -I ./includes/

$(NAME) : $(OBJ) $(LIBFT)
	gcc $(FLAGS)  -o $@ $^ -I ./includes/

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.h ./includes/

fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm includes/libft.h
	rm $(NAME)

clean :
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

re : fclean all

.PHONY : all clean fclean re sub_dir
