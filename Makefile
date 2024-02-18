# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 17:11:11 by junhyeop          #+#    #+#              #
#    Updated: 2024/02/18 22:09:32 by junhyeop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SV = server
NAME_CL = client
NAME_SV_BONUS = server_bonus
NAME_CL_BONUS = client_bonus


SRC_DIR = ./src
BONUS_DIR = ./src_bonus

SRC_SV = $(SRC_DIR)/server.c 
SRC_CL = $(SRC_DIR)/client.c 
SRC_SV_BONUS = $(BONUS_DIR)/server_bonus.c 
SRC_CL_BONUS = $(BONUS_DIR)/client_bonus.c 

LIBDIR = ./libft/
LIBNAME = ft
LIB = $(LIBDIR)lib$(LIBNAME).a
INCDIRS = ./inc

OBJS_SV = $(SRC_SV:.c=.o)
OBJS_CL = $(SRC_CL:.c=.o)

OBJS_SV_BONUS = $(SRC_SV_BONUS:.c=.o)
OBJS_CL_BONUS = $(SRC_CL_BONUS:.c=.o)

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


$(NAME_BONUS): $(NAME_SV_BONUS) $(NAME_CL_BONUS)

$(NAME_SV_BONUS): $(LIB) $(OBJS_SV_BONUS)
		$(CC) -o $(NAME_SV_BONUS) $(OBJS_SV_BONUS) -L$(LIBDIR) -l$(LIBNAME)

$(NAME_CL_BONUS): $(LIB) $(OBJS_CL_BONUS)
		$(CC) -o $(NAME_CL_BONUS) $(OBJS_CL_BONUS) -L$(LIBDIR) -l$(LIBNAME)






$(LIB):
	$(MAKE) -C $(LIBDIR) all
	
clean:
	$(MAKE) -C $(LIBDIR) clean
	${RM} $(SRC_DIR)/*.o $(BONUS_DIR)/*.o

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	${RM} $(NAME_CL) $(NAME_SV) $(NAME_CL_BONUS) $(NAME_SV_BONUS)

re: fclean bonus

bonus: $(NAME) $(NAME_SV_BONUS) $(NAME_CL_BONUS)

.PHONY: all clean fclean re bonus