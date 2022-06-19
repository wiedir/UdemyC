#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

#include "AdFunctions.h"
#include "AdTypes.h"

int main()
{
    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    init_ego_vehicle(&ego_vehicle);
    init_vehicles(&vehicles);

    print_vehicle(&ego_vehicle);
    print_neighbor_vehicles(&vehicles);

    float speed_mps;
    speed_mps = ego_vehicle.speed_mps;

    uint32_t lane_idx;
    lane_idx = ego_vehicle.lane;

    // while (true)
    // {
    //     clear_console();

    //     print_scene(speed_mps, lane_idx);
    //     get_user_input(&speed_mps, &lane_idx);
    // }

    // return 0;
}
