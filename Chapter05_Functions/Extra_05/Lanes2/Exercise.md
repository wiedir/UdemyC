# Exercise

For this exercise, you have to create the following files:

- AdFunctions.h
- AdFunctions.c
- AdTypes.h

Content of AdFunctions.c/h:

- The **print_scene** function that prints out the console output from exercise **Lanes1**

Content of AdTypes.h:

- The Lane Enum

Note:

Don't forget to use include guards!

## Main Function

```cpp
#include <stdint.h>
#include <stdio.h>

#include "AdFunctions.h"

int main()
{
    printf("Create the properties of a vehicle.\n");

    float speed_mps;
    printf("Speed in $\frac{m}{s}$: ");
    scanf("%f", &speed_mps);

    uint32_t lane_idx;
    printf("Lane (1=Right, 2=Center, 3=Left): ");
    scanf("%u", &lane_idx);

    print_scene(speed_mps, lane_idx);

    return 0;
}
```
