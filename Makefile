SRCC		= client.c help_fun_1.c help_fun_2.c 
SRCS		= server.c
CC		= cc

CFLAGS	= -Wall -Wextra -Werror
NAME1	= client
NAME2	= server
L_CRT	= ar rcs
OBJSC	= $(SRCC:.c=.o)
OBJSS = $(SRCS:.c=.o)
MK		= make

FT_PRINTF_DIR	= ./ft_printf
FT_PRINTF_LIB	= $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME1) $(NAME2)

$(NAME1) : $(OBJSC) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJSC) $(FT_PRINTF_LIB) -o $(NAME1) 

$(NAME2) : $(OBJSS) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJSS) $(FT_PRINTF_LIB) -o $(NAME2) 

$(FT_PRINTF_LIB):
	$(MK) -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJSS) $(OBJSC)
	$(MK) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME1) $(NAME2)
	$(MK) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
