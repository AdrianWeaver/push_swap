NAME					=	push_swap

#############################################################################
#																			#
#									COMPILER								#
#																			#
#############################################################################

CC		=		gcc
CFLAGS	=		-MMD -Wall -Wextra -Werror -g3
INC		=		-I ./includes/\
				-I $(LIBFT_INC)


#############################################################################
#																			#
#									FILES									#
#																			#
#############################################################################

SRCS	=	main.c
OBJS	=	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
DEPS	=	$(OBJS:.o=.d)
LIBFT	=	$(addprefix $(LIBFT_PATH), libft.a) 


#############################################################################
#																			#
#									PATHS									#
#																			#
#############################################################################

SRCS_PATH	=	./sources/
OBJS_PATH	=	./objects/
LIBFT_PATH	=	./libft/
LIBFT_INC	=	./libft/includes/

#############################################################################
#																			#
#									RULES									#
#																			#
#############################################################################

all:				$(NAME)

$(NAME):			$(OBJS) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT)

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.c
					@mkdir -p $(OBJS_PATH)
					$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBFT):
					@make -C $(LIBFT_PATH) --no-print-directory
clean:				
					@rm -rf $(OBJS_PATH)
					@echo "Objs cleaned!"

fclean:				clean
					rm -f $(NAME)

re:					fclean
					@make all --no-print-directory


test:
-include $(DEPS)
.PHONY:				all clean fclean re bonus test
