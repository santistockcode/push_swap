# **************************************************************************** #
#                              Master Makefile                                 #
# **************************************************************************** #

# List all sub-project folders
PROJECTS = ayogun hu8813 suspectedoceano mcombeau beatrizdile sisittu99 madebypixel02 raulmarcano gjmacias 42YerevanProjects

all:
	@for prj in $(PROJECTS); do \
		echo "=== Building $$prj ==="; \
		$(MAKE) -C examples/$$prj; \
	done

clean:
	@for prj in $(PROJECTS); do \
		$(MAKE) -C examples/$$prj clean; \
	done

fclean:
	@for prj in $(PROJECTS); do \
		$(MAKE) -C examples/$$prj fclean; \
	done

re: fclean all
