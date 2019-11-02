#include <stdio.h>

void    draw(int n)
{
    int i;
    int j;

    i = 0;
    while (i < n)
    {
        j = 1;
        while (j < n * 2)
        {
            if (j == n || j == (n + i) || j == (n - i))
                printf("* ");
            else
                printf(" ");
            // printf("*");
            j++;
        }
        printf("\n");
        i++;
    }
}

int main()
{
    draw(4);
    return (0);
}