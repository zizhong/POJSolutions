#include<stdio.h>
#include<string.h>
#define MAXN 30000 + 1
int main()
{
    int N, i, j, p, q, t, c;
    char a[MAXN];
    scanf("%d", &N);
    getchar();
    for(i = 0; i < N; i++)
    {
        scanf("%c", &a[i]);
        getchar();
    }
    a[N] = 0;
    c = i = 0; j = strlen(a) - 1;
    while(i < j)
    {
        if(a[i] > a[j])
            { printf("%c", a[j]); j--; c++; }
        else if(a[i] < a[j])
            { printf("%c", a[i]); i++; c++; }
        else
        {
            t = 1;
            p = i + 1; q = j - 1;
            while(p < q)
            {
                if(a[p] > a[q])
                    { t = !t; break; }
                else if(a[p] == a[q])
                    { p++; q--; }
                else break;
            }
            if(t) { printf("%c", a[i]); i++; c++; }
            else { printf("%c", a[j]); j--; c++; }
        }
        if(c % 80 == 0) printf("\n");
    }
    printf("%c\n", a[i]);
}
