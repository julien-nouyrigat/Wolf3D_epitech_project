##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC := epiclang

CFLAGS = -Wall -Wextra -g

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
			src/window/init/init_host.c					\
			src/window/init/init_cursor.c				\
			src/window/sprite_sheet/background_menu.c	\
			src/window/menu.c							\
			src/window/draw_mouse.c						\
			src/window/host.c							\
			src/initialization/create_textures.c		\
			src/connect_to_server.c						\
			src/recv_rooms.c							\
			src/window/join_window/add_party.c			\
			src/window/lobby.c							\
			src/window/init/init_lobby.c				\

SRC_SERVER	=	Server/main.c							\
				Server/display_ip.c						\
				Server/init/init_server.c				\
				Server/init/init_tcp.c					\
				Server/init/init_rooms.c				\
				Server/init/init_epoll.c				\
				Server/loop_serv.c						\
				Server/broadcast.c						\
				Server/add_room.c						\
				Server/manage_client.c					\
				Server/send_rooms.c						\
				Server/free_lst.c						\


SRC_TESTS = tests/unit_tests.c 							\
			$(filter-out $(MAIN), $(SRC))

NAME = wolf3d

NAME_SERVER = server

OBJ_FOLDER = obj

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

OBJ_SERVER = $(patsubst %.c, obj/%.o, $(SRC_SERVER))

all : $(NAME) $(NAME_SERVER)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

$(NAME_SERVER) : $(OBJ_SERVER)
	$(CC) $(OBJ_SERVER) -o $(NAME_SERVER)

$(OBJ_FOLDER)/%.o: %.c
	@mkdir -p $(OBJ_FOLDER) $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean : RM += -R
clean :
	@$(RM) $(OBJ_FOLDER)

fclean : clean
	@$(RM) $(NAME) $(NAME_SERVER)

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
