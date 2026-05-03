# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/30 03:38:33 by luferna3          #+#    #+#              #
#    Updated: 2026/05/01 07:23:19 by luferna3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==========================
# Project
# ==========================

NAME        = Account

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

# ==========================
# Files
# ==========================

SRCS        = tests.cpp Account.cpp
OBJS        = $(SRCS:.cpp=.o)
TOTAL       = $(words $(SRCS))
COMPILED    = 0

MAKEFLAGS   += --no-print-directory

# ==========================
# Colours
# ==========================

GREEN   = \033[0;32m
BLUE    = \033[0;34m
CYAN    = \033[0;36m
BOLD    = \033[1m
RESET   = \033[0m

# ==========================
# Rules
# ==========================

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "\n$(GREEN)$(BOLD)  [$(NAME) compiled successfully]$(RESET)\n"

%.o: %.cpp
	@$(eval COMPILED := $(shell echo $$(($(COMPILED) + 1))))
	@$(eval PCT := $(shell echo $$(($(COMPILED) * 100 / $(TOTAL)))))
	@$(eval FILLED := $(shell if [ $(COMPILED) -eq $(TOTAL) ]; then echo 20; else echo $$(($(COMPILED) * 20 / $(TOTAL))); fi))
	@$(eval EMPTY := $(shell echo $$(( 20 - $(FILLED)))))
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@bar=""; \
	i=0; while [ $$i -lt $(FILLED) ]; do bar="$$bar$(GREEN)█$(RESET)"; i=$$((i+1)); done; \
	i=0; while [ $$i -lt $(EMPTY) ]; do bar="$$bar░"; i=$$((i+1)); done; \
	printf "\r\033[K$(CYAN)  Compiling $(BOLD)%-25s$(RESET)$(CYAN) [$$bar$(CYAN)] $(BOLD)%3d%%$(RESET)" \
		"$<" "$(PCT)"

# ==========================
# Banner
# ==========================

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
	@printf "$(BLUE)  Cleansed$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(BLUE)  More Cleansed$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re banner