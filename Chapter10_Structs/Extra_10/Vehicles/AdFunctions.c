#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"

void print_scene(float speed, uint32_t lane)
{
    printf("\n\n");

    printf("\t  L   C   R\n");

    float offset_m = 20.0f;

    for (int32_t i = 100; i >= -100; i -= (int32_t)(offset_m))
    {
        char left_string[] = "   ";
        char center_string[] = "   ";
        char right_string[] = "   ";

        if (i == 0)
        {
            switch (lane)
            {
            case LANE_ASSOCIATION_TYPE_LEFT:
            {
                strncpy(left_string, " V ", 4);
                break;
            }

            case LANE_ASSOCIATION_TYPE_CENTER:
            {
                strncpy(center_string, " V ", 4);
                break;
            }

            case LANE_ASSOCIATION_TYPE_RIGHT:
            {
                strncpy(right_string, " V ", 4);
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
    printf("Speed: %f\n", speed);
    printf("\n");
}


void get_user_input(float *speed, uint32_t *lane)
{
    char longAct;
    char latAct;

    printf("\n");

    printf("LongitudinalAction (w=Increase, s=Decrease): ");
    scanf(" %c", &longAct);
    handle_longitudinal_user_input(speed, longAct);

    printf("LateralAction (a=Left, d=Right): ");
    scanf(" %c", &latAct);
    handle_lateral_user_input(lane, latAct);
}


void handle_lateral_user_input(uint32_t *lane, char lateral_action)
{
    switch (lateral_action)
    {
    case LATERAL_ACTION_LEFT:
    {
        switch (*lane)
        {
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            *lane = LANE_ASSOCIATION_TYPE_LEFT;
            break;
        }
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            *lane = LANE_ASSOCIATION_TYPE_CENTER;
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }

    case LATERAL_ACTION_RIGHT:
    {
        switch (*lane)
        {
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            *lane = LANE_ASSOCIATION_TYPE_CENTER;
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            *lane = LANE_ASSOCIATION_TYPE_RIGHT;
            break;
        }
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }

    default:
    {
        break;
    }
    }
}


void handle_longitudinal_user_input(float *speed, char longitudinal_action)
{
    switch (longitudinal_action)
    {
    case LONGITUDINAL_ACTION_ACCELERATE:
    {
        float new_speed = *speed + (*speed * LONGITUDINAL_DIFFERENCE_PERCENTAGE);
        *speed = new_speed;
        break;
    }

    case LONGITUDINAL_ACTION_DECELERATE:
    {
        float new_speed = *speed - (*speed * LONGITUDINAL_DIFFERENCE_PERCENTAGE);
        *speed = new_speed;
        break;
    }

    default:
    {
        break;
    }
    }
}


float kph_to_mps(float kph)
{
    return kph / 3.6f;
}


void init_ego_vehicle(VehicleType *ego_vehicle)
{
    ego_vehicle->id = EGO_VEHICLE_ID;
    ego_vehicle->lane = LANE_ASSOCIATION_TYPE_CENTER;
    ego_vehicle->speed_mps = kph_to_mps(130.0f);
    ego_vehicle->distance_m = 0.0f;
}

void init_vehicle(VehicleType *vehicle, int32_t id, float speed_kph, float distance_m, LaneAssociationType lane)
{
    vehicle->id = id;
    vehicle->lane = lane;
    vehicle->speed_mps = kph_to_mps(speed_kph);
    vehicle->distance_m = distance_m;
}


void init_vehicles(NeighborVehiclesType *vehicles)
{
    init_vehicle(&vehicles->vehicles_left_lane[0], 0, 50, 20, LANE_ASSOCIATION_TYPE_LEFT);
    init_vehicle(&vehicles->vehicles_left_lane[1], 1, 100, -20, LANE_ASSOCIATION_TYPE_LEFT);

    init_vehicle(&vehicles->vehicles_center_lane[0], 2, 150, 40, LANE_ASSOCIATION_TYPE_CENTER);
    init_vehicle(&vehicles->vehicles_center_lane[1], 3, 120, -60, LANE_ASSOCIATION_TYPE_CENTER);

    init_vehicle(&vehicles->vehicles_right_lane[0], 4, 200, 60, LANE_ASSOCIATION_TYPE_RIGHT);
    init_vehicle(&vehicles->vehicles_right_lane[1], 5, 80, -80, LANE_ASSOCIATION_TYPE_RIGHT);
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
    print_vehicle(&vehicles->vehicles_center_lane[0]);
    print_vehicle(&vehicles->vehicles_center_lane[1]);
    print_vehicle(&vehicles->vehicles_right_lane[0]);
    print_vehicle(&vehicles->vehicles_right_lane[1]);
}
