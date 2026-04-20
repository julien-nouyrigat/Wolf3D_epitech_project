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

SRC_SERV =	Server/run_serv.c							\
			Server/udp.c								\
			src/initialisation/init_map.c				\
			Server/main.c								\

SRC_CLIENT	=	Client/main.c							\
				Client/client_udp.c						\
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
				src/window/window_ip.c					\
				src/window/window_pseudo.c				\
				src/window/display_ip.c					\
				src/window/display_pseudo.c				\

SRC_TESTS = tests/unit_tests.c 						\
			$(filter-out $(MAIN), $(SRC))

NAME_SERV = server

NAME_CLIENT = wolf3d

OBJ_FOLDER = obj

OBJ_SERV = $(patsubst %.c, obj/%.o, $(SRC_SERV))

OBJ_CLIENT = $(patsubst %.c, obj/%.o, $(SRC_CLIENT))

all : $(NAME_SERV) $(NAME_CLIENT)

$(NAME_SERV) : $(OBJ_SERV)
	$(CC) $(OBJ_SERV) -o $(NAME_SERV) $(LIBS)

$(NAME_CLIENT) : $(OBJ_CLIENT)
	$(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(LIBS)

$(OBJ_FOLDER)/%.o: %.c
	@mkdir -p $(OBJ_FOLDER) $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean : RM += -R
clean :
	@$(RM) $(OBJ_FOLDER)

fclean : clean
	@$(RM) $(NAME_SERV) $(NAME_CLIENT)

fclean_test :
	@$(RM) *.gcno
	@$(RM) *.gcda
	@$(RM) unit_tests

re : fclean all

ll : $(NAME_SERV) $(NAME_CLIENT) re fclean

debug : CFLAGS += -g3
debug : $(OBJ) $(OBJ_SERV)
	$(CC) $(OBJ_SERV) -o $(NAME_SERV) $(LIBS) $(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(LIBS)

tests_run : CFLAGS += --coverage
			LIBS += -lcriterion -lgcov
tests_run : fclean fclean_test
	$(CC) -o unit_tests $(SRC_TESTS) $(CFLAGS) $(CPPFLAGS) $(LIBS)
	./unit_tests

.PHONY : fclean fclean_test re debug tests_run ll
