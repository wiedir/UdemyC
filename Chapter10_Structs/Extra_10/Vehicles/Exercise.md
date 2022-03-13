# Exercise

Create the following structs:

- VehicleType
  - vehicle id (int)
    - Ego vehicle id is (-1), create a define for this
  - lane association
  - speed in $\frac{m}{s}$
  - distance to ego vehicle in meter
- NeighborVehiclesType
  - vehicles on left lane array [2 entries in total]
  - vehicles on center lane array [2 entries in total]
  - vehicles on right lane array [2 entries in total]
  - Create a define for the array length from above

Note:

The logic of these arrays is:

- Index 0: Vehicle is in the front of the ego vehicle (distance > 0 at the start)
- Index 1: Vehicle is in the back (rear) of the ego vehicle (distance < 0 at the start)

Implement the following functions

```cpp
void init_ego_vehicle(VehicleType *ego_vehicle);

void init_vehicles(NeighborVehiclesType *vehicles);

void print_vehicle(const VehicleType *vehicle);

void print_neighbor_vehicles(const NeighborVehiclesType *vehicles);
```

- init_ego_vehicle
  - Just choose any current speed, and lane of the ego vehicle
- init_vehicles
  - Just choose any current speed, and lane of all other vehicles (6 in total)
- print_vehicle
  - print out all information of a vehicle
- print_neighbor_vehicles
  - iterate over all other vehicles and print out their information

## Main Function

```cpp
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

    print_scene(&ego_vehicle, &vehicles);

    printf("Start simulation?: ");
    char Input;
    scanf("%c", &Input);

    while (true)
    {
        clear_console();

        compute_future_state(&ego_vehicle, &vehicles, 1);
        print_scene(&ego_vehicle, &vehicles);

        sleep_console(500);
    }

    return 0;
}
```
