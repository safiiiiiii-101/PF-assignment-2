#include <stdio.h>

int f_m(int num);

int main(void) 
{
    int n;

    printf("Enter the no# of matchsticks: ");
    scanf("%d", &n);

    int result = f_m(n);

    if (result == -1) 
    {
        printf("It's impossible for A to guarantee a win\n");
    }
    else 
    {
        printf("A should pick %d matchsticks on his first turn to guarantee a win", result);
    }

    return 0;
}

int f_m(int num) 
{
    if (num % 5 == 0) 
    {
        return -1;
    }
    else 
    {
        return (num % 5);
    }
}
