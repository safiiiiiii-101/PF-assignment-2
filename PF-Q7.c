#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define r 6
#define c 5
#define ID_ROW "0826"

void c_ray(char ray[r][c]); 
void p_ray(char ray[r][c]);
int s_string(char ray[r][c], char search_str[]);

int main() 
{
    char ray[r][c];
    int s = 0;
    char search_str[100]; 

    while (1) 
    {
        c_ray(ray);
        p_ray(ray);

        while (1) 
        {
            printf("Search Str= ");
            scanf("%99s", search_str);
      
            for (int m = 0; search_str[m]; m++) 
            {
                search_str[m] = toupper(search_str[m]);
            }

            if (strcmp(search_str, "END") == 0) 
            {
                break;
            }

            if (s_string(ray, search_str)) 
            {
                s++;
                printf("%s is present score %d\n", search_str, s);
            } 
            else 
            {
                s -= 1;

                printf("%s is not present Score %d\n", search_str, s);
            }
        }

        printf("New array generated..........\n");
    }

    return 0;
}

void c_ray(char ray[r][c]) 
{
    srand(time(0));
    
    for (int m = 0; m < r - 1; m++) 
    {
        for (int n = 0; n < c; n++) 
        {
            ray[m][n] = 'A' + rand() % 26;
        }
    }
    
    for (int n = 0; n < strlen(ID_ROW); n++) 
    {
        ray[r - 1][n] = ID_ROW[n];
    }
    ray[r - 1][c - 1] = 'A' + rand() % 26;
}

void p_ray(char ray[r][c]) 
{
    for (int m = 0; m < r; m++) 
    {
        for (int n = 0; n < c; n++) 
        {
            printf("%c ", ray[m][n]);
        }

        printf("\n");
    }

    printf("\n"); 
}

int s_string(char ray[r][c], char search_str[]) 
{
    int len = strlen(search_str);

    for (int m = 0; m < r; m++) {
        for (int n = 0; n <= c - len; n++) 
        {
            if (strncmp(ray[m] + n, search_str, len) == 0) 
            {
                return 1; 
            }
        }
    }

    for (int n = 0; n < c; n++) 
    {
        for (int m = 0; m <= r - len; m++) 
        {
            int found = 1;
            for (int k = 0; k < len; k++) 
            {
                if (ray[m + k][n] != search_str[k]) 
                {
                    found = 0;
                    break;
                }
            }

            if (found) 
            {
                return 1; 
            }
        }
    }

    return 0; 
}