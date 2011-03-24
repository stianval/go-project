/*
 * Defines some game specific functions
 */

#ifndef _GAME_H
#define _GAME_H

#define SWIDTH 700
#define SHEIGHT 700

void game_init ();
void game_display ();
void game_keyboard (unsigned char key, int x, int y);
void game_idle ();
void game_mouse (int x, int y);

#endif
