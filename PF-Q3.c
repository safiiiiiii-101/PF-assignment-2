#include <stdio.h> 
#include <string.h>

int w_compressor(char ar[], char n_ar[]);

int main()
{

    int size = 0;
    int nofstrings = 0;
    
    printf("Please enter the maximum length for amongst all of the strings that you would like to input in your array of strings: ");
    scanf("%d", &size);
    
    printf("Please enter the number of string you would like to input: ");
    scanf("%d", &nofstrings);
    
    while (getchar() != '\n');
    
    char ray[nofstrings][size + 1];
    char n_ray[nofstrings][size + 1];
    int t_rm_c = 0;
    
    for (int m = 0; m < nofstrings; m++)
    {
        printf("Enter string number: %d\n", m+1);
        fgets(ray[m], size + 1, stdin);
        ray[m][strcspn(ray[m], "\n")] = '\0';
        
        int r_c = w_compressor(ray[m], n_ray[m]);
        t_rm_c += r_c;
    }
    
    for (int m = 0; m < nofstrings; m++)
    {
        puts(n_ray[m]);
    } 
    //This total character removed count was not shown in the output display sample in the Assignment document
    //I have added this to show that the given requirements in the program have successfully and have been completely met
    printf("The removed characters count during the compression process was: %d\n", t_rm_c);
    
    return 0;
}

int w_compressor(char ar[], char n_ar[])
{    
    int removed = 0;
    int n_ar_index = 0;
    
    for (int m = 0; ar[m] != '\0'; m++)
    {
        if (m == 0 || ar[m] != ar[m - 1])
        {
            n_ar[n_ar_index] = ar[m];
            n_ar_index++;
        }
        else
        {
            removed++;
        }
    }
    n_ar[n_ar_index] = '\0';
    
    return removed;
}