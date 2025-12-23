#include <stdio.h>   // Standard input-output functions

#define MAX 50       // Maximum number of income/expense entries

// Structure to store income details
typedef struct {
    char source[20]; // Source of income (e.g., Salary)
    float amount;    // Income amount
} Income;

// Structure to store expense details
typedef struct {
    char category[20]; // Expense category (e.g., Food)
    float amount;      // Expense amount
} Expense;

// Arrays to store multiple income and expense records
Income incomes[MAX];
Expense expenses[MAX];

// Counters to track number of records
int incomeCount = 0;
int expenseCount = 0;

// Function declarations
void addIncome();
void addExpense();
void viewSummary();

int main(void)
{
    int choice;

    // Infinite loop to keep the menu running
    while (1)
    {
        // Display main menu
        printf("\n============================\n");
        printf("   Personal Finance Manager\n");
        printf("============================\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        // Execute user choice using switch-case
        switch (choice)
        {
            case 1:
                addIncome();
                break;
            case 2:
                addExpense();
                break;
            case 3:
                viewSummary();
                break;
            case 4:
                printf("Thank you for using the application!\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a new income entry
void addIncome()
{
    // Take income source input
    printf("Enter income source: ");
    scanf("%s", incomes[incomeCount].source);

    // Take income amount input
    printf("Enter income amount: ");
    scanf("%f", &incomes[incomeCount].amount);

    // Increase income count after adding entry
    incomeCount++;

    printf("Income added successfully!\n");
}

// Function to add a new expense entry
void addExpense()
{
    // Take expense category input
    printf("Enter expense category: ");
    scanf("%s", expenses[expenseCount].category);

    // Take expense amount input
    printf("Enter expense amount: ");
    scanf("%f", &expenses[expenseCount].amount);

    // Increase expense count after adding entry
    expenseCount++;

    printf("Expense added successfully!\n");
}

// Function to calculate and display financial summary
void viewSummary()
{
    float totalIncome = 0;
    float totalExpense = 0;

    // Calculate total income
    for (int i = 0; i < incomeCount; i++)
    {
        totalIncome += incomes[i].amount;
    }

    // Calculate total expenses
    for (int i = 0; i < expenseCount; i++)
    {
        totalExpense += expenses[i].amount;
    }

    // Display summary
    printf("\n------- Summary -------\n");
    printf("Total Income:  ₹%.2f\n", totalIncome);
    printf("Total Expense: ₹%.2f\n", totalExpense);
    printf("Balance:       ₹%.2f\n", totalIncome - totalExpense);
}
