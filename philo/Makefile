NAME = philo
SRC = SRCS/main.c \
      SRCS/param_handler.c \
      SRCS/utils1.c \
      SRCS/utils2.c \
      SRCS/utils3.c \
      SRCS/init.c \
      SRCS/init2.c \
      SRCS/philo_thread.c \
      SRCS/narator_thread.c \
      SRCS/thread_handler.c \
      SRCS/speaks.c \

PTHREAD = -pthread
CC = gcc #clang
INC = -I./thread.h
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -rf
OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC) $(PTHREAD)
all: $(NAME)
clean:
	@${RM} ${OBJ}
fclean: clean
	@${RM} ${SAVE}
	@${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
