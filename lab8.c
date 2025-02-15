/* A C program that makes use of the concept of pointers to perform sorting/searching algorithms 
Submitted by: Angela Denise Almazan, Meshach Borla */
#include <stdio.h>
#include<math.h>

int dup_spot(int size, int *elem); // spotting duplicates in the array
int is_present(int size, int num, int *elem); // if element searched for is present in the array
void ins_sort(int size, int *elem); 
int search_num(int size, int num, int *elem); 

int main() {
    int size;
    do {
        printf("\nEnter desired array size: ");
        scanf("%d", &size);
 
        if(size < 1) {
            printf("Array size should be greater than zero.\n");
        }
    } while(size < 1);

    int numbers[size], has_dup, target_num; 
    do {
        printf("\nEnter %d elements for the array:\n", size);
        for(int i = 0; i < size; i++) {
            scanf("%d", &numbers[i]);
        }   
        
        has_dup = dup_spot(size, numbers);
        if(has_dup) {
            printf("Enter distinct elements for the array.\n");
        }
    } while(has_dup); // distinct elements only for the array

    int found;
    do {
        printf("\nEnter a number to search in the array: ");
        scanf("%d", &target_num);
        found = is_present(size, target_num, numbers);
        if(!found) {
            printf("Choose an element that is found in the array.\n");
        }
    } while(!(found));  // search only for what is in the array

    // peforming insertion sort
    ins_sort(size, numbers);
    
    // binary search
    int mid = search_num(size, target_num, numbers);

    // for debugging
    printf("\nThe sorted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("\n'%d' is at index [%d] of the array.\n", target_num, mid);

        // terminate program only upon the user's wish
    char choice;
    while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
        printf("Would you like to try the program again? Y/N: ");
        scanf(" %c", &choice);
        if(choice == 'Y' || choice == 'y') {
            printf("\n");
            main();
        } else if (choice == 'N' || choice == 'n') {
            printf("Program Terminated...\n");
            return 0;
        }
    }
}

// funcs
int dup_spot(int size, int *elem) {
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(elem[i] == elem[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int is_present(int size, int num, int *elem) {
    for(int i = 0; i < size; i++) {
        if(elem[i] == num) {
            return 1;
        }
    }
    return 0;
}

void ins_sort(int size, int *elem) {
    int temp, i, j;
    for(i = 1; i < size; i++) {
        temp = elem[i];
        for(j = i - 1; j >= 0; j--) {
            if(elem[j] > temp) {
                elem[j + 1] = elem[j];
            }
            else {
                break;
            }
        }
        elem[j + 1] = temp;
    }
}

void insertionSort(int *arr, int n) {
    int *i, *j, temp; 
    
    for (i = arr + 1; i < arr + n; ++i) { // arr + 1 = second element, arr + n = last element
        temp = *i;
        j = i - 1;
        
        while (j >= arr && *j > temp) {
            *(j + 1) = *j;
            j--;
        }
        
        *(j + 1) = temp;
    }
}

int search_num(int size, int num, int *elem) {
    int lower = 0, upper = size - 1, mid = (upper + lower) / 2; // floor lang
    while(elem[mid] != num) {
        if(elem[mid] < num) {
            lower = mid + 1;
        }
        else if(elem[mid] > num) {
            upper = mid - 1;
        }
        mid = ceil((upper + lower) / 2);
    }
    return mid;
}