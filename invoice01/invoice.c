#include <stdio.h>
#include <string.h>

//I suggest you put all this code in a function called invoice()
int main() {
    // Declare variables
    int invoiceNumber;
    float itemPrice, totalPrice = 0;
    char itemName[50];
    int itemCount = 0;

    // Get user input for invoice number
    printf("Enter invoice number: ");
    scanf("%d", &invoiceNumber);

    // Prompt user for item details until they choose to stop
    while (1) {
        printf("Enter item name (enter 'done' to stop): ");
        scanf("%s", itemName);
        if (strcmp(itemName, "done") == 0) {
            break;
        }

        printf("Enter item price: ");
        scanf("%f", &itemPrice);

        printf("Enter item count: ");
        scanf("%d", &itemCount);

        // Calculate total price for this item
        float itemTotalPrice = itemPrice * itemCount;

        // Add this item's total price to the overall total price
        totalPrice += itemTotalPrice;
    }

    // Open the file for writing
    char filename[50];
    sprintf(filename, "Invoice_%d.txt", invoiceNumber);
    FILE *fptr = fopen(filename, "w");

    // Write the invoice to the file
    fprintf(fptr, "Invoice #%d\n", invoiceNumber);
    fprintf(fptr, "Item\t\tCount\tPrice\tTotal\n");
    fprintf(fptr, "------------------------------------------------\n");
    float vat = totalPrice * 0.05;
    fprintf(fptr, "\n");
    fprintf(fptr, "\t\t\t\tSubtotal: %.2f\n", totalPrice);
    fprintf(fptr, "\t\t\t\tVAT: %.2f\n", vat);
    fprintf(fptr, "\t\t\t\tTotal Amount: %.2f\n", totalPrice + vat);

    // Close the file
    fclose(fptr);

    printf("Invoice generated and stored in file %s\n", filename);

    return 0;
}
