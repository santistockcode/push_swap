# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:50:16 by saalarco          #+#    #+#              #
#    Updated: 2025/03/10 19:34:57 by saalarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
#                              PROJECT SETTINGS                               #
###############################################################################

NAME		:= push_swap

# Compiler & Flags
CC		:= cc
FLAGS    	:= -g -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory

# Headers
HEADERS	= -I ./include

# Libraries
LIBFT		= ./libft
LIBFT_LIB  := $(LIBFT)/libft.a
LIBS	=  -lm ${LIBFT}/libft.a 

ifdef VERBOSE
    SILENT :=
else
    SILENT := @
endif

###############################################################################
#                              COLOR SETTINGS                                 #
###############################################################################

CLR_RMV   := \033[0m
RED       := \033[1;31m
GREEN     := \033[1;32m
YELLOW    := \033[1;33m
BLUE      := \033[1;34m
CYAN      := \033[1;36m
BPURPLE   := \033[1;35m

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS		= src/main.c \
	src/valid_input.c \
	src/ft_split_ps.c \
	src/parse_validation/error_syntax.c
                         
OBJS        := $(SRCS:.c=.o)

###############################################################################
#                              TEST DIRECTORIES & FILES                       #
###############################################################################
TEST_DIR = tests

TEST_PAR_VAR_SRCS  	= $(TEST_DIR)/test_split_par_var.c \
	src/ft_split_ps.c \
	src/parse_validation/error_syntax.c \
	src/parse_validation/ft_atol.c

TEST_PAR_VAR_BIN     = $(TEST_DIR)/tests_par_var

###############################################################################
#                              DEFAULT RULES                                  #
###############################################################################

.PHONY: all clean fclean re

all: $(NAME)

# Compile the main executable 
$(NAME): $(OBJS) $(LIBFT_LIB) 
	@echo "$(BLUE)[Linking]$(CLR_RMV) $@"
	$(SILENT)$(CC) $(FLAGS) $^ $(LIBS) $(HEADERS) -o $@

# Generic rule to build object files from .c
%.o: %.c
	@echo "$(GREEN)[Compiling]$(CLR_RMV) $<"
	$(SILENT)$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)

###############################################################################
#                              LIBRARIES                                      #
###############################################################################

$(LIBFT_LIB):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT)

###############################################################################
#                              TESTS                                          #
###############################################################################

##
## 1) input parsing and validation tests
##
test_par_var: $(TEST_PAR_VAR_BIN) $(LIBFT_LIB)
	@echo "$(YELLOW)Running input parsing and validation tests...$(CLR_RMV)"
	@./$(TEST_PAR_VAR_BIN)
	@echo "$(GREEN)Unit tests for parsing and validation module passed!$(CLR_RMV)"

$(TEST_PAR_VAR_BIN): $(TEST_PAR_VAR_SRCS)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TEST_PAR_VAR_SRCS) $(LIBS) -o $(TEST_PAR_VAR_BIN)

fsanitize_par_var: $(TEST_PAR_VAR_BIN) $(LIBFT_LIB)
	$(SILENT)$(CC) $(FLAGS) -fsanitize=address $(INCLUDES) $(TEST_PAR_VAR_SRCS) $(LIBS) -o $(TEST_PAR_VAR_BIN)
	@echo "$(YELLOW)Running fsanitize input parsing and validation tests...$(CLR_RMV)"
	$(SILENT)@./$(TEST_PAR_VAR_BIN)
	@echo "$(GREEN)Tests fsanitize input parsing and validation module passed! $(CLR_RMV)$(BLUE)...but you better check the output$(CLR_RMV)"

tval_par_var: $(TEST_PAR_VAR_BIN) $(LIBFT_LIB)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TEST_PAR_VAR_SRCS) $(LIBS) -o $(TEST_PAR_VAR_BIN)
	@echo "$(YELLOW)Running valgrind input parsing and validation tests...$(CLR_RMV)"
	$(SILENT)@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			./$(TEST_PAR_VAR_BIN)
	@echo "$(GREEN)Tests valgrind input parsing and validation module ok or not! $(CLR_RMV)$(BLUE)...but you better check the output$(CLR_RMV)"

test_pv_lldb : $(TEST_PAR_VAR_BIN) $(LIBFT_LIB) 
	$(CC) $(FLAGS) -g $(INCLUDES) $(TEST_PAR_VAR_SRCS) $(LIBS) -o $(TEST_PAR_VAR_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	lldb ./$(TEST_PAR_VAR_BIN)


###############################################################################
#                              CI-LIKE PIPELINE                               #
###############################################################################

ci: fclean $(LIBFT_LIB) 
	
	# TODO: library libft directly from git

	@echo "==> Module get_map tests..."
	$(SILENT)$(MAKE) test_get_map

	@echo "==> Building main project..."
	$(SILENT)$(MAKE) all

	@echo "$(GREEN)==> CI-like pipeline complete!$(CLR_RMV)"

###############################################################################
#                              CLEAN RULES                                    #
###############################################################################

clean:
	@echo "$(RED)[Cleaning objects]$(CLR_RMV)"
	$(SILENT)rm -rf $(OBJS)
	$(SILENT)make -C $(LIBFT) clean
	$(SILENT)rm -rf $(TEST_PAR_VAR_BIN)

fclean: clean
	@echo "$(RED)[Removing executables]$(CLR_RMV)"
	$(SILENT)make -C $(LIBFT) fclean
	$(SILENT)rm -rf $(NAME)

re: fclean all
