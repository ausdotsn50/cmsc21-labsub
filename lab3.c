/*A C program that prints out all special number within user-defined range
Submitted by: Angela Denise Almazan*/
#include <stdio.h>

int user_input();
int fac(int num);

int main() {

    // get upper range
    int range = user_input();
    printf("All special numbers between 1 to %d\n", range);

    // loop thru the range of 1 to range
    for (int i = 1; i <= range; i++) {

        int pot_special, sum_fac = 0, num = i;
        while (num != 0) {
            pot_special = num % 10;
            sum_fac += fac(pot_special);
            num /= 10;
        }

        if (i == sum_fac) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

int user_input() {
    int input;
    printf("Enter upper range: ");
    scanf("%d", &input);
    return input;
}

int fac(int num) {
    int factorial = 1;
    while (num != 0) {
        factorial *= num;
        num--;
    }
    return factorial;
}