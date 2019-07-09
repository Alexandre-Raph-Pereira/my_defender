##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## My_Sokoban
##

SRC =	src/main.c								\
		src/add_and_free/add.c					\
		src/add_and_free/free.c 				\
		src/creates/create_info.c 				\
		src/creates/create_tower.c 				\
		src/entities/castle.c 					\
		src/entities/dragon.c					\
		src/entities/ennemis.c					\
		src/for_player/anim.c					\
		src/for_player/pos_anim.c				\
		src/for_player/song.c					\
		src/game/click.c						\
		src/game/event.c						\
		src/game/game.c							\
		src/game/usage.c						\
		src/how_to_play/how_to_play.c 			\
		src/how_to_play/how_to_play_gestion.c 	\
		src/inits/init.c						\
		src/inits/init_button.c					\
		src/inits/init_ent.c					\
		src/inits/init_loose.c 					\
		src/inits/init_menu.c					\
		src/inits/init_pause.c 					\
		src/menus/button.c						\
		src/menus/loose.c						\
		src/menus/menu.c						\
		src/menus/pause.c						\
		src/moves/move_ennemis.c				\
		src/moves/move_icon.c					\
		src/norms/for_norm.c 					\
		src/norms/for_norm2.c 					\
		src/shoot/damage.c						\
		src/shoot/impact.c						\
		src/shoot/shot.c						\
		src/shoot/zone_impact.c					\
		src/stats/clock.c						\
		src/stats/stats.c						\
		src/stats/window_stats.c				\
		src/usable/checkpoint.c					\
		src/usable/release.c					\
		src/usable/up_effect.c 					\
		src/usable/upgrade.c 					\
		src/usable/waves.c						\

SRCC =	tests/test_project.c					\
		src/add_and_free/add.c					\
		src/add_and_free/free.c 				\
		src/creates/create_info.c 				\
		src/creates/create_tower.c 				\
		src/entities/castle.c 					\
		src/entities/dragon.c					\
		src/entities/ennemis.c					\
		src/for_player/anim.c					\
		src/for_player/pos_anim.c				\
		src/for_player/song.c					\
		src/game/click.c						\
		src/game/event.c						\
		src/game/game.c							\
		src/game/usage.c						\
		src/how_to_play/how_to_play.c 			\
		src/how_to_play/how_to_play_gestion.c 	\
		src/inits/init.c						\
		src/inits/init_button.c					\
		src/inits/init_ent.c					\
		src/inits/init_loose.c 					\
		src/inits/init_menu.c					\
		src/inits/init_pause.c 					\
		src/menus/button.c						\
		src/menus/loose.c						\
		src/menus/menu.c						\
		src/menus/pause.c						\
		src/moves/move_ennemis.c				\
		src/moves/move_icon.c					\
		src/norms/for_norm.c 					\
		src/norms/for_norm2.c 					\
		src/shoot/damage.c						\
		src/shoot/impact.c						\
		src/shoot/shot.c						\
		src/shoot/zone_impact.c					\
		src/stats/clock.c						\
		src/stats/stats.c						\
		src/stats/windows_stats.c				\
		src/usable/checkpoint.c					\
		src/usable/release.c					\
		src/usable/up_effect.c 					\
		src/usable/upgrade.c 					\
		src/usable/waves.c						\

OBJ =	$(SRC:.c=.o)

OBJC =	$(SRCC:.c=.o)

NAME =	my_defender

INC = -I./include

LIB = -L./lib/my -lmy

LE = -lcsfml-graphics -lcsfml-audio -lcsfml-system

CRIT = --coverage -lcriterion

WALL = -Wall -Wextra -Werror

CRITERION = unit_tests

VALGRIND = -g3

CC = gcc -g3

CPPFLAGS = -I./include

ARGUMENTS = 

all:	$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib/my
			$(CC) -o $(NAME) $(OBJ) $(INC) $(LIB) $(LE) $(WALL)

exe:		$(NAME)
			clear
			./$(NAME)

valgrind:	$(OBJ)
			make -C ./lib/my
			gcc -o $(NAME) $(OBJ) $(LIB) $(LE) $(VALGRIND)
			rm -f $(OBJ)
			valgrind ./$(NAME) $(ARGUMENTS)

clean:
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ../lib/my/libmy.a
		rm -f lib/my/libmy.a

re: fclean all

error:		$(NAME)
			clear
			./$(NAME) maps/errormap

tests_run:	$(OBJC)
			make -C ./lib/my
			gcc -o $(CRITERION) $(OBJC) $(INC) $(LIB) $(LE) $(CRIT)
			rm -f $(OBJC)
			rm -f ../lib/my/libmy.a
			rm -f lib/my/libmy.a
			./$(CRITERION)
