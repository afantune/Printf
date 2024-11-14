# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afantune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 10:28:26 by afantune          #+#    #+#              #
#    Updated: 2024/11/14 12:15:26 by afantune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_printf.c ft_format.c ft_putnbr.c ft_putnbr_base.c ft_putstr.c ft_putchar.c \
	ft_char_conversion.c ft_string_conversion.c ft_pointer_conversion.c \
	ft_int_conversion.c ft_unsigned_conversion.c ft_lowerhex_conversion.c \
	ft_upperhex_conversion.c ft_percent_conversion.c

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = @cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
AR = @ar
RM = @rm -f
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) rcs $(NAME) $(OBJS) $(LIBFT_DIR)/ft_putchar_fd.o

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
