/*A C program that computes - slope, distance, midpoint, x and y intercepts using structs, functions, and pointers
Submitted by: Angela Denise Almazan*/

#include <math.h> // for sqrt func
#include <stdlib.h> // for fabs func
#include <stdio.h>

// struct for coords (used multiple times later)
struct coordinates {
    float x[2];
    float y[2];
};

float comp_slope(struct coordinates c);
float comp_dist(struct coordinates c);
void midpoint(struct coordinates c, float *midp_coor);
float comp_xint(struct coordinates c, float slope, float y_int);
float comp_yint(struct coordinates c, float slope);

int main() {
    struct coordinates coords;
    char choice;
    float slope, dist, midpoint_coords[2], x_int, y_int;

    do {
        // taking user_input for coordinates
        printf("Enter the first coordinates:\n");
        printf("x: ");
        scanf("%f", &coords.x[0]);

        printf("y: ");
        scanf("%f", &coords.y[0]);

        printf("\n");

        printf("Enter the second coordinates:\n");
        printf("x: ");
        scanf("%f", &coords.x[1]);

        printf("y: ");
        scanf("%f", &coords.y[1]);

        // variables assigned to value computations **for presentation below
        slope = comp_slope(coords);
        dist = comp_dist(coords);
        midpoint(coords, midpoint_coords);
        y_int = comp_yint(coords, slope);
        x_int = comp_xint(coords, slope, y_int);

        // displaying computed values
        printf("\nHere are the following values for:\n");

        printf("Slope: %.1f\n", slope);
        printf("Distance: %.1f\n", dist);
        printf("Midpoint Coordinates: (%.1f, %.1f)\n", midpoint_coords[0], midpoint_coords[1]);
        printf("x-intercept: (%.1f, 0)\n", x_int);
        printf("y-intercept: (0, %.1f)\n", y_int);
        
        if(y_int < 0) {
            printf("SLOPE INTERCEPT FORM: y = (%.1f)x - %.1f\n", slope, fabs(y_int)); // display for negative
        }
        else {
            printf("SLOPE INTERCEPT FORM: y = (%.1f)x + %.1f\n", slope, y_int); // display for positive
        }

        printf("\n");
        
        // keep using program upon user's wish
        do {
            printf("Press (Y/y) to continue using the program. Otherwise, press (N/n): ");
            scanf(" %c", &choice);
            
            if(choice == 'N' || choice == 'n') {
                break;
            }
            else if(choice == 'Y' || choice == 'y') {
                continue;
            }
        } while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
    } while(choice == 'Y' || choice == 'y');
}

float comp_slope(struct coordinates c) {
    float slope;
    return slope = (c.y[1] - c.y[0]) / (c.x[1] - c.x[0]);
}

float comp_dist(struct coordinates c) {
    float distance;
    float x_sqrd = (c.x[0] - c.x[1]) * (c.x[0] - c.x[1]);
    float y_sqrd = (c.y[0] - c.y[1]) * (c.y[0] - c.y[1]);
    return distance = sqrt(x_sqrd + y_sqrd);
}

// pointer as argument, modifying it within the code then
void midpoint(struct coordinates c, float *midp_coor) {
    *(midp_coor) = (c.x[0] + c.x[1]) / 2;
    *(midp_coor + 1) = (c.y[0] + c.y[1]) / 2;
}

// intercept formulas derived in blue notebook
float comp_xint(struct coordinates c, float slope, float y_int) {
    float x_int;
    return x_int = -(y_int/slope);
    
}

float comp_yint(struct coordinates c, float slope) {
    float y_int;
    return y_int = -(slope*c.x[0]) + c.y[0];
}