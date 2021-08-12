NAME 				= push_swap
LIBFT_NAME			= libft.a

HEADER				= include/push_swap.h

SRC_DIR				= source/
SRC 				= do_push.c main.c do_swap.c do_roll.c do_reverce_roll.c parse.c
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
