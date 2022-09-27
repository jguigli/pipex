SRC_M = srcs/pipex.c \
	srcs/utils.c \
	srcs/free.c \
	srcs/manage_pipex.c \
	srcs/error.c \
	func/ft_split.c \
	func/ft_strjoin.c \
	func/ft_strlen.c \
	func/ft_strncmp.c \
	func/ft_strtrim.c \
	func/ft_isalpha.c \
	func/ft_substr.c \
	func/ft_split_cmd_quote.c \


SRC_B = bonus/pipex_bonus.c \
	bonus/utils_bonus.c \
	bonus/utils2_bonus.c \
	bonus/free_bonus.c \
	bonus/manage_pipex_bonus.c \
	bonus/error_bonus.c \
	func/ft_split.c \
	func/ft_strjoin.c \
	func/ft_strlen.c \
	func/ft_strncmp.c \
	func/ft_strtrim.c \
	func/ft_isalpha.c \
	func/ft_substr.c \
	func/ft_split_cmd_quote.c \


HEADER			=	include/pipex.h
HEADER_BONUS	=	include/pipex_bonus.h

OBJECTS			= 	$(SRC_M:.c=.o)
OBJECTS_BONUS	=	$(SRC_B:.c=.o)

NAME			=	pipex
NAME_BONUS		=	pipex_bonus

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

.c.o:			$(HEADER) $(HEADER_BONUS)
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(NAME_BONUS):		$(OBJECTS_BONUS) $(HEADER_BONUS)
				$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $(NAME_BONUS)

clean:
				$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

bonus:			$(NAME_BONUS)

.PHONY:			all clean fclean re bonus