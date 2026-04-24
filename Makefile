# =========================
# CONFIG
# =========================

MODULES = cpp00 cpp01 cpp02 cpp03 cpp04 cpp05 cpp06 cpp07 cpp08 cpp09

MAKEFLAGS += --no-print-directory

.PHONY: all clean fclean re run module status

# =========================
# INTERNAL HELPER
# =========================

define run_in_exercises
	for e in $$m/ex*; do \
		if [ -d $$e ]; then \
			echo "$(1) $$e"; \
			$(MAKE) -C $$e $(2); \
		fi; \
	done
endef

# =========================
# BASIC TARGETS
# =========================

all:
	@for m in $(MODULES); do \
		if [ -d $$m ]; then \
			$(call run_in_exercises,Building,); \
		fi; \
	done

clean:
	@for m in $(MODULES); do \
		if [ -d $$m ]; then \
			$(call run_in_exercises,Cleaning,clean); \
		fi; \
	done

fclean:
	@for m in $(MODULES); do \
		if [ -d $$m ]; then \
			$(call run_in_exercises,Fclean,fclean); \
		fi; \
	done

re: fclean all

# =========================
# EXTRA FUNCTIONALITY
# =========================

# Build + run specific exercise
# Usage: make run M=cpp00 E=ex01
run:
	@if [ -z "$(M)" ] || [ -z "$(E)" ]; then \
		echo "Usage: make run M=cppXX E=exXX"; \
	else \
		if [ ! -d "$(M)/$(E)" ]; then \
			echo "Path $(M)/$(E) not found"; \
			exit 1; \
		fi; \
		echo "Running $(M)/$(E)"; \
		$(MAKE) -C $(M)/$(E); \
		EXEC=$$(find $(M)/$(E) -maxdepth 1 -type f -perm -111 ! -name "*.o" ! -name "*.cpp" ! -name "*.hpp"); \
		if [ -z "$$EXEC" ]; then \
			echo "No executable found"; \
		else \
			$$EXEC; \
		fi; \
	fi

# Build a whole module
# Usage: make module M=cpp02
module:
	@if [ -z "$(M)" ]; then \
		echo "Usage: make module M=cppXX"; \
	else \
		if [ ! -d "$(M)" ]; then \
			echo "Module $(M) not found"; \
			exit 1; \
		fi; \
		for e in $(M)/ex*; do \
			if [ -d $$e ]; then \
				echo "Building $$e"; \
				$(MAKE) -C $$e; \
			fi; \
		done \
	fi

# Show build status
status:
	@for m in $(MODULES); do \
		if [ -d $$m ]; then \
			for e in $$m/ex*; do \
				if [ -d $$e ]; then \
					EXEC=$$(find $$e -maxdepth 1 -type f -perm -111 ! -name "*.o"); \
					if [ -n "$$EXEC" ]; then \
						echo "$$e ✅ built"; \
					else \
						echo "$$e ❌ not built"; \
					fi; \
				fi; \
			done \
		fi; \
	done