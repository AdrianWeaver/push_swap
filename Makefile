NAME					=	push_swap
NAME_BONUS				=	checker

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

MAIN_M	=	main.c
SRCS	=	ft_lst_functions.c		\
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

SRCS_BONUS = main_bonus.c
OBJS	=	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o) $(MAIN_M:.c=.o))
OBJS_NOMAIN = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
OBJS_BONUS	=	$(addprefix $(OBJS_B_PATH), $(SRCS_BONUS:.c=.o))
DEPS	=	$(OBJS:.o=.d)
LIBFT	=	$(addprefix $(LIBFT_PATH), libft.a) 
TOTAL	=	$(shell find ./sources -type f -name '*.c' | wc -l)
CURRENT =	$(shell find ./objects -type f -name '*.o' 2>/dev/null | wc -l | xargs expr 1 +)
TOTAL_B	=	$(shell find ./bonus -type f -name '*.c' | wc -l)
CURRENT_B =	$(shell find ./bonus_objects -type f -name '*.o' 2>/dev/null | wc -l | xargs expr 1 +)

#############################################################################
#																			#
#									PATHS									#
#																			#
#############################################################################

SRCS_PATH	=	./sources/
BONUS_PATH	=	./bonus/
OBJS_PATH	=	./objects/
OBJS_B_PATH	=	./bonus_objects/
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
					@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
					@sleep 0.1
					@echo -n "\33[2KBuilding object $(CURRENT)/$(TOTAL)\r"

$(OBJS_B_PATH)%.o:	$(BONUS_PATH)%.c
					@mkdir -p $(OBJS_B_PATH)
					@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
					@sleep 0.1

$(LIBFT):
					@make -C $(LIBFT_PATH) --no-print-directory

clean:				
					@rm -rf $(OBJS_PATH)
					@rm -rf $(OBJS_B_PATH)
					@echo "Objs cleaned!"

fclean:				clean
					@rm -f $(NAME)
					@rm -f $(NAME_BONUS)

re:					fclean
					@make all --no-print-directory

bonus:				$(NAME_BONUS)

$(NAME_BONUS):		$(OBJS_BONUS) $(NAME) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJS_NOMAIN) $(OBJS_BONUS) -o $@ $(LIBFT)
					@echo -n "\33[2KBuilding object $(CURRENT_B)/$(TOTAL_B)\r"
					@echo "\nLinking files for bonus only"

test:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Nombre d'opérations : "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Nombre d'opérations : "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Nombre d'opérations : "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Nombre d'opérations : "
					@./push_swap $(ARG) | wc -l

-include $(DEPS)
.PHONY:				all clean fclean re bonus test test5 test500
