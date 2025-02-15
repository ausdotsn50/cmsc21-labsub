/*A C program that outputs distinct occurrences of elements in an array
Submitted by: Angela Denise Almazan*/
#include <stdio.h>

int main() {
    int size;
    do {
        printf("Enter size of the array: ");
        scanf("%d", &size);
    } while(size < 1);

    int numbers[size];
    printf("Enter elements in the array: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("The number of occurrences of each element:\n");
    // accessing each element
    for(int j = 0; j < size; j++) {
        int count = 1;

        // for each element, accessing to its right
        for(int k = j + 1; k < size; k++) {
            // in case of similar elements
            if(numbers[j] == numbers[k]) {
                count++;
                // shift to the left
                // size - 1 (else exceed array size)
                for(int l = k; l < size - 1; l++) {
                    numbers[l] = numbers[l + 1];
                }
                size--; // remove at the end
            }
        }

    // singular/plural
        if(count > 1) {
            printf("%d occured %d times\n", numbers[j], count);
        } else {
            printf("%d occured %d time\n", numbers[j], count);
        }
        
    }

    // accessing elements on the filtered array for printing
    printf("The distinct elements in the array: ");
    for(int m = 0; m < size; m++) {
        printf("%d ", numbers[m]);
    }
    printf("\n");

    return 0; 
}