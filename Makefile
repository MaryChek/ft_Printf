NAME = libftprintf.a
LIBFTA = libft.a
SRCS = main1.c print_format.c ft_skip.c ft_parse.c
OBJ = $(SRCS:.c=.o)
LIBDIR = libft/
LIBNAME = libft/libft.a
#CFLAGS = -Wall -Wextra -Werror$(CFLAGS)
all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c  $< -o $@ 

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean
	@echo OBJECTS FILES HAS BEEN DELETED.

test:
	@gcc *.c -L libft -lft -o test

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo OBJECT FILES AND EXECUTABLE HAS BEEN DELETED.

re: fclean all
