#include <stdio.h>

int main(void)
{   
    int c = 0;

    printf("Please enter the count of the values you would like to store in your array: \n");
    scanf("%d", &c);

    int ray[c];

    printf("Please enter the values in your array that the program will display as a histogram: \n");

    for (int m = 0; m < c; m++)
    {
        printf("Elmement number - %d in index: \n", m);
        scanf("%d", &ray[m]);
    }

    printf("\n");

    printf("Horzontal Histogram: \n");
    
    int h_printer = 0;

    for (int m = 0; m < c; m++)
    {
        h_printer = ray[m];

        for (int n = 0; n < h_printer; n++)
        {
            printf("*");
        }

        printf("\n");

    }

    printf("\n");

    printf("Vertical Histogram: \n");
    
    int h_v = ray[0];

    for (int m = 1; m < c; m++)
    {
        if (ray[m] > h_v)
        {
            h_v = ray[m];
        }
    }

    for (int max = h_v; max > 0; max--)
    {
        for (int m = 0; m < c; m++)
        {
            if (ray[m] >= max)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    
    return 0;
        
}