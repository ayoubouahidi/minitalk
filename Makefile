# SRCC		= client.c help_fun_1.c
# SRCS		= server.c
# CC		= cc

# CFLAGS	= -Wall -Wextra -Werror -g
# NAME1	= client
# NAME2	= server
# L_CRT	= ar rcs
# OBJSC	= $(SRCC:.c=.o)

# MK		= make

# # Paths
# FT_PRINTF_DIR	= ./ft_printf
# FT_PRINTF_LIB	= $(FT_PRINTF_DIR)/libftprintf.a

# LIBFT_DIR = ./libft
# LIBFT_LIB = $(LIBFT_DIR)/libft.a

# # Rules
# all: $(NAME1) $(NAME2)

# $(NAME): $(OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB)
# 	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)

# $(FT_PRINTF_LIB):
# 	$(MK) -C $(FT_PRINTF_DIR)

# # $(LIBFT_LIB):
# # 	$(MK) -C $(LIBFT_DIR)

# clean:
# 	rm -f $(OBJS)
# 	$(MK) -C $(FT_PRINTF_DIR) clean
# 	$(MK) -C $(LIBFT_DIR) clean

# fclean: clean
# 	rm -f $(NAME)
# 	$(MK) -C $(FT_PRINTF_DIR) fclean
# 	$(MK) -C $(LIBFT_DIR) fclean

# re: fclean all

# .PHONY: all clean fclean re
