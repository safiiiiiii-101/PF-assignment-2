#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_GROUPS 100
#define MAX_STRINGS 100

int main(void) 
{
    int size = 0;
    int nstrings = 0;

    printf("Please provide the maximum length of each transaction string: ");
    scanf("%d", &size);

    printf("Please provide the number of transaction strings you would like to evaluate: ");
    scanf("%d", &nstrings);

    while (getchar() != '\n'); 

    char transactions[MAX_STRINGS][MAX_STR_LEN + 1];
    char sorted_str[MAX_STR_LEN + 1];
    char groups[MAX_GROUPS][MAX_STRINGS][MAX_STR_LEN + 1];
    int g_counts[MAX_GROUPS] = {0};
    int g_count = 0;

    for (int m = 0; m < nstrings; m++) 
    {
        printf("Enter string number %d: ", m + 1);
        fgets(transactions[m], size + 1, stdin);
        transactions[m][strcspn(transactions[m], "\n")] = '\0';
    }

    for (int m = 0; m < nstrings; m++) 
    {
        strcpy(sorted_str, transactions[m]);
        int len = strlen(sorted_str);

        for (int n = 0; n < len - 1; n++) 
        {
            for (int o = n + 1; o < len; o++) 
            {
                if (sorted_str[n] > sorted_str[o]) 
                {
                    char temp = sorted_str[n];
                    sorted_str[n] = sorted_str[o];
                    sorted_str[o] = temp;
                }
            }
        }

        int f = 0;

        for (int n = 0; n < g_count; n++) 
        {
            if (strcmp(groups[n][0], sorted_str) == 0) 
            {
                strcpy(groups[n][g_counts[n] + 1], transactions[m]);
                g_counts[n]++;
                f = 1;
                break;
            }
        }

        if (!f) 
        {
            strcpy(groups[g_count][0], sorted_str);
            strcpy(groups[g_count][1], transactions[m]);
            g_counts[g_count] = 1;
            g_count++;
        }
    }

    printf("[");

    for (int m = 0; m < g_count; m++) 
    {
        printf("[");

        for (int n = 1; n <= g_counts[m]; n++) 
        {
            printf("'%s'", groups[m][n]);
        }

        printf("]");

        if (m < g_count - 1) 
        {
            printf(", "); 
        }
    }

    printf("]\n");

    return 0;
}