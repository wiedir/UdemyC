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
