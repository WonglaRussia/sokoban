/* editor_functions.h */
#ifndef EDITOR_FUNCTIONS_H
#define EDITOR_FUNCTIONS_H
void show_editor(struct level *play_ground, const int my, const int mx, const int pos_y, const int  pos_x);
void mv_position(map_type map, const int key, int *position_y, int *position_x, int my, int mx);
void update_edited_map(struct level *play_field, const int key, const int position_y, const int position_x);
#endif
