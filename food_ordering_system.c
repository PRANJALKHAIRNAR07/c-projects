#include <stdio.h>      // For input/output functions
#include <string.h>     // For string comparison functions like strcmp

#define MAX_LEN 50      // Maximum length for item names

// Structure to store food or beverage details
typedef struct {
    char name[MAX_LEN]; // Name of the item
    int price;          // Price of the item
} Item;

int main(void)
{
    // Food menu
    Item food[] = {
        {"Burger", 100},
        {"Fries", 50},
        {"Salad", 80}
    };

    // Beverage menu
    Item drinks[] = {
        {"Coke", 50},
        {"Sprite", 67},
        {"Water", 20}
    };

    int food_count = 3;     // Number of food items
    int drink_count = 3;    // Number of beverages
    int total = 0;          // Stores total bill amount
    char order[MAX_LEN];    // Stores user input (food or drink name)
    char choice;            // Stores user's beverage choice (y/n)

    // Welcome message
    printf("🍽️ Welcome to Foodify 🍽️\n\n");

    // Display food menu
    printf("Food Menu:\n");
    for (int i = 0; i < food_count; i++)
    {
        printf("%s - ₹%d\n", food[i].name, food[i].price);
    }

    // Take food order from user
    printf("\nEnter food item: ");
    scanf("%s", order);

    int found = 0; // Flag to check if food item exists

    // Check if the entered food item is available
    for (int i = 0; i < food_count; i++)
    {
        if (strcmp(order, food[i].name) == 0)
        {
            total += food[i].price; // Add price to total bill
            found = 1;
            break;
        }
    }

    // If food item is not found, exit the program
    if (!found)
    {
        printf("Food item not available!\n");
        return 0;
    }

    // Ask user if they want a beverage
    printf("Do you want a beverage? (y/n): ");
    scanf(" %c", &choice);

    // If user chooses yes, show beverage menu
    if (choice == 'y' || choice == 'Y')
    {
        printf("\nBeverage Menu:\n");
        for (int i = 0; i < drink_count; i++)
        {
            printf("%s - ₹%d\n", drinks[i].name, drinks[i].price);
        }

        // Take beverage order
        printf("\nEnter beverage: ");
        scanf("%s", order);

        // Check if beverage exists and add price
        for (int i = 0; i < drink_count; i++)
        {
            if (strcmp(order, drinks[i].name) == 0)
            {
                total += drinks[i].price; // Add beverage price
                break;
            }
        }
    }

    // Display final bill
    printf("\n🧾 Total Bill: ₹%d\n", total);
    printf("Thank you for ordering with Foodify!\n");

    return 0; // End of program
}
