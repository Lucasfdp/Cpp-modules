# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 05:38:34 by luferna3          #+#    #+#              #
#    Updated: 2026/01/27 06:26:46 by luferna3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==========================
# Project
# ==========================

NAME        = Fixed

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

# ==========================
# Files
# ==========================

SRCS        = main.cpp Fixed.cpp
OBJS        = $(SRCS:.cpp=.o)

# ==========================
# Rules
# ==========================

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@$(MAKE) banner

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# ==========================
# Banner
# ==========================
GREEN  = \033[0;32m
BLUE   = \033[0;34m
CYAN   = \033[0;36m
RESET  = \033[0m


banner:
	@printf "$(CYAN)\n"
	@printf " _____  _____  _____  _____  _____  _____  _____  _____  _____  _____ \n"
	@printf "/  ___>/   __\\/   __\\/  _  \\/   __\\/   __\\/  _  \\/   __\\/   __\\/  ___>\n"
	@printf "|___  ||   __||   __||   __/|   __||   __||   __/|   __||   __||___  |\n"
	@printf "<_____/\\_____/\\_____/\\__/   \\_____/\\_____/\\__/   \\_____/\\_____/_____/ \n"
	@printf "$(RESET)\n"




# ==========================
# Cleaning
# ==========================

clean:
	@rm -f $(OBJS)
	@printf "$(BLUE)\n"
	@printf "Cleansed"
	@printf "$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(BLUE)\n"
	@printf "More Cleansed"
	@printf "$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re banner
