#include <stdio.h>
#include <cs50.h>


void drawline(int blanks, int points);

int main(void)
{
    int PyramHeight = 0;
    while (PyramHeight <= 0 || PyramHeight > 8)
    {
        PyramHeight = get_int("Pyramid Height?: ");
    }
    int fills = 0;
    while (fills < PyramHeight)
    {
        fills += 1;
        drawline(PyramHeight - fills, fills);
    }

}

/* Function to draw the mirrored line*/
void drawline(int blanks, int fills)
{
    int n = 0;
    for (n = 1; n <= blanks; n = n + 1)
    {
        printf(" ");
    }
    for (n = 1; n <= fills; n = n + 1)
    {
        printf("#");
    }
    printf("  ");
    for (n = 1; n <= fills; n = n + 1)
    {
        printf("#");
    }

    printf("\n");
}

