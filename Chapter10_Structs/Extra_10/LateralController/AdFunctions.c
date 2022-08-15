#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"

void print_scene(const VehicleType *ego_vehicle, const NeighborVehiclesType *vehicles)
{
    printf("\n\n");

    printf("\t  L   C   R\n");

    float offset_m = 10.0f;

    size_t left_idx = 0;
    size_t center_idx = 0;
    size_t right_idx = 0;

    for (int32_t i = 100; i >= -100; i -= (int32_t)(offset_m))
    {
        const VehicleType *left_vehicle =
            (left_idx >= NUM_VEHICLES_ON_LANE) ? NULL : &vehicles->vehicles_left_lane[left_idx];
        const VehicleType *center_vehicle =
            (center_idx >= NUM_VEHICLES_ON_LANE) ? NULL : &vehicles->vehicles_center_lane[center_idx];
        const VehicleType *right_vehicle =
            (right_idx >= NUM_VEHICLES_ON_LANE) ? NULL : &vehicles->vehicles_right_lane[right_idx];

        char left_string[] = "   ";
        char center_string[] = "   ";
        char right_string[] = "   ";

        const float range_m = (float)(i);

        if ((left_vehicle != NULL) && (range_m >= left_vehicle->distance_m) &&
            (left_vehicle->distance_m > (range_m - offset_m)))
        {
            strncpy(left_string, " V ", 4);
            left_idx++;
        }
        if ((center_vehicle != NULL) && (range_m >= center_vehicle->distance_m) &&
            (center_vehicle->distance_m > (range_m - offset_m)))
        {
            strncpy(center_string, " V ", 4);
            center_idx++;
        }
        if ((right_vehicle != NULL) && (range_m >= right_vehicle->distance_m) &&
            (right_vehicle->distance_m > (range_m - offset_m)))
        {
            strncpy(right_string, " V ", 4);
            right_idx++;
        }

        if (i == 0)
        {
            switch (ego_vehicle->lane)
            {
            case LANE_ASSOCIATION_TYPE_LEFT:
            {
                strncpy(left_string, " E ", 4);
                break;
            }

            case LANE_ASSOCIATION_TYPE_CENTER:
            {
                strncpy(center_string, " E ", 4);
                break;
            }

            case LANE_ASSOCIATION_TYPE_RIGHT:
            {
                strncpy(right_string, " E ", 4);
                break;
            }

            default:
            {
                break;
            }
            }
        }

        printf("%d\t|%s|%s|%s|\n", i, left_string, center_string, right_string);
    }

    printf("\n");
    printf("\nSpeed: %f\n", ego_vehicle->speed_mps);
}

float kph_to_mps(const float kph)
{
    return kph / 3.6f;
}

float mps_to_kph(const float mps)
{
    return mps * 3.6F;
}

void init_ego_vehicle(VehicleType *ego_vehicle)
{
    ego_vehicle->id = EGO_VEHICLE_ID;
    ego_vehicle->lane = LANE_ASSOCIATION_TYPE_CENTER;
    ego_vehicle->speed_mps = kph_to_mps(100.0f);
    ego_vehicle->distance_m = 0.0f;
}

void init_vehicle(VehicleType *vehicle,
                  const int32_t id,
                  const float speed_kph,
                  const float distance_m,
                  const LaneAssociationType lane)
{
    vehicle->id = id;
    vehicle->lane = lane;
    vehicle->speed_mps = kph_to_mps(speed_kph);
    vehicle->distance_m = distance_m;
}


void init_vehicles(NeighborVehiclesType *vehicles)
{
    init_vehicle(&vehicles->vehicles_left_lane[0], 0, 120, -60, LANE_ASSOCIATION_TYPE_LEFT);
    init_vehicle(&vehicles->vehicles_left_lane[1], 1, 110, -100, LANE_ASSOCIATION_TYPE_LEFT);

    init_vehicle(&vehicles->vehicles_center_lane[0], 2, 60, 60, LANE_ASSOCIATION_TYPE_CENTER);
    init_vehicle(&vehicles->vehicles_center_lane[1], 3, 60, -20, LANE_ASSOCIATION_TYPE_CENTER);

    init_vehicle(&vehicles->vehicles_right_lane[0], 4, 90, 80, LANE_ASSOCIATION_TYPE_RIGHT);
    init_vehicle(&vehicles->vehicles_right_lane[1], 5, 90, -40, LANE_ASSOCIATION_TYPE_RIGHT);
}


const VehicleType *get_vehicle_array(const LaneAssociationType ego_lane, const NeighborVehiclesType *vehicles)
{
    switch (ego_lane)
    {
    case LANE_ASSOCIATION_TYPE_LEFT:
    {
        return vehicles->vehicles_left_lane;
        break;
    }
    case LANE_ASSOCIATION_TYPE_CENTER:
    {
        return vehicles->vehicles_center_lane;
        break;
    }
    case LANE_ASSOCIATION_TYPE_RIGHT:
    {
        return vehicles->vehicles_right_lane;
        break;
    }
    case LANE_ASSOCIATION_TYPE_NONE:
    default:
    {
        return NULL;
    }
    }
}


LaneAssociationType get_lane_change_request(const VehicleType *ego_vehicle, const NeighborVehiclesType *vehicles)
{
    const VehicleType *ego_lane_vehicles = get_vehicle_array(ego_vehicle->lane, vehicles);
    const VehicleType *rear_vehicle = &ego_lane_vehicles[1];

    const float min_distance_m = mps_to_kph(ego_vehicle->speed_mps) * 0.2f;
    const float rear_distance_m = fabs(rear_vehicle->distance_m);

    if (rear_distance_m < min_distance_m)
    {
        switch (ego_vehicle->lane)
        {
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            const VehicleType *ego_lane_vehicles = get_vehicle_array(ego_vehicle->lane, vehicles);
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            break;
        }
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            break;
        }
        case LANE_ASSOCIATION_TYPE_NONE:
        default:
        {
            break;
        }
        }
    }
}


bool lateral_control(const NeighborVehiclesType *vehicles,
                     const LaneAssociationType lane_change_request,
                     VehicleType *ego_vehicle)
{
}


void print_vehicle(const VehicleType *vehicle)
{
    printf("ID: %d\n", vehicle->id);
    printf("Speed (m/s): %f\n", vehicle->speed_mps);
    printf("Distance (m): %f\n", vehicle->distance_m);
    printf("Lane: %d\n", vehicle->lane);
}


void print_neighbor_vehicles(const NeighborVehiclesType *vehicles)
{
    print_vehicle(&vehicles->vehicles_left_lane[0]);
    print_vehicle(&vehicles->vehicles_left_lane[1]);
    printf("\n");
    print_vehicle(&vehicles->vehicles_center_lane[0]);
    print_vehicle(&vehicles->vehicles_center_lane[1]);
    printf("\n");
    print_vehicle(&vehicles->vehicles_right_lane[0]);
    print_vehicle(&vehicles->vehicles_right_lane[1]);
    printf("\n");
}


void decrease_speed(VehicleType *ego_vehicle)
{
    const float speed_decrease = ego_vehicle->speed_mps * LONGITUDINAL_DIFFERENCE_PERCENTAGE;

    if ((ego_vehicle->speed_mps - speed_decrease) > 0.0f)
    {
        ego_vehicle->speed_mps -= speed_decrease;
    }
}


void longitudinal_control(const VehicleType *front_vehicle, VehicleType *ego_vehicle)
{
    const float min_distance_m = mps_to_kph(ego_vehicle->speed_mps) * 0.5f;
    const float front_distance_m = front_vehicle->distance_m;

    if (front_distance_m < min_distance_m)
    {
        decrease_speed(ego_vehicle);
    }
}


void compute_future_distance(VehicleType *vehicle, const float ego_driven_distance, const float seconds)
{
    const float veh_driven_distance = vehicle->speed_mps * seconds;

    vehicle->distance_m = vehicle->distance_m + veh_driven_distance - ego_driven_distance;
}


void compute_future_state(const VehicleType *ego_vehicle, NeighborVehiclesType *vehicles, const float seconds)
{
    const float ego_driven_distance = ego_vehicle->speed_mps * seconds;

    for (int32_t i = 0; i < NUM_VEHICLES_ON_LANE; i++)
    {
        compute_future_distance(&vehicles->vehicles_left_lane[i], ego_driven_distance, seconds);
        compute_future_distance(&vehicles->vehicles_center_lane[i], ego_driven_distance, seconds);
        compute_future_distance(&vehicles->vehicles_right_lane[i], ego_driven_distance, seconds);
    }
}
