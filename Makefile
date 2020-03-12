
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeowth <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 19:32:29 by cmeowth           #+#    #+#              #
#    Updated: 2020/02/29 05:41:46 by cmeowth          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# General

NAME		= libftprintf.a
LIBNAME		= libft.a

# **************************************************************************** #
# GNU Compiler Collection

GCC			= /usr/bin/clang
WOPT		= -Wall -Wextra -Werror
OOPT		= -O2
IOPT		= -I $(INCDIR) -I $(LIBDIR)/include

# **************************************************************************** #
# System commands

AR			= /usr/bin/ar -rc
MAKE		= /usr/bin/make -C
RANLIB		= /usr/bin/ranlib
NORMINETTE	= /usr/bin/norminette
MKDIR		= /bin/mkdir -p
RM			= /bin/rm -rf

# **************************************************************************** #
# Directories of source and object files

LIBDIR		= ./libft
SRCDIR		= ./sources
OBJDIR		= ./objects
INCDIR		= ./includes

# **************************************************************************** #
# List of source files

PF_HEADER = includes/ft_printf.h

SRCNAME		= ft_printf.c				\
			  parsing.c					\
			  tools/buffer.c			\
			  tools/good_way_before.c	\
			  tools/initialization.c	\
			  tools/get_si.c			\
			  tools/get_ui.c			\
			  tools/get_f.c				\
			  specs/wildcard.c			\
			  specs/set_specs.c			\
			  specs/set_flags.c			\
			  specs/set_length.c		\
			  specs/apply_specs.c		\
			  types/type_b.c			\
			  types/type_c.c			\
			  types/type_d.c			\
			  types/type_f.c			\
			  types/type_f2.c			\
			  types/type_o.c			\
			  types/type_p.c			\
			  types/type_s.c			\
			  types/type_u.c			\
			  types/type_x.c			\
			  types/percent.c		    \
			  types/unknown.c			\

LFTOBJ =\
libft/objects/ft_abs.o \
libft/objects/ft_atoi.o \
libft/objects/ft_bzero.o \
libft/objects/ft_cntwords.o \
libft/objects/ft_ftoa_static.o \
libft/objects/ft_isalnum.o \
libft/objects/ft_isalpha.o \
libft/objects/ft_isascii.o \
libft/objects/ft_isdigit.o \
libft/objects/ft_islower.o \
libft/objects/ft_isprint.o \
libft/objects/ft_isseparator.o \
libft/objects/ft_isspace.o \
libft/objects/ft_isupper.o \
libft/objects/ft_iswhitespace.o \
libft/objects/ft_itoa.o \
libft/objects/ft_itoa_static.o \
libft/objects/ft_litoa.o \
libft/objects/ft_litoa_static.o \
libft/objects/ft_lstadd.o \
libft/objects/ft_lstdel.o \
libft/objects/ft_lstdelone.o \
libft/objects/ft_lstiter.o \
libft/objects/ft_lstmap.o \
libft/objects/ft_lstnew.o \
libft/objects/ft_memalloc.o \
libft/objects/ft_memccpy.o \
libft/objects/ft_memchr.o \
libft/objects/ft_memcmp.o \
libft/objects/ft_memcpy.o \
libft/objects/ft_memdel.o \
libft/objects/ft_memmove.o \
libft/objects/ft_memset.o \
libft/objects/ft_nblen.o \
libft/objects/ft_putchar.o \
libft/objects/ft_putchar_fd.o \
libft/objects/ft_putendl.o \
libft/objects/ft_putendl_fd.o \
libft/objects/ft_putnbr.o \
libft/objects/ft_putnbr_fd.o \
libft/objects/ft_putstr.o \
libft/objects/ft_putstr_fd.o \
libft/objects/ft_silen.o \
libft/objects/ft_sitoa_base.o \
libft/objects/ft_sitoa_base_static.o \
libft/objects/ft_strcat.o \
libft/objects/ft_strchr.o \
libft/objects/ft_strclr.o \
libft/objects/ft_strcmp.o \
libft/objects/ft_strcpy.o \
libft/objects/ft_strdel.o \
libft/objects/ft_strdup.o \
libft/objects/ft_strequ.o \
libft/objects/ft_strfrjoin.o \
libft/objects/ft_striter.o \
libft/objects/ft_striteri.o \
libft/objects/ft_strjoin.o \
libft/objects/ft_strlcat.o \
libft/objects/ft_strlen.o \
libft/objects/ft_strmap.o \
libft/objects/ft_strmapi.o \
libft/objects/ft_strncat.o \
libft/objects/ft_strncmp.o \
libft/objects/ft_strncpy.o \
libft/objects/ft_strnequ.o \
libft/objects/ft_strnew.o \
libft/objects/ft_strnew2d.o \
libft/objects/ft_strnstr.o \
libft/objects/ft_strrchr.o \
libft/objects/ft_strrev.o \
libft/objects/ft_strsplit.o \
libft/objects/ft_strstr.o \
libft/objects/ft_strsub.o \
libft/objects/ft_strtrim.o \
libft/objects/ft_swap.o \
libft/objects/ft_tolower.o \
libft/objects/ft_toupper.o \
libft/objects/ft_uilen.o \
libft/objects/ft_uitoa_base.o \
libft/objects/ft_uitoa_base_static.o \
libft/objects/ft_ulltoa.o

# **************************************************************************** #
# Automatic variables where are listed the names of sources and objects files

SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))
LFT			= $(addprefix $(LIBDIR)/, $(LIBNAME))
#LFTOBJ		= $(LIBDIR)/objects/*.o

# **************************************************************************** #
# Extra

CLEAR       = "\033[K"
EOC			= "\033[0;0m"
GREEN		= "\033[0;32m"
CR			= "\r"$(CLEAR)
BASENAME	= `basename $(PWD)`

# **************************************************************************** #
# Rules

all: $(NAME) $(LFT)

$(NAME): $(LFT) $(OBJ)
	$(AR) $(NAME) $(OBJ) $(LFTOBJ)
	$(RANLIB) $(NAME)
	printf $(CR)$(GREEN)"✓ $(NAME) is created\n"$(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(PF_HEADER)
	-@$(MKDIR) $(OBJDIR)/{types,tools,specs}
	$(GCC) $(WOPT) $(OOPT) $(IOPT) -c $< -o $@
	printf $(CR)"[ $(BASENAME)/%s ]"$(CLEAR) $@

$(LFT):
	$(MAKE) $(LIBDIR)

clean:
	$(RM) $(OBJ) $(OBJDIR)
	$(MAKE) $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) $(LIBDIR) fclean

re: fclean all

norm:
	$(NORMINETTE) $(SRCDIR) $(INCDIR) $(LIBDIR)/sources $(LIBDIR)/include

.PHONY: all clean fclean re norm
