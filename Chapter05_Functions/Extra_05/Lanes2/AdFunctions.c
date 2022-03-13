#include <stdint.h>
#include <stdio.h>

#include "AdFunctions.h"
#include "AdTypes.h"


void print_scene(float speed, uint32_t lane)
{
    printf("\n\n");

    printf("  L   C   R\n");

    switch (lane)
    {
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            printf("|   |   | V |\n");
            break;
        }

        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            printf("|   | V |   |\n");
            break;
        }

        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            printf("| V |   |   |\n");
            break;
        }

        default:
        {
            printf("|   |   |   |\n");
        }
    }

    printf("\nSpeed: %f\n", speed);
}
