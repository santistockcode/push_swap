# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:50:16 by saalarco          #+#    #+#              #
#    Updated: 2025/04/09 18:27:03 by saalarco         ###   ########.fr        #
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
	src/valid_input_and_list.c \
	src/ft_split_ps.c \
	src/parse_validation/error_syntax.c \
	src/parse_validation/free_argv.c \
	src/print_list.c \
	src/parse_validation/ft_atol.c \
	src/parse_validation/error_duplicates.c \
	src/parse_validation/ft_join_spaces.c \
	src/operations/ft_swap.c \
	src/operations/sa.c \
	src/operations/sb.c \
	src/operations/ss.c \
	src/operations/pb.c \
	src/operations/ra.c \
	src/operations/rra.c \
	src/operations/pa.c \
	src/operations/rb.c \
	src/operations/rr.c \
	src/operations/rrb.c \
	src/operations/rrr.c \
	src/order.c \
	src/order_utils.c \
	src/order_few/order_three.c \
	src/order_few/order_five.c \
	src/order_few/push_min_to_b.c \
	src/turk/order_many.c

                         
OBJS        := $(SRCS:.c=.o)

###############################################################################
#                              TEST DIRECTORIES & FILES                       #
###############################################################################
TEST_DIR = tests

TEST_PAR_VAR_SRCS  	= $(TEST_DIR)/test_split_par_var.c \
	src/valid_input_and_list.c \
	src/ft_split_ps.c \
	src/parse_validation/error_syntax.c \
	src/parse_validation/free_argv.c \
	src/print_list.c \
	src/parse_validation/ft_atol.c \
	src/parse_validation/error_duplicates.c \
	src/parse_validation/ft_join_spaces.c


TEST_PAR_VAR_BIN     = $(TEST_DIR)/tests_par_var

TESTS_SPLIT_SRCS1	= $(TEST_DIR)/test_split_1.c \
	src/ft_split_ps.c \
	src/parse_validation/error_syntax.c \
	src/parse_validation/ft_atol.c \
	src/valid_input_and_list.c

TESTS_SPLIT_BIN1	= $(TEST_DIR)/test_split_1

TESTS_SPLIT_SRCS2	= $(TEST_DIR)/test_split_2.c \
	src/ft_split_ps.c \
	src/parse_validation/error_syntax.c \
	src/parse_validation/ft_atol.c \
	src/valid_input_and_list.c

TESTS_SPLIT_BIN2	= $(TEST_DIR)/test_split_2

TESTS_SPLIT_SRCS3	= $(TEST_DIR)/test_split_3.c \
	src/ft_split_ps.c \
	src/parse_validation/error_syntax.c \
	src/parse_validation/ft_atol.c \
	src/valid_input_and_list.c

TESTS_SPLIT_BIN3	= $(TEST_DIR)/test_split_3

TESTS_SPLIT_SRCS4	= $(TEST_DIR)/test_split_4.c \
	src/ft_split_ps.c \
	src/parse_validation/error_syntax.c \
	src/parse_validation/ft_atol.c \
	src/valid_input_and_list.c

TESTS_SPLIT_BIN4	= $(TEST_DIR)/test_split_4

TESTS_OPERATIONS_SRC	= $(TEST_DIR)/test_operations.c \
	src/print_list.c \
	src/operations/ft_swap.c \
	src/operations/sa.c \
	src/operations/sb.c \
	src/operations/ss.c \
	src/operations/pb.c \
	src/operations/ra.c \
	src/operations/rra.c \
	src/operations/pa.c \
	src/operations/rb.c \
	src/operations/rr.c \
	src/operations/rrb.c \
	src/operations/rrr.c

TESTS_OPERATIONS_BIN	= $(TEST_DIR)/test_operations

TESTS_ORDER_UTILS	= $(TEST_DIR)/test_order_utils.c \
	src/print_list.c \
	src/operations/sa.c \
	src/operations/ft_swap.c \
	src/operations/ra.c \
	src/order_utils.c 

TESTS_ORDER_UTILS_BIN	= $(TEST_DIR)/test_order_utils

TEST_ORDER = $(TEST_DIR)/test_order.c \
	src/print_list.c \
	src/operations/ft_swap.c \
	src/operations/sa.c \
	src/operations/sb.c \
	src/operations/ss.c \
	src/operations/pb.c \
	src/operations/ra.c \
	src/operations/rra.c \
	src/operations/pa.c \
	src/operations/rb.c \
	src/operations/rr.c \
	src/operations/rrb.c \
	src/operations/rrr.c \
	src/order.c \
	src/order_utils.c \
	src/order_few/order_three.c \
	src/order_few/order_five.c \
	src/order_few/push_min_to_b.c \
	src/turk/order_many.c

TEST_ORDER_BIN = $(TEST_DIR)/test_order

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
	@echo "$(GREEN)Tests fsanitize input parsing and validation module passed! $(CLR_RMV)"

tval_par_var: $(TEST_PAR_VAR_BIN) $(LIBFT_LIB)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TEST_PAR_VAR_SRCS) $(LIBS) -o $(TEST_PAR_VAR_BIN)
	@echo "$(YELLOW)Running valgrind input parsing and validation tests...$(CLR_RMV)"
	$(SILENT)@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			./$(TEST_PAR_VAR_BIN)
	@echo "$(GREEN)Tests valgrind input parsing and validation module ok or not! $(CLR_RMV)$(BLUE)...but you better check the output$(CLR_RMV)"

tests_split: $(LIBFT_LIB)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TESTS_SPLIT_SRCS1) $(LIBS) -o $(TESTS_SPLIT_BIN1)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TESTS_SPLIT_SRCS2) $(LIBS) -o $(TESTS_SPLIT_BIN2)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TESTS_SPLIT_SRCS3) $(LIBS) -o $(TESTS_SPLIT_BIN3)
	$(SILENT)$(CC) $(FLAGS) $(INCLUDES) $(TESTS_SPLIT_SRCS4) $(LIBS) -o $(TESTS_SPLIT_BIN4)
	$(SILENT)@echo "$(YELLOW)Running valgrind tests for ft_split_ps...$(CLR_RMV)"
	$(SILENT)@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			./$(TESTS_SPLIT_BIN1)
	$(SILENT)@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			./$(TESTS_SPLIT_BIN2)			
	$(SILENT)@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			./$(TESTS_SPLIT_BIN3)
	$(SILENT)@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			./$(TESTS_SPLIT_BIN4)
	@echo "$(GREEN)Tests valgrind ft_split_ps module ok (check above)! $(CLR_RMV)"


test_pv_lldb : $(TEST_PAR_VAR_BIN) $(LIBFT_LIB) 
	$(CC) $(FLAGS) -g $(INCLUDES) $(TEST_PAR_VAR_SRCS) $(LIBS) -o $(TEST_PAR_VAR_BIN)
	@echo "$(YELLOW)Running tests...$(CLR_RMV)"
	lldb ./$(TEST_PAR_VAR_BIN)

##
## 2) basic operations
##

test_op_fs: $(LIBFT_LIB)
	$(CC) $(FLAGS) -fsanitize=address $(INCLUDES) $(TESTS_OPERATIONS_SRC) $(LIBS) -o $(TESTS_OPERATIONS_BIN)
	./$(TESTS_OPERATIONS_BIN)

test_op_v: $(LIBFT_LIB)
	$(CC) $(FLAGS) $(INCLUDES) $(TESTS_OPERATIONS_SRC) $(LIBS) -o $(TESTS_OPERATIONS_BIN)
	@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			./$(TESTS_OPERATIONS_BIN)

test_op: $(LIBFT_LIB)
	$(CC) $(FLAGS) $(INCLUDES) $(TESTS_OPERATIONS_SRC) $(LIBS) -o $(TESTS_OPERATIONS_BIN)
	./$(TESTS_OPERATIONS_BIN)

##
## 2) order_utils
##

test_order_utils: $(LIBFT_LIB)
	$(CC) $(FLAGS) $(INCLUDES) $(TESTS_ORDER_UTILS) $(LIBS) -o $(TESTS_ORDER_UTILS_BIN)
	./$(TESTS_ORDER_UTILS_BIN)

test_order_utils_fs: $(LIBFT_LIB)
	$(CC) $(FLAGS) -fsanitize=address $(INCLUDES) $(TESTS_ORDER_UTILS) $(LIBS) -o $(TESTS_ORDER_UTILS_BIN)
	./$(TESTS_ORDER_UTILS_BIN)

test_order_utils_v: $(LIBFT_LIB)
	$(CC) $(FLAGS) $(INCLUDES) $(TESTS_ORDER_UTILS) $(LIBS) -o $(TESTS_ORDER_UTILS_BIN)
	@valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			./$(TESTS_ORDER_UTILS_BIN)


##
## 3) order
##

test_order: $(LIBFT_LIB)
	$(CC) $(FLAGS) $(INCLUDES) $(TEST_ORDER) $(LIBS) -o $(TEST_ORDER_BIN)
	./$(TEST_ORDER_BIN)

	

###############################################################################
#                              CI-LIKE PIPELINE                               #
###############################################################################

ci: fclean $(LIBFT_LIB) 
	
	# TODO: library libft directly from git

	@echo "$(BLUE)==> Module parsing and validation tests...$(CLR_RMV)"
	$(SILENT)$(MAKE) test_par_var

	@echo "==> Building main project..."
	$(SILENT)$(MAKE) all
	
	@echo "$(BLUE)==> Running valgrind test empty...$(CLR_RMV)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_integers/empty.log ./$(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_string/empty.log ./$(NAME) ""
	@echo "$(BLUE)==> Running valgrind as integers test OK...$(CLR_RMV)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_integers/12345.log ./$(NAME) 1 2 3 4 5
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_integers/1.log ./$(NAME) 1
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_integers/12.log ./$(NAME) 1 2
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_integers/123450.log ./$(NAME) 1 2 3 4 5 0
	@echo "$(BLUE)==> Running valgrind as integers test KO...$(CLR_RMV)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_integers/empty.log ./$(NAME) 11 1 1 1 1 1 11 11 1
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_integers/empty.log ./$(NAME) 1 2 3 4 4
	@echo "$(BLUE)==> Running valgrind as string test OK...$(CLR_RMV)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_string/12345.log ./$(NAME) "1 2 3 4 5"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_string/012345.log ./$(NAME) "0 1 2 3 4 5"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_string/123450.log ./$(NAME) "1 2 3 4 5 0"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_string/1.log ./$(NAME) "1"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_string/12.log ./$(NAME) "1 2"
	@echo "$(BLUE)==> Running valgrind as string test KO...$(CLR_RMV)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_string/12345.log ./$(NAME) "1 2 3 4 5 5"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_string/012345.log ./$(NAME) "0 0 1 2 3 4 5"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_string/123450.log ./$(NAME) "1 2 3 4 3 5 0"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_string/1.log ./$(NAME) "1 1"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/as_string/12.log ./$(NAME) "0 1 2 0"
	@echo "$(BLUE)==> Running valgrind limit cases test OK...$(CLR_RMV)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/limit_cases/1.log ./$(NAME) 2147483647
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/limit_cases/2.log ./$(NAME) -2147483648
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/limit_cases/3.log ./$(NAME) 2147483647 -2147483648
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/limit_cases/4.log ./$(NAME) -2147483648 2147483647
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/limit_cases/8.log ./$(NAME) "" 1
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/limit_cases/9.log ./$(NAME) 1 ""
	@echo "$(BLUE)==> Running valgrind limit cases test KO...$(CLR_RMV)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/limit_cases/5.log ./$(NAME) 2147483647 2147483647
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/limit_cases/6.log ./$(NAME) -2147483649 -2147483649
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/limit_cases/7.log ./$(NAME) 2147483648 0
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/limit_cases/10.log ./$(NAME) "" ""
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/limit_cases/11.log ./$(NAME) 1 2 tres 4 5
	@echo "$(BLUE)==> Running valgrind peer review OK...$(CLR_RMV)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/peer_suggest/1.log ./$(NAME) "" 1 "" 5 6 37 "42"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/peer_suggest/2.log ./$(NAME) "24" 1 2 4 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/peer_suggest/3.log ./$(NAME) 3 "1234 6"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/peer_suggest/4.log ./$(NAME) 3 "1234 6" 42 2 "1"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/peer_suggest/5.log ./$(NAME) "123456" 0
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/peer_suggest/6.log ./$(NAME) 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 "16"
	@echo "$(BLUE)==> Running valgrind peer review KO...$(CLR_RMV)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/peer_suggest/7.log ./$(NAME) "24 2 4" 2 4 2 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=tests/peer_suggest/8.log ./$(NAME) 364 3 "1234 6" 3 2

	@echo "$(RED)==> As integers:$(CLR_RMV)"
	$(SILENT)cat tests/as_integers/*.log | grep "ERROR SUMMARY:"
	@echo "$(RED)==> As strings:$(CLR_RMV)"
	$(SILENT)cat tests/as_string/*.log | grep "ERROR SUMMARY:"
	@echo "$(RED)==> Limit cases:$(CLR_RMV)"
	$(SILENT)cat tests/limit_cases/*.log | grep "ERROR SUMMARY:"
	@echo "$(RED)==> Peer review:$(CLR_RMV)"
	$(SILENT)cat tests/peer_suggest/*.log | grep "ERROR SUMMARY:"
	@echo "$(CLR_RMV)"

	@echo "$(GREEN)==> Frees and allocs:$(CLR_RMV)"

	@echo "$(GREEN)==> As integers:$(CLR_RMV)"
	$(SILENT)cat tests/as_integers/*.log | grep "All heap blocks we"
	@echo "$(GREEN)==> As strings:$(CLR_RMV)"
	$(SILENT)cat tests/as_string/*.log | grep "All heap blocks we"
	@echo "$(GREEN)==> Limit cases:$(CLR_RMV)"
	$(SILENT)cat tests/limit_cases/*.log | grep "All heap blocks we"
	@echo "$(GREEN)==> Peer review:$(CLR_RMV)"
	$(SILENT)cat tests/peer_suggest/*.log | grep "All heap blocks we"
	@echo "$(CLR_RMV)"

	@echo "==> Valgrind parsing and validation test completed!"

	@echo "$(BLUE)==> Running basic operations tests$(CLR_RMV)"
	$(SILENT)$(MAKE) test_op

	@echo "$(BLUE)==> Running basic operations tests with fsanitize$(CLR_RMV)"
	$(SILENT)$(MAKE) test_op_fs

	@echo "$(BLUE)==> Running basic operations tests with valgrind$(CLR_RMV)"
	$(SILENT)$(MAKE) test_op_v

	@echo "$(BLUE)==> Running checker by 42$(CLR_RMV)"
	$(SILENT)./checker.sh

	@echo "$(GREEN)==> CI-like pipeline complete!$(CLR_RMV)"


###############################################################################
#                              CLEAN RULES                                    #
###############################################################################

clean:
	@echo "$(RED)[Cleaning objects]$(CLR_RMV)"
	$(SILENT)rm -rf $(OBJS)
	$(SILENT)make -C $(LIBFT) clean
	$(SILENT)rm -rf $(TEST_PAR_VAR_BIN)
	$(SILENT)rm -rf $(TESTS_SPLIT_BIN1)
	$(SILENT)rm -rf $(TESTS_SPLIT_BIN2)
	$(SILENT)rm -rf $(TESTS_SPLIT_BIN3)
	$(SILENT)rm -rf $(TESTS_SPLIT_BIN4)
	$(SILENT)rm -rf $(TESTS_OPERATIONS_BIN)
	$(SILENT)rm -rf $(TESTS_ORDER_UTILS_BIN)
	$(SILENT)rm -rf $(TEST_ORDER_BIN)
	

	

fclean: clean
	@echo "$(RED)[Removing executables]$(CLR_RMV)"
	$(SILENT)make -C $(LIBFT) fclean
	$(SILENT)rm -rf $(NAME)

re: fclean all
