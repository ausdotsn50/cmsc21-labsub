/* A C program that deals with a matrix and its transposed form 
Submitted by: Angela Denise Almazan */
#include <stdio.h>

void mat_elems(int r_c, int matrix[][r_c]); // taking matrix elements (user input)
void transpose(int r_c, int matrix[][r_c], int transposed[][r_c]); // transpose the original matrix
void print_matrix(int r_c, int matrix[][r_c]);
int compare(int r_c, int matrix[][r_c], int transposed[][r_c]); // checking symmetry for orig matrix and transposed

int main() {
    int row_col;
    // row/column size should be greater than zero
    do {
        printf("Enter the desired number of rows and columns for the matrix: ");
        scanf("%d", &row_col);
        if(row_col < 1) {
            printf("Enter an integer greater than 0.\n");
        }
    } while(row_col < 1);
    int matrix[row_col][row_col], t_matrix[row_col][row_col];

    printf("\nEnter entries for the %d x %d matrix.\n", row_col, row_col);
    mat_elems(row_col, matrix);

    transpose(row_col, matrix, t_matrix);

    printf("\nThe matrix is:\n");
    print_matrix(row_col, matrix);

    printf("\nThe transpose of the matrix is:\n");
    print_matrix(row_col, t_matrix);

    int t_val = compare(row_col, matrix, t_matrix);
    if(t_val == 1) {
        printf("\nThe matrix is a symmetric matrix.\n\n");
    }
    else {
        printf("\nThe matrix is not symmetric.\n\n");
    }

    // terminate program only upon the user's wish
    char choice;
    while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
        printf("Would you like to try again? Y/N: ");
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

void mat_elems(int r_c, int matrix[][r_c]) {
    for(int row = 0; row < r_c; row++) {
        for(int col = 0; col < r_c; col++) {
            printf("Enter entry for row %d column %d: ", row + 1, col + 1);
            scanf("%d", &matrix[row][col]);
        }
    }
}

void transpose(int r_c, int matrix[][r_c], int transposed[][r_c]) {
    for(int row = 0; row < r_c; row++) {
        for(int col = 0; col < r_c; col++) {
            transposed[row][col] = matrix[col][row]; // a 2x3mat transposed is 3x2
        }
    }
}

void print_matrix(int r_c, int matrix[][r_c]) {
    for(int row = 0; row < r_c; row++) {
        for(int col = 0; col < r_c; col++) {
            printf("%d\t", matrix[row][col]);
            if(col == r_c - 1) { // last element for row, newline
                printf("\n");
            }
        }
    }
}

int compare(int r_c, int matrix[r_c][r_c], int transposed[][r_c]) {
    for(int row = 0; row < r_c; row ++) {
        for(int col = 0; col < r_c; col++) {
            if(matrix[row][col] != transposed[row][col]) { // the instance the element is different, mark as not symmetric
                return 0;
            }
        }
    }
    return 1;
}
