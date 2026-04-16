##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC := epiclang

CFLAGS = -Wall -Wextra

CPPFLAGS = -iquote./include

LIBS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

MAIN = 		src/main.c

SRC = 		$(MAIN)									\
			src/flag_h.c							\
			src/wolf.c								\
			src/destroy.c							\
			src/initialisation/init_window.c		\
			src/initialisation/init_player.c		\
			src/inputs/manage_keyboard.c			\
			src/player_movements/moove_forward.c	\
			src/player_movements/moove_backward.c	\
			src/player_movements/rotate_left.c		\
			src/player_movements/rotate_right.c		\
			src/2d_raycasting/draw_2d_player.c		\
			src/initialisation/init_map.c			\
			src/2d_raycasting/draw_2d_map.c			\
			src/initialisation/init_ray.c			\

SRC_TESTS = tests/unit_tests.c 						\
			$(filter-out $(MAIN), $(SRC))

NAME = wolf3d

OBJ_FOLDER = obj

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

$(OBJ_FOLDER)/%.o: %.c
	@mkdir -p $(OBJ_FOLDER) $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean : RM += -R
clean :
	@$(RM) $(OBJ_FOLDER)

fclean : clean
	@$(RM) $(NAME)

fclean_test :
	@$(RM) *.gcno
	@$(RM) *.gcda
	@$(RM) unit_tests

re : fclean all

ll : $(NAME) re fclean

debug : CFLAGS += -g3
debug : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

tests_run : CFLAGS += --coverage
			LIBS += -lcriterion -lgcov
tests_run : fclean fclean_test
	$(CC) -o unit_tests $(SRC_TESTS) $(CFLAGS) $(CPPFLAGS) $(LIBS)
	./unit_tests

.PHONY : fclean fclean_test re debug tests_run ll
