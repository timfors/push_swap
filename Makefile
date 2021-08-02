NAME 				= push_swap
LIBFT_NAME			= libft.a

HEADER				= include/push_swap.c

SRC_DIR				= source/
SRC 				= 
OBJ_DIR				= objects/
OBJ 				= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR			= libft/
LIBFT				= $(LIBFT_DIR)$(LIBFT_NAME)

FLAGS 				= -Werror -Wall -Wextra
HEADER 				= push_swap.h


all : sub_dir $(LIBFT) $(NAME) 

sub_dir :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SOUCRE_DIR)%.c $(HEADER)
	gcc $(FLAGS) -c $<	-o $@  -I ./includes/

$(NAME) : $(OBJ) $(LIBFT)
	gcc $(FLAGS)  -o $@ $^ -I ./includes/

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.h ./includes/

fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm includes/libft.h
	rm $(NAME)

clean 
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

re : fclean all

.PHONY : all clean fclean re bonus sub_dir
