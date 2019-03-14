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

INCLUDES = -I includes

SRCS = 	srcs/main.cpp \
		srcs/reading_input/reading_input.cpp \
		srcs/reading_input/read_images.cpp \
		srcs/reading_input/read_number_of_images.cpp \
		srcs/utils/struct_operations/t_image.cpp \
		srcs/utils/struct_operations/t_slide.cpp 

OBJ		=	$(SRCS:.cpp=.o)

EXEC = GHash

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

%.o:%.cpp
			@echo "$(GREEN) - Creating $(GREEN_EXTRA)$<...$(RESET)"
			@clang++ -c $< -o $@ $(INCLUDES) -g

all: $(EXEC)

$(EXEC): $(OBJ)
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC)$(RESET)"
	@clang++ -o $(EXEC) $(OBJ) $(INCLUDE) -g
	@echo "$(BLUE_EXTRA)$(EXEC)$(BLUE): Complete$(RESET)"

clean:
	@if [ -a "srcs/main.o" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -rf $(OBJ); \
	fi
	@echo "$(BLUE_EXTRA)clean$(BLUE): Complete$(RESET)"

fclean: clean
	@if [ -a "$(EXEC)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -f $(EXEC); \
	fi
	@echo "$(BLUE_EXTRA)fclean$(BLUE): Complete$(RESET)"

re: fclean all

.PHONY: clean fclean re
