/*A C program that computes a sequence to the nth element using recursive functions
Submitted by: Angela Denise Almazan*/
#include <stdio.h>

void sequence(int n);

int main() {
    char choice;
    int nth;

    printf("Enter: ");
    scanf("%d", &nth);

    sequence(nth);
    printf("\n");

    do {
        printf("Try again? (Y/N) ");
        scanf(" %c", &choice);

        if(choice == 'Y' || choice == 'y') {
            printf("\n");
            main();
        }
        else if(choice == 'N' || choice == 'n') {
            return 0;
        }

    } while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
}

// loops
/*
void sequence(int n) {
    int curr_num = 1, plus_fac = 0;
    for(int i = 0; i < n; i++) {
        if(curr_num % 2 == 0) {
            curr_num /= 2;
            printf("%d ", curr_num);
        }
        else {
            curr_num += plus_fac;
            printf("%d ", curr_num);
            plus_fac++;
        }
    }
}
*/

// recursion
void sequence(int n) {
    static int curr_num = 1, plus_fac = 0;
    if(n == 0){
        curr_num = 1, plus_fac = 0;
        return;
    }
    else {
        if(curr_num % 2 == 0) {
            curr_num /= 2;
            printf("%d ", curr_num);
            sequence(n - 1);
        }
        else {
            curr_num += plus_fac;
            printf("%d ", curr_num);
            plus_fac++;
            sequence(n - 1);
        }
    }

}