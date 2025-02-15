/*A C program that sorts the letters in a given string alphabetically, ignoring non-letter characters
Submitted by: Angela Denise Almazan*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void string_sort(char *long_string);

int main() {
    char choice, ui_string[100];
    do {
        printf("Enter a word/phrase/sentence: ");
        fgets(ui_string, sizeof(ui_string), stdin);

        // converting all uppercase to lowercase
        for(int i = 0; ui_string[i] != '\0'; i++) {
            ui_string[i] = tolower(ui_string[i]);
        }
        
        string_sort(ui_string); // sorting using lab8 algo > char has their ASCII equivalent

        // printing alphabet characters only (a - z)
        for(int i = 0; ui_string[i] != '\0'; i++) {
            if(isalpha(ui_string[i])) {
                printf("%c", ui_string[i]);
            }
        }
        printf("\n");

        printf("Wanna sort again? (Y/N) ");
        scanf("%c", &choice);
        getchar(); // taking the newline -one index char- away
        printf("\n");
    } while(choice == 'Y' || choice == 'y' && choice != 'N' && choice != 'n');

    printf("Program Terminated...\n");
    return 0;
}

void string_sort(char *long_string) {
    char temp, *i, *j;
    for(i = long_string + 1; *i != '\0'; i++) {
        temp = *i;
        for(j = i - 1; j >= long_string; j--) {
            if(*j > temp) {
                *(j + 1) = *j;
            }
            else {
                break;
            }
        }
        *(j + 1) = temp;
    }
}

// var = pointing to that memory
// *var = accessing value in that memory
// pointer to the first char