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
			src/manage_client.c							\
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
			src/window/init/init_param.c				\
			src/window/init/init_lamp.c					\
			src/window/init/init_audio.c				\
			src/window/param.c							\
			src/window/sprite_sheet/background_menu.c	\
			src/window/menu.c							\
			src/window/draw_mouse.c						\
			src/window/draw_lamp.c						\
			src/initialization/create_textures.c		\
			src/raycasting/draw_floor.c					\
			src/hud/create_hud.c						\
			src/hud/display_hud.c						\
			src/player_movements/sprint.c				\
			src/player_movements/stamina_regen.c		\
			src/enemies/create_new_monster.c			\
			src/enemies/display_entities.c				\
			src/inventory/inventory.c 					\
			src/initialization/init_client.c			\
			src/music/play_music_tiles.c 				\
			src/initialization/init_music.c 			\
			src/window/audio_param.c					\
			src/window/init/init_footstep.c 			\
			src/music/play_footsteps.c 					\
			src/window/init/init_gun.c 					\
			src/window/draw_gun.c 						\
			src/enemies/sort_entities.c					\
			src/window/init/init_graphics.c				\
			src/window/graphics.c						\
			src/window/init/init_minimap.c				\
			src/window/minimap.c						\
			src/save.c									\
			src/load_save.c								\
			src/enemies/manage_enemies.c				\
			src/enemies/add_to_entity_list.c			\
			src/enemies/handle_enderman.c				\
			src/enemies/enemies_attack.c 				\
			src/window/shoot.c							\
			src/object/init_items.c 					\
			src/level_management/next_level.c			\
			src/free/free_enemies_list.c				\
			src/inventory/hand_inventory.c				\
			src/object/get_object.c 					\
			src/object/exctract.c						\
			src/free/free_items_list.c 					\
			src/initialization/init_visor.c				\
			src/initialization/init_weapons.c			\
			src/inventory/manage_hand_inventory.c		\
			src/inventory/draw_hand.c					\


SRC_SERV = 	server/main.c								\
			server/init/init_epoll.c					\
			server/init/init_tcp.c						\
			server/manage/manage_map.c					\
			server/manage/manage_client.c				\
			server/manage/manage_pos.c					\
			server/manage/manage_stdin.c				\
			server/get_ip.c								\
			server/init/init_udp.c						\
			server/server_loop.c						\
			src/initialization/init_map.c				\
			src/generating/parsing_map.c 				\
			src/generating/parsing_door.c 				\
			src/generating/generating.c 				\
			src/generating/create_map.c 				\
			src/generating/free_tools.c 				\
			lib/free_array.c							\
			lib/str_to_wa.c 							\
			src/player_movements/movements.c			\
			src/player_movements/rotation.c				\
			src/enemies/create_new_monster.c			\
			src/enemies/sort_entities.c					\
			src/enemies/handle_enderman.c				\
			src/object/init_items.c 					\
			src/manage_client.c							\
			src/level_management/next_level.c			\
			src/free/free_enemies_list.c				\
			src/initialization/init_player.c			\
			src/inventory/inventory.c					\
			src/inventory/hand_inventory.c				\
			src/object/get_object.c 					\
			src/object/exctract.c 						\
			src/free/free_items_list.c 					\
			src/initialization/init_visor.c				\
			src/initialization/init_weapons.c			\
			src/inventory/manage_hand_inventory.c		\
			src/inventory/draw_hand.c					\


SRC_TESTS = tests/unit_tests.c 							\
			$(filter-out $(MAIN), $(SRC))

NAME = wolf3d

NAME_SERV = serv

OBJ_FOLDER = obj

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

OBJ_SERV = $(patsubst %.c, obj/%.o, $(SRC_SERV))

all : $(NAME) $(NAME_SERV)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

$(NAME_SERV) : $(OBJ_SERV)
	$(CC) $(OBJ_SERV) -o $(NAME_SERV) $(LIBS)

$(OBJ_FOLDER)/%.o: %.c
	@mkdir -p $(OBJ_FOLDER) $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean : RM += -R
clean :
	@$(RM) $(OBJ_FOLDER)

fclean : clean
	@$(RM) $(NAME) $(NAME_SERV)

fclean_test :
	@$(RM) *.gcno
	@$(RM) *.gcda
	@$(RM) unit_tests

asset:
	rm -rf assets
	wget https://github.com/julien-nouyrigat/Asset-Wolf3d/archive/main.zip
	unzip main.zip -d assets
	mv assets/Asset-Wolf3d-main/rooms assets
	mv assets/Asset-Wolf3d-main/image assets
	mv assets/Asset-Wolf3d-main/sounds assets
	mv assets/Asset-Wolf3d-main/sprite_sheet assets
	mv assets/Asset-Wolf3d-main/fonts assets
	mv assets/Asset-Wolf3d-main/monsters assets
	mv assets/Asset-Wolf3d-main/monster_sounds assets
	mv assets/Asset-Wolf3d-main/items assets
	mv assets/Asset-Wolf3d-main/weapons assets
	rm -f main.zip
	rm -f main.zip.1
	rm -f main.zip.2
	rm -f main.zip.3

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

.PHONY : fclean fclean_test re debug tests_run ll asset
