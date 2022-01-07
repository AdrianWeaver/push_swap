NAME			=	push_swap

LIBFT			=	$(addprefix $(LIBFT_PATH), libft.a)

SCRS_PATH		=	./utils/

SRCS			=	$(addprefix $(SRCS_PATH), push_swap)

LIBFT_PATH		=	./libft/

LIBFT_SRCS		=	$(addprefix $(LIBFT_PATH),				\
					ft_isalpha.c							\
					ft_isdigit.c							\
					ft_isalnum.c							\
					ft_isascii.c							\
					ft_isprint.c							\
					ft_strlen.c								\
					ft_memset.c								\
					ft_bzero.c								\
					ft_memcpy.c								\
					ft_memmove.c							\
					ft_strlcpy.c							\
					ft_strlcat.c							\
					ft_toupper.c							\
					ft_tolower.c							\
					ft_strchr.c								\
					ft_strrchr.c							\
					ft_strncmp.c							\
					ft_memchr.c								\
					ft_memcmp.c								\
					ft_strnstr.c							\
					ft_atoi.c								\
					ft_calloc.c								\
					ft_strdup.c								\
					ft_substr.c								\
					ft_strjoin.c							\
					ft_strtrim.c							\
					ft_split.c								\
					ft_itoa.c								\
					ft_strmapi.c							\
					ft_striteri.c							\
					ft_putchar_fd.c							\
					ft_putstr_fd.c							\
					ft_putendl_fd.c							\
					ft_putnbr_fd.c							\
					ft_lstnew.c								\
					ft_lstadd_front.c						\
					ft_lstsize.c							\
					ft_lstlast.c							\
					ft_lstadd_back.c						\
					ft_lstdelone.c							\
					ft_lstclear.c							\
					ft_lstiter.c							\
					ft_lstmap.c)

OBJS			=	$(SRCS:.c=.o)

LIBFT_OBJS		=	$(LIBFT_SRCS:.c=.o)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

INC				=	./includes

DEP				=	$(OBJS:.o=.d)							\
					$(LIBFT_OBJS:.o=.d)

-include		$(DEP)

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $^

$(LIBFT):		$(LIBFT_OBJS)
				ar -rcs $(LIBFT) $^

%.o:			%.c
				$(CC) $(CFLAGS) -c $^ -o $@ -I $(INC)
				
clean:
				rm -f $(OBJS) $(LIBFT_OBJS)

fclean:			clean
				rm -f $(NAME) $(LIBFT)
				
re:				fclean all

test:			re
				$(CC) main.c $(NAME) -I $(INC) && ./a.out

.PHONY:			all re clean fclean test bonus rebonus
