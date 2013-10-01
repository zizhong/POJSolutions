#include<stdio.h>
#include<string.h>
#define N 1000001
int question[N];
int bonus[2][2]={10,10,20,40};
int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,sum=0;
    scanf("%d",&n);
    while(n--)
    {
        int q,a,x;
        scanf("%d%d%d",&q,&a,&x);
        if(a)
            question[q]++;
        sum+=bonus[a][x];
        if(question[q]>1) sum+=(question[q]-1)*10;
    }
    printf("%d\n",sum);
}
