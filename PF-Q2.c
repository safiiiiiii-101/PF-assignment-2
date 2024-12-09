#include <stdio.h>
#include <string.h>

void f_s_counter(char ray[]);

int main(void)
{
    int m_size = 0;
    int word = 0;

    printf("Please enter the max number of characters ou would like in one slogan: ");
    scanf("%d", &m_size);

    printf("Please enter the number of multi syllable words you would like to analyse: ");
    scanf("%d", &word);

    //clearing the buffer from the new line character that scanf function left when it made the last scan
    while (getchar() != '\n');

    char slogan[word][m_size];

    for (int  m = 0; m < word; m++)
    {
        printf("Please enter your multi syllable word number %d: ", m+1);
        fgets(slogan[m], m_size, stdin);

        //clearing out the new line character from each string scanned via fgets()
        int len = strlen(slogan[m]);                       
        if (len > 0 && slogan[m][len - 1] == '\n')
        {
            slogan[m][len - 1] = '\0';
        }
    }

    for (int m = 0; m < word; m++)
    {
        f_s_counter(slogan[m]);
    }

    return 0;
        
}

void f_s_counter(char ray[])
{   
    int freq[256] = {0};

    for (int x = 0; ray[x] != '\0'; x++)
    {
        freq[(unsigned char) ray[x]]++;
    }

    printf("For \"%s\": {", ray);

    int first = 1;

    for (int x = 0; x <= 255; x++)
    {   
        if  (freq[x] > 0 && x != 32)    //as 332 repressents the space character
        {
            if (!first)
            {
                printf(", ");
            }
            printf("'%c': %d", (char) x, freq[x]);
            first = 0;
        }
        
    }
    printf("}\n");
    
}