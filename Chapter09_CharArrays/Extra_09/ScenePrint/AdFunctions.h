#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdint.h>

void print_scene(float speed, uint32_t lane);

void get_user_input(float *speed, uint32_t *lane);

void handle_lateral_user_input(uint32_t *lane, char lateral_action);

void handle_longitudinal_user_input(float *speed, char longitudinal_action);

#endif
