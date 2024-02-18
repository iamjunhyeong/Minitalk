# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 17:11:11 by junhyeop          #+#    #+#              #
#    Updated: 2024/02/18 21:06:15 by junhyeop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SV = server
NAME_CL = client
# NAME_BONUS = so_long_bonus



SRC_DIR = ./
# BONUS_DIR = ./src_bonus

SRC_SV = server.c utils.c 
SRC_CL = client.c utils.c 


LIBDIR = ./libft/
LIBNAME = ft
LIB = $(LIBDIR)lib$(LIBNAME).a
INCDIRS = ./

OBJS_SV = $(SRC_SV:.c=.o)
OBJS_CL = $(SRC_CL:.c=.o)

# OBJS_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
MAKE = make
RM = rm -f
CFLAGS = -Wall -Wextra -Werror $(foreach D, $(INCDIRS), -I$(D))
ARFLAGS = rs

all: $(NAME_SV) $(NAME_CL)

%.o: %.c $(foreach D, $(INCDIRS), $(D)*.h)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(NAME_SV) $(NAME_CL)

$(NAME_SV): $(LIB) $(OBJS_SV)
		$(CC) -o $(NAME_SV) $(OBJS_SV) -L$(LIBDIR) -l$(LIBNAME)

$(NAME_CL): $(LIB) $(OBJS_CL)
		$(CC) -o $(NAME_CL) $(OBJS_CL) -L$(LIBDIR) -l$(LIBNAME)

# $(NAME_BONUS): $(NAME) $(OBJS_BONUS)
# 	$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBDIR) -l$(LIBNAME)

$(LIB):
	$(MAKE) -C $(LIBDIR) all
	
clean:
	$(MAKE) -C $(LIBDIR) clean
	${RM} $(SRC_DIR)/*.o

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	${RM} $(NAME_CL) $(NAME_SV)

re: fclean bonus

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus