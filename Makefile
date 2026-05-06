# =========================
# CONFIG
# =========================

MODULES = cpp00 cpp01 cpp02 cpp03 cpp04 cpp05 cpp06 cpp07 cpp08 cpp09

MAKEFLAGS += --no-print-directory

# =========================
# COLOURS
# =========================

GREEN   = \033[0;32m
BLUE    = \033[0;34m
CYAN    = \033[0;36m
YELLOW  = \033[0;33m
RED     = \033[0;31m
MAGENTA = \033[0;35m
BOLD    = \033[1m
RESET   = \033[0m

.PHONY: all clean fclean re run module status help banner push

# =========================
# INTERNAL HELPER
# =========================

define run_in_exercises
	for e in $$m/ex*; do \
		if [ -d $$e ]; then \
			$(MAKE) -C $$e $(2); \
		fi; \
	done
endef

# =========================
# BASIC TARGETS
# =========================

all: banner
	@total=0; built=0; \
	for m in $(MODULES); do \
		if [ -d $$m ]; then \
			for e in $$m/ex*; do \
				if [ -d $$e ]; then \
					total=$$((total + 1)); \
					bar=""; filled=0; empty=20; \
					printf "\r\033[K$(CYAN)  Building $(BOLD)%-20s$(RESET)$(CYAN) [%s] $(BOLD)%d%%$(RESET)" \
						"$$e" "$$(printf '░%.0s' $$(seq 1 20))" "0"; \
					$(MAKE) -C $$e 2>/dev/null; \
					built=$$((built + 1)); \
					pct=$$((built * 100 / total)); \
					filled=$$((built * 20 / total)); \
					if [ $$built -eq $$total ]; then filled=20; fi; \
					empty=$$((20 - filled)); \
					bar=""; \
					i=0; while [ $$i -lt $$filled ]; do bar="$$bar$(GREEN)█$(RESET)"; i=$$((i+1)); done; \
					i=0; while [ $$i -lt $$empty ]; do bar="$$bar░"; i=$$((i+1)); done; \
					printf "\r\033[K$(CYAN)  Building $(BOLD)%-20s$(RESET)$(CYAN) [$$bar$(CYAN)] $(BOLD)%d%%$(RESET)" \
						"$$e" "$$pct"; \
				fi; \
			done; \
		fi; \
	done; \
	printf "\n$(GREEN)$(BOLD)  [All modules compiled successfully]$(RESET)\n\n"

clean:
	@printf "$(BLUE)$(BOLD)\n  Cleaning objects...$(RESET)\n"
	@for m in $(MODULES); do \
		if [ -d $$m ]; then \
			for e in $$m/ex*; do \
				if [ -d $$e ]; then \
					$(MAKE) -C $$e clean 2>/dev/null; \
				fi; \
			done; \
		fi; \
	done
	@printf "$(BLUE)  Cleansed$(RESET)\n\n"

fclean:
	@printf "$(BLUE)$(BOLD)\n  Full clean...$(RESET)\n"
	@for m in $(MODULES); do \
		if [ -d $$m ]; then \
			for e in $$m/ex*; do \
				if [ -d $$e ]; then \
					$(MAKE) -C $$e fclean 2>/dev/null; \
				fi; \
			done; \
		fi; \
	done
	@printf "$(BLUE)  More Cleansed$(RESET)\n\n"

re: fclean all

# =========================
# EXTRA FUNCTIONALITY
# =========================

# Build + run specific exercise
# Usage: make run M=cpp00 E=ex01
run:
	@if [ -z "$(M)" ] || [ -z "$(E)" ]; then \
		printf "$(RED)  Usage: make run M=cppXX E=exXX$(RESET)\n"; \
	else \
		if [ ! -d "$(M)/$(E)" ]; then \
			printf "$(RED)  Path $(M)/$(E) not found$(RESET)\n"; \
			exit 1; \
		fi; \
		printf "$(CYAN)$(BOLD)\n  Building $(M)/$(E)...$(RESET)\n\n"; \
		$(MAKE) -C $(M)/$(E); \
		EXEC=$$(find $(M)/$(E) -maxdepth 1 -type f -perm -111 \
			! -name "*.o" ! -name "*.cpp" ! -name "*.hpp"); \
		if [ -z "$$EXEC" ]; then \
			printf "$(RED)  No executable found$(RESET)\n"; \
		else \
			printf "$(GREEN)$(BOLD)\n  Running $$EXEC$(RESET)\n\n"; \
			$$EXEC; \
		fi; \
	fi

# Build a whole module
# Usage: make module M=cpp02
module:
	@if [ -z "$(M)" ]; then \
		printf "$(RED)  Usage: make module M=cppXX$(RESET)\n"; \
	else \
		if [ ! -d "$(M)" ]; then \
			printf "$(RED)  Module $(M) not found$(RESET)\n"; \
			exit 1; \
		fi; \
		printf "$(CYAN)$(BOLD)\n  Building module $(M)...$(RESET)\n\n"; \
		total=0; built=0; \
		for e in $(M)/ex*; do \
			if [ -d $$e ]; then total=$$((total + 1)); fi; \
		done; \
		for e in $(M)/ex*; do \
			if [ -d $$e ]; then \
				$(MAKE) -C $$e 2>/dev/null; \
				built=$$((built + 1)); \
				pct=$$((built * 100 / total)); \
				filled=$$((built * 20 / total)); \
				if [ $$built -eq $$total ]; then filled=20; fi; \
				empty=$$((20 - filled)); \
				bar=""; \
				i=0; while [ $$i -lt $$filled ]; do bar="$$bar$(GREEN)█$(RESET)"; i=$$((i+1)); done; \
				i=0; while [ $$i -lt $$empty ]; do bar="$$bar░"; i=$$((i+1)); done; \
				printf "\r\033[K$(CYAN)  Building $(BOLD)%-20s$(RESET)$(CYAN) [$$bar$(CYAN)] $(BOLD)%d%%$(RESET)" \
					"$$e" "$$pct"; \
			fi; \
		done; \
		printf "\n$(GREEN)$(BOLD)  [$(M) compiled successfully]$(RESET)\n\n"; \
	fi

# Show build status of all exercises
status:
	@printf "$(CYAN)$(BOLD)\n  Build status:$(RESET)\n\n"
	@for m in $(MODULES); do \
		if [ -d $$m ]; then \
			printf "$(BOLD)  $(CYAN)$$m$(RESET)\n"; \
			for e in $$m/ex*; do \
				if [ -d $$e ]; then \
					EXEC=$$(find $$e -maxdepth 1 -type f -perm -111 \
						! -name "*.o" ! -name "*.cpp" ! -name "*.hpp"); \
					if [ -n "$$EXEC" ]; then \
						printf "    $(GREEN)✓$(RESET)  $$e\n"; \
					else \
						printf "    $(RED)✗$(RESET)  $$e\n"; \
					fi; \
				fi; \
			done; \
			printf "\n"; \
		fi; \
	done

# Count lines of code
cloc:
	@printf "$(CYAN)$(BOLD)\n  Lines of code per module:$(RESET)\n\n"
	@for m in $(MODULES); do \
		if [ -d $$m ]; then \
			total=$$(find $$m -name "*.cpp" -o -name "*.hpp" | xargs wc -l 2>/dev/null | tail -1 | awk '{print $$1}'); \
			printf "  $(GREEN)$$m$(RESET)  →  $(BOLD)$$total lines$(RESET)\n"; \
		fi; \
	done
	@printf "\n"

# Git add, commit and push
# Usage: make push M="your commit message"
push:
	@if [ -z "$(M)" ]; then \
		printf "$(RED)  Usage: make push M=\"your commit message\"$(RESET)\n"; \
	else \
		printf "$(CYAN)$(BOLD)\n  Pushing to remote...$(RESET)\n\n"; \
		git add . && \
		git commit -m "$(M)" && \
		git push && \
		printf "$(GREEN)$(BOLD)  [Pushed successfully]$(RESET)\n\n"; \
	fi

# Help
help:
	@printf "\n$(CYAN)$(BOLD)  cpp modules — available commands$(RESET)\n\n"
	@printf "  $(GREEN)make$(RESET)                         — build all modules\n"
	@printf "  $(GREEN)make re$(RESET)                      — clean and rebuild all\n"
	@printf "  $(GREEN)make clean$(RESET)                   — remove object files\n"
	@printf "  $(GREEN)make fclean$(RESET)                  — remove objects and binaries\n"
	@printf "  $(GREEN)make module M=cppXX$(RESET)          — build a specific module\n"
	@printf "  $(GREEN)make run M=cppXX E=exXX$(RESET)      — build and run a specific exercise\n"
	@printf "  $(GREEN)make status$(RESET)                  — show build status of all exercises\n"
	@printf "  $(GREEN)make cloc$(RESET)                    — count lines of code per module\n"
	@printf "  $(GREEN)make push M=\"msg\"$(RESET)          — git add, commit and push\n"
	@printf "  $(GREEN)make help$(RESET)                    — show this message\n\n"

# =========================
# BANNER
# =========================

banner:
	@printf "$(CYAN)$(BOLD)"
	@printf "\n"
	@sleep 0.05
	@printf "   ___ ___ ___   __  __         _        _\n"
	@sleep 0.1
	@printf "  / __| _ \\ _ \\ |  \\/  |___  __| |_  _  | |\n"
	@sleep 0.1
	@printf " | (__|  _/  _/ | |\\/| / _ \\/ _\` | || | |_|\n"
	@sleep 0.1
	@printf "  \\___|_| |_|   |_|  |_\\___/\\__,_|\\_, | (_)\n"
	@sleep 0.1
	@printf "                                   |__/\n"
	@printf "$(RESET)\n"