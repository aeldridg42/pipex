NAME		=	pipex

BNAME		=	pipex_bonus

SRCS		= 	pipex.c \
				sources/init.c \
				sources/processes.c \
				sources/ft_freedom.c \
				sources/ft_exit.c \
				utils/ft_putstr_fd.c \
				utils/ft_split.c \
				utils/ft_strdup.c \
				utils/ft_strjoin.c \
				utils/ft_strlen.c \
				utils/ft_strnstr.c \

BSRCS		=	bonus/pipex_bonus.c \
				bonus/init_bonus.c \
				bonus/processes_bonus.c \
				bonus/ft_freedom_bonus.c \
				bonus/ft_exit_bonus.c \
				utils/ft_putstr_fd.c \
				utils/ft_split.c \
				utils/ft_strdup.c \
				utils/ft_strjoin.c \
				utils/ft_strlen.c \
				utils/ft_strnstr.c \


OBJS		= 	${SRCS:.c=.o}

BOBJS		= 	${BSRCS:.c=.o}

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror

INCLUDES	= 	includes/pipex.h

RM			= 	rm -rf

all: 			$(NAME)

$(NAME): 		$(OBJS)
				@${CC} ${OBJS} ${CFLAGS} -o ${NAME}

%.o : %.c 		${INCLUDES}
				${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o ${<:.c=.o}

bonus:			$(BOBJS)
				@${CC} ${BOBJS} ${CFLAGS} -o ${BNAME}

clean:
				${RM} $(OBJS) $(BOBJS)

fclean:			clean
				${RM} ${NAME} ${BNAME}

re:				fclean all

.PHONY:			all clean fclean re bonus