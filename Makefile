NAME		=	pipex

SRCS		= 	pipex.c \
				sources/init.c \
				sources/processes.c \
				sources/ft_freedom.c \
				utils/ft_putstr_fd.c \
				utils/ft_split.c \
				utils/ft_strdup.c \
				utils/ft_strjoin.c \
				utils/ft_strlen.c \
				utils/ft_strnstr.c \
				utils/strjoin_free.c \

OBJS		= 	${SRCS:.c=.o}

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror

INCLUDES	= 	includes/pipex.h

RM			= 	rm -rf

all: 			$(NAME)

$(NAME): 		$(OBJS)
				@${CC} ${OBJS} ${CFLAGS} -o ${NAME}

%.o : %.c 		${INCLUDES}
				${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o ${<:.c=.o}

clean:
				${RM} $(OBJS)

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re