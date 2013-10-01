#include <stdio.h>

int lose[5000010], k;

int dyna (int n)
{
    int i, j;
    lose[1] = 1, lose[2] = 2;
    for (i = 2, j = 1; lose[i] < n; i++)
    {
        while (lose[j] * k < lose[i]) j++;
        lose[i + 1] = lose[i] + lose[j];
    }
    while (1)
    {
          while (lose[i] > n) i--;
          if (lose[i] == n) return lose[i];
          n -= lose[i];
    }
}

int main ()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, a, kase, kr;
    scanf("%d", &kr);
    for (kase = 1; kase <= kr; kase++)
    {
        scanf("%d %d", &n, &k);
        a = dyna(n);
       // for(int i=1;i<=n;i++) printf("%d ",lose[i]);puts("");
        printf("Case %d: ", kase);
        if (a == n) printf("lose\n");
        else printf("%d\n", a);
    }
    return 0; 
}
