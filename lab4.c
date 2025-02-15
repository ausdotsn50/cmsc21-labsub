/*A C program that outputs narcissistic numbers based on a user-defined range
Submitted by: Angela Denise Almazan*/
#include <ctype.h>
#include <math.h> // pow
#include <stdbool.h> // bool
#include <stdio.h>
#include <stdlib.h> // atoi

// func prototypes
bool narcissistic(int num);
bool validity(char input[]);
int dig_length(int num);
void output(int num);

// main
int main() {
    // resorted to strings, handy for bool validity later on
    char choice, lower_str[50], upper_str[50]; // 50 char length assumption

    // "while bool true, keep doin"
    do {
        printf("Enter lower limit to print narcissistic numbers: ");
        scanf("%s", lower_str);
    } while(!validity(lower_str) || atoi(lower_str) < 0); 

    do {
        printf("Enter upper limit to print narcissistic numbers: ");
        scanf("%s", upper_str);
    } while(!validity(upper_str) || atoi(upper_str) < atoi(lower_str));

    // string to int conversion by built-in >>atoi
    int lower = atoi(lower_str);
    int upper = atoi(upper_str);

    // traverse from lower to upper limit
    while (lower <= upper) {
        // if true, then do
        if (narcissistic(lower)) {
            output(lower);
        }
        lower++;
    }
}

// determines narcissistic number/s
bool narcissistic(int num) {
    int temp = num, r_most, sum = 0;
    while (temp != 0) {
        int power = dig_length(num); // calling func inside func...
        r_most = temp % 10;
        sum += pow(r_most, power);
        temp /= 10;
    }

    if (num == sum) {
        return true;
    }
    return false;
}

// length of digit
int dig_length(int num) {
    int len = 0;
    while (num != 0) {
        num /= 10;
        len++;
    }
    return len;
}

// checks validity of the input (excluding the non-negative condition)
// basically, does not accept 'float-form' inputs
bool validity(char input[]) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '.' || !isdigit(input[i])) {
            return false;
        }
    }
    return true; 
}

// output printing
void output(int num) {
    printf("%d\n", num);
}