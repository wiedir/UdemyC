#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include "AdTypes.h"
#include <stdint.h>

void print_scene(float speed, uint32_t lane);

void get_user_input(float *speed, uint32_t *lane);

void handle_lateral_user_input(uint32_t *lane, char lateral_action);

void handle_longitudinal_user_input(float *speed, char longitudinal_action);

float kph_to_mps(float kph);

void init_ego_vehicle(VehicleType *ego_vehicle);

void init_vehicle(VehicleType *vehicle, int32_t id, float speed_kph, float distance_m, LaneAssociationType lane);

void init_vehicles(NeighborVehiclesType *vehicles);

void print_vehicle(const VehicleType *vehicle);

void print_neighbor_vehicles(const NeighborVehiclesType *vehicles);

#endif
