#include <stdio.h>

int p_r = 4;
int p_c = 4;
int p_row = 4;
int p_col = 4;
char g[5][5] = 
{
    {' ', ' ', 'I', 'X', ' '},
    {' ', 'X', ' ', ' ', ' '},
    {'I', ' ', 'X', 'X', ' '},
    {' ', ' ', ' ', 'I', 'X'},
    {' ', 'X', ' ', ' ', 'P'}
};

void p_g();
int v_m(char inp);
void u_p();

int main() 
{
    char input = ' ';

    while (input != 'q' && input != 'Q') 
    {
        p_g();
        printf("Enter a move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &input);

        if (input != 'q' && input != 'Q' && v_m(input)) 
        {
            u_p();
        } 
        else if (input != 'q' && input != 'Q') 
        {
            printf("Unfortunately, that's an Invalid move, Please try again\n");
        }
    }

    return 0;
}

void p_g() 
{
    int i, j;
    for (i = 0; i < 5; i++) 
    {
        printf("{");
        for (j = 0; j < 5; j++) 
        {
            if (j != 4) 
            {
                printf("%c|", g[i][j]);
            } 
            else 
            {
                printf("%c", g[i][j]);
            }
        }
        printf("}\n");
    }
}

int v_m(char inp) 
{
    int row = p_r, col = p_c;

    if (inp == 'w' || inp == 'W') 
    {
        row = p_r - 1;
    } 
    else if (inp == 'a' || inp == 'A') 
    {
        col = p_c - 1;
    } 
    else if (inp == 's' || inp == 'S') 
    {
        row = p_r + 1;
    } 
    else if (inp == 'd' || inp == 'D') 
    {
        col = p_c + 1;
    }



    if (row > 4 || col > 4 || row < 0 || col < 0) 
    {
        return 0; // false
    } 
    else if (g[row][col] == 'X') 
    {
        return 0; // false
    } 
    else 
    {
        p_row = p_r;
        p_col = p_c;
        p_r = row;
        p_c = col;
        return 1; // true
    }
}

void u_p() 
{
    if (g[p_r][p_c] == 'I') 
    {
        printf("You collected an item.....\n");
        g[p_r][p_c] = ' '; 
    }
    g[p_row][p_col] = ' '; 
    g[p_r][p_c] = 'P';   
}
