# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pde-bakk <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 13:45:00 by pde-bakk      #+#    #+#                  #
#    Updated: 2021/04/05 16:06:30 by pde-bakk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRC_DIR := srcs
BUILD_DIR := obj
SRC_EXT := c
OBJ_EXT := o
SOURCES := $(shell find $(SRC_DIR) -type f -name '*.$(SRC_EXT)')
OBJS    := $(SOURCES:.$(SRC_EXT)=.$(OBJ_EXT))
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(OBJS))

INCLUDE := -I include
HEADER :=$(shell find "include" -type f -name "*.h")

FLAGS := -Wall -Werror -Wextra
ifdef DEBUG
  FLAGS += -g -fsanitize=address
else
  FLAGS += -Ofast
endif

# COLORS
SHELL := /bin/bash
PINK = \x1b[35;01m
BLUE = \x1b[34;01m
YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
WHITE = \x1b[31;37m
RESET = \x1b[0m

all:
	$(MAKE) $(NAME) -j

$(NAME): directories $(OBJECTS)
	@printf "$(YELLOW)Linking libft.a...$(RESET)\n"
	@ar -rc $(NAME) $(OBJECTS)
	@printf "$(YELLOW)Done!$(RESET)\n"

directories:
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDE) -c $^ -o $@

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all -j

bonus: re
