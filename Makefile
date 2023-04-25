# Makefile

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS =  src/philo.c \
  		src/parsing/ft_atoi.c \
		src/lst_utils.c \
		src/ft_time.c 
		


		
OBJECT_FILES = $(SRCS:.c=.o)
HEADER = -I./includes

all: $(NAME)
.c.o:
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)
	@printf "$(YELLOW)Compiling $(NAME): << $< >>\033[K\r$(DEFAULT)"

$(NAME): $(OBJECT_FILES)
	@echo "\n"
	@$(CC) $(CFLAGS) $(HEADER) -o $(NAME) $(SRCS)
	@echo "$(GREEN)<<<<< $(NAME) exec file created >>>>>$(DEFAULT)"
#------------------------------------------------------------------------------
clean:
	@rm -rf $(OBJECT_FILES)
	@echo "$(GREEN)<<<<< $(NAME): Object Files Cleaned >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)<<<<< $(NAME): fclean done >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
re: fclean all
	@echo "$(GREEN)\n<<<<< $(NAME): make re done >>>>>$(DEFAULT)"
#------------------------------------------------------------------------------
#COLORS
RED = \033[3;31m
GREEN = \033[3;32m
YELLOW = \033[3;33m
DEFAULT = \033[0m
#------------------------------------------------------------------------------
#DEBUG
# -fsanitize=address
# valgrind --leak-check=full
