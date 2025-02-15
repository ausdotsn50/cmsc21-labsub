/*A C program that serves as a calculator to compute for the perimeter or area of circle, rectangle, square, or triangle 
Submitted by: Angela Denise Almazan*/
#include <stdio.h>
#include <math.h>

#define PI 3.14

char choice();
int ask_radius();
void length_width(int dimensions[2]);
int ask_side();
void s1_s2_s3(int dimensions[3]);
void base_height(int dimensions[2]);

int main() {
    int pin = 8714, pin_input;
    char shape, comp;
    int radius, rec_dim[2], sq_side, tri_dim[3];

    do {
        printf("Enter 4-digit PIN: ");
        scanf("%d", &pin_input);
    } while(pin != pin_input);
    
    do {
        printf("\nWelcome to the calculator to compute the Perimeter or Area.\n"
               "Choose one of the following:\n"
               "a. Circle\n"
               "b. Rectangle\n"
               "c. Square\n"
               "d. Triangle\n"
               "\nEnter the letter of your choice here: ");

        scanf(" %c", &shape); 

        switch(shape) {
            case 'a':
                comp = choice();
                if (comp == 'P') {
                    radius = ask_radius();
                    printf("The circumference of a circle with radius %d is %.2f\n", radius, 2*PI*radius);
                } else if (comp == 'A') {
                    radius = ask_radius();
                    printf("The area of a circle with radius %d is %.2f\n", radius, PI*pow(radius, 2));
                }
                break;
            
            case 'b':
                comp = choice();
                if (comp == 'P') {
                    length_width(rec_dim);
                    int length = rec_dim[0], width = rec_dim[1];
                    printf("The perimeter of a rectangle with length %d and width %d is %d\n", length, width, 2*(length+width));
                } else if (comp == 'A') {
                    length_width(rec_dim);
                    int length = rec_dim[0], width = rec_dim[1];
                    printf("The area of a rectangle with length %d and width %d is %d\n", length, width, length*width);
                }
                break;
            
            case 'c':
                comp = choice();
                if (comp == 'P') {
                    sq_side = ask_side();
                    printf("The perimeter of a square with side %d is %d\n", sq_side, 4*sq_side);
                } else if (comp == 'A') {
                    sq_side = ask_side();
                    printf("The area of a square with side %d is %.0f\n", sq_side, pow(sq_side, 2));
                }
                break;

            case 'd':
                comp = choice();
                if (comp == 'P') {
                    s1_s2_s3(tri_dim);
                    int s1 = tri_dim[0], s2 = tri_dim[1], s3 = tri_dim[2];
                    printf("The perimeter of a triangle with sides %d, %d, %d is %d\n", s1, s2, s3, s1+s2+s3);
                } else if (comp == 'A') {
                    base_height(tri_dim);
                    printf("The area of a triangle with base %d and height %d is %.0f\n", tri_dim[0], tri_dim[1], 0.5*(tri_dim[0]*tri_dim[1]));
                }
                break;

            default:
                printf("Invalid choice :/\n");
                break;
        }
    } while (shape != 'a' && shape != 'b' && shape != 'c' && shape != 'd');
    
    return 0;
}

char choice()
{
    char choice;
    do {
        printf("Choose P to compute for Perimeter and A for Area: ");
        scanf(" %c", &choice);

        if (choice != 'P' && choice != 'A') {
            printf("Invalid choice :/\n");
        }
    } while (choice != 'P' && choice != 'A');

    return choice;
}

int ask_radius()
{
    int radius;
    printf("Radius: ");
    scanf("%d", &radius);
    return radius;
}

void length_width(int dimensions[2])
{
    printf("Length: ");
    scanf("%d", &dimensions[0]);

    printf("Width: ");
    scanf("%d", &dimensions[1]);
}

int ask_side()
{
    int side;
    printf("Side of the square: ");
    scanf("%d", &side);
    return side;
}

void s1_s2_s3(int dimensions[])
{
    printf("Side 1: ");
    scanf("%d", &dimensions[0]);

    printf("Side 2: ");
    scanf("%d", &dimensions[1]);

    printf("Side 3: ");
    scanf("%d", &dimensions[2]);
}

void base_height(int dimensions[])
{ 
    printf("Base: ");
    scanf("%d", &dimensions[0]);

    printf("Height: ");
    scanf("%d", &dimensions[1]);
}