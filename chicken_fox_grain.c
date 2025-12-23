#include <stdio.h>
#include <ctype.h>

void print_state(int chicken, int fox, int grain, int boat, int moves)
{
    printf("***************************************\n");
    printf("            Current State              \n");
    printf("***************************************\n");

    printf("Chicken: %s\n", chicken ? "Left" : "Right");
    printf("Fox: %s\n", fox ? "Left" : "Right");
    printf("Grain: %s\n", grain ? "Left" : "Right");
    printf("Boat: %s\n", boat ? "Left" : "Right");
    printf("Total Valid Moves: %d\n", moves);

    printf("***************************************\n\n");

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (row == 0 && col == (chicken ? 0 : 3)) printf(" C ");
            else if (row == 1 && col == (fox ? 0 : 3)) printf(" F ");
            else if (row == 2 && col == (grain ? 0 : 3)) printf(" G ");
            else if (row == 3 && col == (boat ? 0 : 3)) printf(" B ");
            else if (col == 1 || col == 2) printf(" ~ ");
            else printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    int chicken = 1, fox = 1, grain = 1, boat = 1;
    int moves = 0;

    printf("Welcome to the Chicken, Fox, and Grain Game!\n");

    while (1)
    {
        print_state(chicken, fox, grain, boat, moves);

        if (chicken == 0 && fox == 0 && grain == 0)
        {
            printf("Congratulations! You solved the puzzle!\n");
            break;
        }

        if ((chicken == fox && chicken != boat) ||
            (chicken == grain && chicken != boat))
        {
            printf("Game Over! Chicken got eaten!\n");
            break;
        }

        char move;
        printf("Move (c = chicken, f = fox, g = grain, n = none): ");
        scanf(" %c", &move);
        move = tolower(move);

        int *item = NULL;
        if (move == 'c') item = &chicken;
        else if (move == 'f') item = &fox;
        else if (move == 'g') item = &grain;

        if (item != NULL)
        {
            *item = !(*item);
            boat = !boat;
            moves++;
        }
        else if (move == 'n')
        {
            boat = !boat;
        }
        else
        {
            printf("Invalid move!\n");
        }
    }

    return 0;
}
