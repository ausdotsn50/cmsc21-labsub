/*A C program that calculates item expenses, allowing cost split with others depending on user choice
Submitted by: Angela Denise Almazan*/
#include <stdio.h>
#include <string.h>

#define BUDGET_CAP 50 // party capacity

struct expenses {
    char items[50];
    float price;
    int quantity;
};

int main() {
    int iter = 0, add_choice;
    struct expenses party_exp[BUDGET_CAP]; // array of expenses

    do {
        printf("Enter item details:\n");

        printf("Item: ");
        fgets(party_exp[iter].items, sizeof(party_exp[iter].items), stdin);
        
        printf("Price: ");
        scanf("%f", &party_exp[iter].price);

        printf("Quantity: ");
        scanf("%d", &party_exp[iter].quantity);

        printf("Press '1' to add more items. Otherwise, any other digit: ");
        scanf("%d", &add_choice);
        getchar();

        iter++;
    } while(add_choice == 1 && iter < BUDGET_CAP);

    float total = 0;
    printf("All details:\nItem\t\tPrice\t\tQuantity\t\tTotal\n");
    for(int i = 0; i < iter; i++) {
        printf("%s\t\t%.2f\t\t%d\t\t\t%.2f\n", party_exp[i].items, party_exp[i].price, party_exp[i].quantity, party_exp[i].price * party_exp[i].quantity);
        total += party_exp[i].price * party_exp[i].quantity;
    }

    int div_choice, friends;
    printf("Total expense: %.2f\n", total);
    printf("Press '1' to divide expense with friends. Otherwise, any other digit: ");
    scanf("%d", &div_choice);

    if(div_choice == 1) {
        printf("How many friends to divide with? ");
        scanf("%d", &friends);
        
        if (friends <= 0) {
            printf("Invalid number of friends.\n");
            return 1;
        }
        
        float share_per_friend = total / (friends + 1);
        printf("Each friend shall contribute: %.2f\n", share_per_friend);
    }

    return 0;
}
