/*
** EPITECH PROJECT, 2019
** prototype.h
** File description:
** prototype
*/

#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "structures.h"
#include "my.h"

int mainscreen(int *gamemode);
int end(int *gamemode);
void clockcreate(strct *strct, int nbr);
void clockelapsed(strct *strct, int nbr);
void game(int *gamemode);
int init_ennemi(scene_t *scene);
sfRenderWindow *createmywindow(unsigned int width, unsigned int height);
void close_window(scene_t *scene, strct *strct, pause_s *pause);
int init_checkpoint_tower(scene_t *scene);
int initialisation(strct *strct);
int init_checkpoint(scene_t *scene, int x, int y);
void init_render(strct *strct);
void render(sfRenderWindow *window, strct *strct);
int add_ruby(scene_t *scene, int i, strct *strct);
void find_pos(obj_t *perso, scene_t *scene);
int init_pos_check(scene_t *scene, int x, int y);
int event_gest(scene_t *scene, int *gamemode);
int allevent(scene_t *scene, sfEvent *event, strct *strct, pause_s *pause);
int cond_rel(sfVector2f pos1, but_s *checkpoint, scene_t *scene);
int movement(strct *strct, scene_t *scene);
void move_ennemis(scene_t *scene);
int println(strct *strct, sfRenderWindow *window);
int stats(scene_t *scene, strct *strct, sfRenderWindow *window);
void disp_ennemi(scene_t *scene);
void debug(scene_t *scene);
int find_ennemis(scene_t *scene);
int compare_coord(obj_t *perso, sfVector2i mouse);
void check_move(scene_t *scene);
void move_icon(scene_t *scene);
void is_trashed(scene_t *scene, scene_t *temp, int i, strct *strct);
void find_released(scene_t *scene, strct *strct);
int map(ent_t *back);
int cond_pos(sfVector2f pos1, sfVector2f pos2);
int init_start_button(but_s *button);
int init_end_button(but_s *button);
int button_is_clicked(sfRectangleShape *button, sfVector2i click_position);
void cond_mouse(scene_t *scene);
int init_button(scene_t *scene);
int init_scene(scene_t *scene);
void button_disp(scene_t *scene);
sfIntRect create_char_rect(int x, int y, int width, int height);
int printer(strct *strct);
void disp_button(scene_t *scene);
int upgrade(scene_t *scene, sfVector2i mouse, strct *strct);
void check_impact(scene_t *scene, strct *strct);
int init_strct(strct *strct);
void create_button2(but_s *button);
void create_button3(but_s *button);
void create_button1(but_s *button);
void create_button4(but_s *button);
void disp_pause(scene_t *scene, pause_s *pause);
int pause_function(scene_t *scene, pause_s *pause);
int pause_event(sfEvent *event, scene_t *scene, pause_s *pause);
void disp_scene(scene_t *scene);
int init_pause(pause_s *pause);
void init_filter(pause_s *pause);
int usage(void);
dam_s damage(float slow, int dam, float time, int zone);
void create_slow(but_s *button, char *str, int x, int y);
void create_reload(but_s *button, char *str, int x, int y);
void create_damage(but_s *button, char *str, int x, int y);
void create_cost(but_s *button, char *str, int x, int y);
int nbr_ennemi(scene_t *scene);
void create_zone(but_s *button, char *str, int x, int y);
void create_life(ennemi_t *ennemi, sfVector2f pos, int x, int y);
sfText *place_money(strct *strct, char *arr, int x, int y);
int waves(scene_t *scene);
void free_perso(scene_t *scene);
void free_ennemi(scene_t *scene);
void free_button(scene_t *scene);
void free_checkpoint(scene_t *scene);
int double_pos(scene_t *scene, scene_t *pos_scene);
void castle_damage(scene_t *scene, timer *clock_castle);
int r_number(scene_t *scene, int nb);
int ennemi_type(scene_t *scene, ennemi_t *ennemi, sfVector2f pos);
int red_d(scene_t *scene, ennemi_t *ennemi, sfVector2f pos);
int blue_d(scene_t *scene, ennemi_t *ennemi, sfVector2f pos);
int light_d(scene_t *scene, ennemi_t *ennemi, sfVector2f pos);
int dark_d(scene_t *scene, ennemi_t *ennemi, sfVector2f pos);
void init_char_enn(ennemi_t *ennemi);
void check_explosion(scene_t *scene);
int anim_pos(scene_t *scene);
sfVector2f convert_mouse(sfVector2i mouse);
void up_tower1(obj_t *tower);
void up_tower2(obj_t *tower);
void up_tower3(obj_t *tower);
void up_tower4(obj_t *tower);
void restart_bullet(scene_t *scene, ennemi_t *ennemie, ennemi_t *temp_enn);
void modif_life(scene_t *scene, ennemi_t *temp_enn);
void set_zone_zone_enn(int *i, sfVector2f *pos_enn_zone,
                       ennemi_t *zoned_ennemi);
void set_zone_scene(sfFloatRect *enn_rect, sfVector2f *life, scene_t *scene);
void clock_ennemie(ennemi_t *ennemi);
void move_clock_ennemi(scene_t *scene);
int init_all(scene_t *scene, strct *strct, pause_s *pause, timer *clock_castle);
int damage_r(scene_t *scene);
int song(scene_t *scene);
int disp_loose(scene_t *scene);
void move_clock_ennemi(scene_t *scene);
void set_zone_scene(sfFloatRect *enn_rect, sfVector2f *life, scene_t *scene);
void set_zone_zone_enn(int *i, sfVector2f *pos_enn_zone,
                       ennemi_t *zoned_ennemi);
void restart_bullet(scene_t *scene, ennemi_t *ennemie, ennemi_t *temp_enn);
sfVector2f convert_mouse(sfVector2i mouse);
int castle_life(scene_t *scene);
int init_how_to_play_button(but_s *button);
int what_button_is_clicked(but_s **button, sfVector2i mouse);
void init_restart_button(but_s*button);
void init_menu_button(but_s *button);
void cond_button_loose(but_s **button, scene_t *scene);
void cond_how_to_play(scene_t *scene, but_s *button);
void free_music(scene_t *scene);
int how_to_play_gestion(scene_t *scene);

#endif
