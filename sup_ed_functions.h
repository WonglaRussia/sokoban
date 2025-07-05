 /* sup_ed_functions.h */
#ifndef SUP_ED_FUNCTIONS_H
#define SUP_ED_FUNCTIONS_H

#define SITE_BAR_WIDTH 26
#define MIN_MAP_SHIFT 5 /* Map`s left-top corner position use as DRAFT */
void fringe_area(const int coord_y, const int coord_x, const int height, const int width);
void show_edited_map(struct level *play_ground, const int shft_y, const int shft_x);
void show_side_bar(const int shft_y, const int shft_x);
int get_map_position(const int mx);
void chk_pos(int *position);
#endif
