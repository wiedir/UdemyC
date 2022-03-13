#include <stdint.h>
#include <stdio.h>

#include "AdFunctions.h"

int main()
{
    printf("Create the properties of a vehicle.\n");

    float speed_mps;
    printf("Speed in m/s: ");
    scanf("%f", &speed_mps);

    uint32_t lane_idx;
    printf("Lane (1=Right, 2=Center, 3=Left): ");
    scanf("%u", &lane_idx);

    print_scene(speed_mps, lane_idx);

    return 0;
}
