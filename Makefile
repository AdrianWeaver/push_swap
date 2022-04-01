NAME					=	push_swap

#############################################################################
#																			#
#									COMPILER								#
#																			#
#############################################################################

CC		=		gcc
CFLAGS	=		-MMD -Wall -Wextra -Werror -g3
INC		=		-I ./libft/includes\
				-I ./includes
				


#############################################################################
#																			#
#									FILES									#
#																			#
#############################################################################

SRCS	=	main.c					\
			ft_lst_functions.c		\
			ft_get_functions.c		\
			ft_push.c				\
			ft_swap.c				\
			ft_check_sort.c			\
			ft_sort_three.c			\
			ft_the_algo.c			\
			ft_the_algo_part_2.c	\
			ft_print_pile.c			\
			ft_rotate.c				\
			ft_reverse_rotate.c		\
			ft_get_pos.c
OBJS	=	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
DEPS	=	$(OBJS:.o=.d)
LIBFT	=	$(addprefix $(LIBFT_PATH), libft.a) 
TOTAL	=	$(shell find ./sources -type f -name '*.c' | wc -l)
CURRENT =	$(shell find ./objects -type f -name '*.o' 2>/dev/null | wc -l | xargs expr 1 +)


#############################################################################
#																			#
#									PATHS									#
#																			#
#############################################################################

SRCS_PATH	=	./sources/
OBJS_PATH	=	./objects/
LIBFT_PATH	=	./libft/


#############################################################################
#																			#
#									RULES									#
#																			#
#############################################################################

all:				$(NAME)

$(NAME):			$(OBJS) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT)
					@echo "\nLinking files"

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.c
					@mkdir -p $(OBJS_PATH)
					$(CC) $(CFLAGS) -c $< -o $@ $(INC)
					@sleep 0.1
					@echo -n "\33[2KBuilding object $(CURRENT)/$(TOTAL)\r"

$(LIBFT):
					@make -C $(LIBFT_PATH) --no-print-directory

clean:				
					@rm -rf $(OBJS_PATH)
					@echo "Objs cleaned!"

fclean:				clean
					rm -f $(NAME)

re:					fclean
					@make all --no-print-directory


test:				$(NAME)	
					./push_swap 2 44 66 102 -1 38

-include $(DEPS)
.PHONY:				all clean fclean re bonus test
