##
## EPITECH PROJECT, 2021
## Graphical
## File description:
## Makefie
##

CFLAGS = -I./ -g3

SRC		=	main.c \
			game.c \
			map1/main.c \
			map1/init.c \
			map1/pause_map1.c \
			data/init_data.c \
			data/destroy_data.c \
			htp/init_htp.c \
			htp/htp_handler.c \
			htp/htp_handler2.c \
			htp/htp_handler3.c \
			htp/htp_handler4.c \
			htp/htp_handler5.c \
			htp/htp_handler6.c \
			htp/htp_handler7.c \
			htp/htp_pause.c \
			htp/read_dialogue.c \
			htp/handle_hover_spell_htp.c \
			tower/init_turret_menu.c \
			tower/set_hover_pos.c \
			tower/handle_hover_turret.c \
			tower/turret_menu.c \
			tower/init_towers.c \
			tower/init_towers2.c \
			tower/display_turret.c \
			tower/init_data.c \
			tower/destroy_data.c \
			tower/check_data.c \
			tower/anim_magic.c \
			tower/turret_sell.c \
			damage/damage.c \
			damage/calcul_angle.c \
			damage/arrow.c \
			damage/move_arrow.c \
			damage/thunder.c \
			damage/damage2.c \
			event/event_move.c \
			spell/handle_targeting.c \
			spell/animation_spell.c \
			spell/init_spell.c \
			tools/clock_tools.c \
			handler_scenes.c			\
			aux_sfvector.c				\
			hover_clic_rect.c			\
			hover_clic_circle.c			\
			button_animation_clic.c		\
			init/init_object.c			\
			init/init_circle_button.c	\
			init/init_rect_button.c		\
			setting/init_setting_menu.c	\
			menu/init_main_menu.c		\
			init/init_text.c			\
			init/init_music.c			\
			setting/setting_draw.c		\
			setting/setting_button_animation.c	\
			setting/setting_update_bar.c		\
			setting/setting_init_object.c		\
			setting/setting_init_circle.c		\
			setting/setting_init_rect.c			\
			setting/setting_init_text.c			\
			setting/setting_button_function_vol.c	\
			setting/setting_button_function_onoff.c	\
			setting/setting_button_rate.c	\
			setting/setting_event.c	\
			setting/setting_button_function_quit.c	\
			setting/setting_button_none.c	\
			setting/setting_destroy.c	\
			setting/malloc_setting.c			\
			menu/malloc_menu.c			\
			menu/menu_event.c			\
			menu/menu_init_object.c		\
			menu/menu_init_circle.c		\
			menu/menu_init_rect.c		\
			menu/menu_button_function_music.c	\
			menu/menu_button_function.c	\
			menu/menu_button_animation.c\
			menu/menu_button_none.c		\
			menu/menu_draw.c			\
			menu/menu_destroy.c			\
			menu/menu_button_function_sound.c	\
			pause/malloc_pause.c			\
			pause/init_pause_menu.c		\
			pause/pause_draw.c			\
			pause/pause_event.c			\
			pause/pause_init_object.c	\
			pause/pause_init_circle.c	\
			pause/pause_init_rect.c		\
			pause/pause_init_text.c		\
			pause/pause_button_animation.c		\
			pause/pause_button_function_music.c		\
			pause/pause_button_function_sound.c		\
			pause/pause_button_function_resume.c		\
			pause/pause_button_function_quit.c		\
			pause/pause_button_function_menu.c		\
			pause/pause_button_none.c		\
			pause/pause_destroy.c		\
			destroy/destroy_object.c	\
			helper/my_helper.c \
			monster/move_monster.c	\
			monster/set_orientation.c	\
			monster/health_bar.c	\
			monster/boss_monster.c	\
			monster/normal_monster.c	\
			monster/fast_monster.c	\
			monster/tank_monster.c	\
			monster/destroy_monster.c	\
			wave/destroy_wave.c	\
			wave/malloc_wave.c	\
			wave/handler_wave.c	\
			wave/init_wave.c	\
			wave/str_wave.c		\
			wave/draw_monster.c \
			point/init_point.c	\
			point/map_1_boss_monster.c	\
			point/map_1_tank_monster.c	\
			point/map_1_normal_monster.c	\
			point/map_1_fast_monster.c	\
			win_screen/malloc_win_screen.c	\
			win_screen/draw_win_screen.c	\
			win_screen/init_win_screen.c	\
			win_screen/win_screen_event.c	\
			win_screen/win_screen_destroy.c	\
			win_screen/win_screen_init_circle.c	\
			win_screen/win_screen_init_object.c	\
			win_screen/win_screen_init_rect.c	\
			win_screen/win_screen_init_text.c	\
			win_screen/win_screen_button_function.c	\
			win_screen/win_screen_button_none.c	\
			win_screen/win_screen_button_animation.c	\
			win_screen/win_screen_scoreboard_init_text.c	\
			win_screen/win_screen_score.c	\
			win_screen/win_screen_sound.c	\
			scoreboard/init_scoreboard.c	\
			scoreboard/malloc_scoreboard.c	\
			scoreboard/scoreboard_button_animation.c	\
			scoreboard/scoreboard_button_none.c	\
			scoreboard/scoreboard_destroy.c	\
			scoreboard/scoreboard_draw.c	\
			scoreboard/scoreboard_event.c	\
			scoreboard/scoreboard_init_circle.c	\
			scoreboard/scoreboard_init_object.c	\
			scoreboard/scoreboard_init_text.c	\
			scoreboard/scoreboard_button_function.c	\
			scoreboard_point/read_scoreboard.c	\


LIB	=	-L lib/my/ -lmy

CSFML	=	-l csfml-graphics -lcsfml-audio -lcsfml-graphics

CSFML1	=	-lcsfml-system -lcsfml-network -lcsfml-window -lm

OBJ		=		$(SRC:.c=.o)

NAME	=		my_defender

all: $(NAME)

MAKELIB:
	make -C lib/my/

DESTROYLIB:
	make fclean -C lib/my/

$(NAME): MAKELIB	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB) $(CSFML) $(CSFML1)
	touch scoreboard/score.txt
	chmod 777 scoreboard/score.txt

clean: DESTROYLIB
	find . -name "*.o" -exec rm -rf "{}" \;
	find . -name "*.~" -exec rm -rf "{}" \;

fclean:	clean
	rm -f $(NAME)

re: fclean all