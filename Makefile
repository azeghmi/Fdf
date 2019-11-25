# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 22:08:10 by abrunet           #+#    #+#              #
#    Updated: 2019/08/13 16:31:21 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

NAME		= 	fdf

#######   DIRECTORIES   #######
HDR			=	.
LIBDIR		=	libft
SRCDIR		=	srcs
OBJDIR		=	obj
DIRS	=	$(patsubst $(SRCDIR)%, $(OBJDIR)%, $(shell find $(SRCDIR) -type d))

##########   FLAGS   ##########
CFLAGS		=	-Wall						\
				-Wextra						\
				-Werror						\
				-Wshadow					\
				-Wnull-dereference			\
				-pedantic					\
				-O3

EXECFLAGS	=	-I /usr/local/include		\
				-L /usr/local/lib -lmlx		\
				-framework OpenGL -framework AppKit	\

LIBFLAG		=	-L $(LIBDIR) -lft

#########   SOURCES   #########
LIBFT		=	$(LIBDIR)/libft.a

SRCS		=	$(shell find $(SRCDIR) -type f -name "*.c")

OBJS		=	$(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

#########   COLORS   ##########
STD			=	\033[0m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m

##########   RULES   ##########
all				: $(LIBFT) $(NAME)

$(NAME)			: $(OBJS)
	@printf "$(YELLOW)%-40s$(STD)" "Building executable $@ ..."
	@$(CC) $(CFLAGS) $(EXECFLAGS) -I . $(OBJS) -o $@ $(LIBFLAG)
	@echo "$(GREEN)DONE$(STD)"

$(LIBFT)		: $(LIBDIR)/libft.h
	@make -C $(LIBDIR)

$(OBJDIR)/%.o	: $(SRCDIR)/%.c
	@mkdir -p $(DIRS)
	@printf "%-40s" " > Compiling $* ..."
	@$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@
	@echo '✓'

clean			:
	@/bin/rm -rf $(OBJDIR)
	@make clean -C $(LIBDIR)

fclean			: clean
	@/bin/rm -rf $(NAME)
	@make fclean -C $(LIBDIR)

re				: fclean all

.PHONY			: all $(LIBFT) clean fclean re
