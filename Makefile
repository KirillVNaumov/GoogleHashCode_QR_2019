# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 22:08:06 by knaumov           #+#    #+#              #
#    Updated: 2019/02/25 13:28:26 by amelikia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES_EXEC = -I executable/includes
INCLUDES_CHECKER = -I checker/includes
INCLUDES_UTILS = -I utils

TESTS =		tests/a_example.txt 
			# tests/b_lovely_landscapes.txt 
			# tests/c_memorable_moments.txt 
			# tests/d_pet_pictures.txt 
			# tests/e_shiny_selfies.txt

OUTPUT = 	$(TESTS:%=%)

UTILS = 	utils/utils_1.cpp \
			utils/bools.cpp \
			utils/from_string_to_num.cpp \
			utils/printing/print_input.cpp \
			utils/printing/print_list.cpp \
			utils/printing/print_output.cpp \
			utils/printing/print_answer.cpp \
			utils/printing/print_horizontal_images.cpp \
			utils/printing/print_vertical_images.cpp \
			utils/printing/print_horizontal_slides.cpp \
			utils/printing/print_vertical_slides.cpp \
			utils/struct_operations/t_image.cpp \
			utils/struct_operations/t_slide.cpp 

SRCS_EXEC = executable/srcs/main.cpp \
			executable/srcs/create_output/create_output.cpp \
			executable/srcs/create_output/final_sort_slides.cpp \
			executable/srcs/create_possible_slides/create_possible_slides.cpp \
			executable/srcs/create_possible_slides/create_vertical_slides.cpp \
			executable/srcs/create_possible_slides/create_horizontal_slides.cpp \
			executable/srcs/reading_input/reading_input.cpp \
			executable/srcs/reading_input/read_images.cpp \
			executable/srcs/reading_input/read_number_of_images.cpp \
			executable/srcs/separate_vertical_and_horizontal/separate_vertical_and_horizontal.cpp \
			executable/srcs/separate_vertical_and_horizontal/initialize_horizontal_array.cpp \
			executable/srcs/separate_vertical_and_horizontal/initialize_vertical_array.cpp 

SRCS_CHECKER = \
			checker/srcs/main.cpp \
			checker/srcs/assess_output.cpp \
			checker/srcs/determine_tags.cpp \
			checker/srcs/check_output/check_verticals.cpp \
			checker/srcs/check_output/check_output_for_repetition.cpp \
			checker/srcs/reading_file/reading_file.cpp \
			checker/srcs/reading_file/read_images.cpp \
			checker/srcs/reading_file/read_number_of_images.cpp \
			checker/srcs/reading_output/reading_output.cpp \
			checker/srcs/reading_output/read_slides.cpp \
			checker/srcs/reading_output/read_number_of_slides.cpp

OBJ_EXEC	=	$(SRCS_EXEC:.cpp=.o)
OBJ_CHECKER	=	$(SRCS_CHECKER:.cpp=.o)
OBJ_UTILS	= 	$(UTILS:.cpp=.o)

EXEC = exe
CHECKER = check

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

%.o:%.cpp
			@echo "$(GREEN) - Creating $(GREEN_EXTRA)$<...$(RESET)"
			@clang++ -c $< -o $@ $(INCLUDES_EXEC) $(INCLUDES_CHECKER) $(INCLUDES_UTILS) -g

all: $(OBJ_UTILS) $(EXEC) $(CHECKER)

$(EXEC): $(OBJ_EXEC)
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC)$(RESET)"
	@clang++ -o $(EXEC) $(OBJ_EXEC) $(OBJ_UTILS) $(INCLUDES_EXEC) $(INCLUDES_UTILS) -g
	@echo "$(BLUE_EXTRA)$(EXEC)$(BLUE): Complete$(RESET)"

$(CHECKER): $(OBJ_CHECKER)
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(CHECKER)$(RESET)"
	@clang++ -o $(CHECKER) $(OBJ_CHECKER) $(OBJ_UTILS) $(INCLUDES_CHECKER) $(INCLUDES_UTILS) -g
	@echo "$(BLUE_EXTRA)$(CHECKER)$(BLUE): Complete$(RESET)"

clean:
	@if [ -a "executable/srcs/main.o" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -rf $(OBJ_EXEC); \
	fi
	@if [ -a "checker/srcs/main.o" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(CHECKER)$(RESET)"; \
	/bin/rm -rf $(OBJ_CHECKER); \
	fi
	@if [ -a "utils/struct_operations/t_image.o" ]; then \
	echo "$(RED)Deleting utils objects$(RESET)"; \
	/bin/rm -rf $(OBJ_UTILS); \
	fi
	@echo "$(BLUE_EXTRA)clean$(BLUE): Complete$(RESET)"

fclean: clean
	@if [ -a "$(EXEC)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -f $(EXEC); \
	fi
	@if [ -a "$(CHECKER)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(CHECKER)$(RESET)"; \
	/bin/rm -f $(CHECKER); \
	fi
	@echo "$(BLUE_EXTRA)fclean$(BLUE): Complete$(RESET)"

re: fclean all

%: %
	@echo "$(GREEN)Making output for $(GREEN_EXTRA)$<"
	@./exe < $< > $@.out

output: $(TESTS)

.PHONY: clean fclean re
