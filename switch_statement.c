#include <stdio.h>

int main(void)
{
    int x;

    printf("Enter switch state (0 = OFF, 1 = ON): ");
    scanf("%d", &x);

    switch (x)
    {
        case 1:
            printf("Switch is ON\n");
            break;

        case 0:
            printf("Switch is OFF\n");
            break;

        default:
            printf("Invalid input! Enter only 0 or 1.\n");
    }

    return 0;
}
