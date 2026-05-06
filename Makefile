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

SRC = 		$(MAIN)										\
			src/flag_h.c								\
			src/wolf.c									\
			src/destroy.c								\
        	src/generating/parsing_map.c 				\
			src/generating/parsing_door.c 				\
			src/generating/generating.c 				\
			src/generating/create_map.c 				\
			src/generating/free_tools.c 				\
			lib/str_to_wa.c 							\
			lib/free_array.c							\
			lib/my_itoa.c								\
			src/initialization/init_window.c			\
			src/initialization/init_player.c			\
			src/events/inputs/manage_keyboard.c			\
			src/events/window_events/window_evts.c		\
			src/player_movements/movements.c			\
			src/player_movements/rotation.c				\
			src/raycasting/draw_2d_player.c				\
			src/initialization/init_map.c				\
			src/raycasting/draw_2d_map.c				\
			src/raycasting/algorithm.c					\
			src/raycasting/draw_wall.c					\
			src/window/init/init_menu.c					\
			src/window/init/init_cursor.c				\
			src/window/init/init_lamp.c					\
			src/window/sprite_sheet/background_menu.c	\
			src/window/menu.c							\
			src/window/draw_mouse.c						\
			src/window/draw_lamp.c						\
			src/initialization/create_textures.c		\
			src/raycasting/draw_floor.c					\
			src/hud/create_hud.c						\
			src/hud/display_hud.c						\

SRC_SERV =	Server/main.c								\
			Server/init_tcp.c							\
			Server/init_epoll.c							\
			Server/get_ip.c								\
			Server/server_loop.c						\
			Server/manage_stdin.c						\
			Server/manage_client.c						\

SRC_TESTS = tests/unit_tests.c 							\
			$(filter-out $(MAIN), $(SRC))

NAME = wolf3d

NAME_SERV = server

OBJ_FOLDER = obj

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

OBJ_SERV = $(patsubst %.c, obj/%.o, $(SRC_SERV))

all : $(NAME) $(NAME_SERV)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

$(NAME_SERV) : $(OBJ_SERV)
	$(CC) $(OBJ_SERV) -o $(NAME_SERV)

$(OBJ_FOLDER)/%.o: %.c
	@mkdir -p $(OBJ_FOLDER) $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean : RM += -R
clean :
	@$(RM) $(OBJ_FOLDER) $(OBJ_SERV)

fclean : clean
	@$(RM) $(NAME) $(NAME_SERV)

fclean_test :
	@$(RM) *.gcno
	@$(RM) *.gcda
	@$(RM) unit_tests

re : fclean all

ll : $(NAME) re fclean

debug : CFLAGS += -g3
debug : clean $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

tests_run : CFLAGS += --coverage
			LIBS += -lcriterion -lgcov
tests_run : fclean fclean_test
	$(CC) -o unit_tests $(SRC_TESTS) $(CFLAGS) $(CPPFLAGS) $(LIBS)
	./unit_tests

.PHONY : fclean fclean_test re debug tests_run ll
