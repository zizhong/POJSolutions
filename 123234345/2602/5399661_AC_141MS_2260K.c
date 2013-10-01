#include<stdio.h>
int main()
{
    char a[1000000], b[1000000], j;
    int N, i;
    scanf("%d",&N);
    getchar();
    for (i = 0; i < N; i++)
    {
        a[i] = getchar();
        getchar();
        b[i] = getchar();
        getchar();
    }
    j = 0;
    for (i = N - 1; i >= 0; i--)
    {
        a[i] += b[i] + j - 48;
        j = 0;
        if (a[i] > 57)
        {
            a[i] -= 10;
            j = 1;
        }
    }
    for (i = 0; i < N; i++)
        putchar(a[i]);
    putchar('\n');
    return 0;
}