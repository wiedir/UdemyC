#include <stdint.h>
#include <stdio.h>

enum LaneAssociationType
{
    LANE_ASSOCIATION_TYPE_NONE,
    LANE_ASSOCIATION_TYPE_LEFT,
    LANE_ASSOCIATION_TYPE_CENTER,
    LANE_ASSOCIATION_TYPE_RIGHT,
};

int main()
{
    float speed = 0.0f;
    int lane = 0;
    printf("Create the properties of a vehicle.\n");

    printf("Speed in m/s: ");
    scanf("%f", &speed);

    printf("Actual Lane (1=Left, 2=Center, 3=Right): ");
    scanf("%d", &lane);

    printf("\n\n");

    printf("  L   C   R\n");

    switch (lane)
    {
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            printf("| V |   |   |\n");
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            printf("|   | V |   |\n");
            break;
        }
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            printf("|   |   | V |\n");
            break;
        }
        default:
        {
            printf("|   |   |   |\n");
        }
    }

    printf("\nSpeed: %f\n", speed);

    return 0;
}
