# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 09:45:49 by lnicosia          #+#    #+#              #
#    Updated: 2021/05/11 11:52:33 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftasm.a

MAKEFILE = Makefile

LIB_DIR = lib
SRC_DIR = src
SRC_SIZE = $(shell ls src | grep .s | wc -l)
OBJ_DIR = obj
BIN_DIR = .
INCLUDES_DIR = includes
LIBFT_DIR = $(LIB_DIR)/libft
LIBMFT_DIR = $(LIB_DIR)/libmft
INSTALL_DIR = install
SED = sed
ROOT = sudo

#LIBS
LIBFT = $(LIBFT_DIR)/libft.a

### Linking flags ###
# Linking libgs
LDLIBS = 

LDFLAGS = 

LIB_RAW = 

SRC_RAW =	ft_strlen.s ft_puts.s ft_bzero.s ft_strcat.s ft_isalnum.s \
			ft_isalpha.s ft_isascii.s ft_isdigit.s ft_isprint.s \
			ft_tolower.s ft_toupper.s ft_memset.s ft_memcpy.s \
			ft_strdup.s ft_cat.s

HEADERS =	

#
# Creation of files path
#

SRC = $(addprefix $(SRC_DIR)/, $(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_RAW:.s=.o))

INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

RESOURCES =

OPTI_FLAGS = -O3

CFLAGS = -Wall -Wextra -Werror -Wpadded -Wconversion -I $(INCLUDES_DIR) \
	  	-I $(LIBFT_DIR)/includes -I $(BMP_PARSER_DIR)/includes \
		-I $(LIBMFT_DIR)/includes -I $(GLAD_DIR)/include \
		$(OPTI_FLAGS) \
		#-fsanitize=address -g3 \

ASMFLAGS = -g -f elf64 -F dwarf
		
	
#
# Setting right flags and files dependencies to link external libs
# according to user's os
#

ifeq ($(OS), Windows_NT)
else
	UNAME_S = $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
		OPTI_FLAGS += -flto
		SED = gsed
    else
		CFLAGS += -Wno-misleading-indentation
		OPTI_FLAGS += -flto
    endif
endif

#
# Color declarations
#

RED := "\e[0;31m"
GREEN := "\e[0;32m"
YELLOW := "\e[0;33m"
BLUE := "\e[0;34m"
MAGENTA := "\e[0;35m"
CYAN := "\e[0;36m"
RESET :="\e[0m"

#
# Rules
#

all:
	@printf $(CYAN)"[INFO] Building $(NAME)..\n"$(RESET)
	@make --no-print-directory $(BIN_DIR)/$(NAME)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

$(LIBMFT):
	@make --no-print-directory -C $(LIBMFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

I = 1
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s $(INCLUDES)
	@printf $(YELLOW)"[$(I)/$(SRC_SIZE)] Compiling $<\n"$(RESET)
	$(eval I=$(shell echo $$(($(I) + 1))))
	@nasm $< -o $@ $(ASMFLAGS) 

$(NAME): $(OBJ_DIR) $(OBJ) 
	@printf $(CYAN)"[INFO] Linking ${BIN_DIR}/${NAME}\n"$(YELLOW)
	ar rc -o $(NAME) $(OBJ) 
	ranlib $(NAME)
	@printf ${GREEN}"[INFO] Compiled $(BIN_DIR)/$(NAME) with success!\n"
	@printf ${RESET}

clean:
	@printf ${CYAN}"[INFO] Removing objs\n"${RESET}
	rm -rf $(OBJ_DIR)

fclean:
	@printf ${CYAN}"[INFO] Removing objs\n"${RESET}
	rm -rf $(OBJ_DIR)
	@printf ${CYAN}"[INFO] Removing $(BIN_DIR)/$(NAME)\n"$(RESET)
	rm -rf $(BIN_DIR)/$(NAME)

re: fclean all

.PHONY: fclean all clean libft
