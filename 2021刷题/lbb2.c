#include <stdio.h>
int main()
{
    int m = 1, n = 1, i = 1, j = 1;
    char ch, a[10][4] = {{'1'}, {'A', 'B', 'C'},
                                {'D', 'E', 'F'},
                                {'G', 'H', 'I'}, 
                                {'J', 'K', 'L'}, 
                                {'M', 'N', 'O'}, 
                                {'P', 'Q', 'R', 'S'}, 
                                {'T', 'U', 'V'}, 
                                {'W', 'X', 'Y', 'Z'}},
             b[3][10] = {{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'},
                         {'A', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},
                         {'Z', 'X', 'C', 'V', 'B', 'N', 'M'}};
    while (~scanf("%c", &ch))
    {
        getchar();
        for (i = 1; i < 9; i++)
            for (j = 0; j < 4; j++)
            {
                if (ch == a[i][j])
                    printf("%d\n", i+1);
            }
        for (m = 0; m < 3; m++)
            for (n = 0; n < 10; n++)
            {
                if (ch == b[m][n])
                    printf("%d %d\n", m+1, n+1);
            }
    }
}
