#include <stdio.h>
#include <math.h>
#include <string.h>
/* POJ 3279: Filptile */

int map[16][16], m, n;
int serial[16][16];

int main ()
{
  //  freopen("in.txt","r",stdin);
  //   freopen("key.txt","w",stdout);
    void add ();
    int check ();
    int i, j, flag = 0;
   
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
           
    memset(serial, 0, sizeof(serial));
    for (i = 0; i < (int)(pow(2, n)); i++)
    {
        if (check()) { flag = 1; break; }
        add();
    }
   
    if (flag)
    {
       for (i = 0; i < m; i++)
       {
           for (j = 0; j < n; j++)
               printf("%d%c", serial[i][j],j<n-1?' ':'\n');
       }       
    }
    else printf("IMPOSSIBLE\n");
    return 0;
}

void add ()
{
     int i = 0;
     serial[0][0]++;
     while (serial[0][i] > 1)
     {
           serial[0][i + 1] += serial[0][i] / 2;
           serial[0][i++] %= 2;
     }
     return;
}

int check ()
{
    int copy[16][16], i, j, k;
   
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            copy[i][j] = map[i][j];
           
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (serial[i][j] == 1)
            {      
               copy[i][j] = 1 - copy[i][j];
               if (j > 0) copy[i][j - 1] = 1 - copy[i][j - 1];
               if (j < n - 1) copy[i][j + 1] = 1 - copy[i][j + 1];
               if (i < m - 1) copy[i + 1][j] = 1 - copy[i + 1][j];
            }
        }
       
        if (i < m - 1) for (j = 0; j < n; j++)
            serial[i + 1][j] = copy[i][j];
    }
    for (i = 0; i < n; i++)
        if (copy[m - 1][i] == 1) return 0;

    return 1;
}
