#include<stdio.h>
const int N=40000;
__int64 hum[N];
__int64 _min(__int64 a,__int64 b){return a>b?b:a;}
int main()
{
    int p1,p2,p3,n;
    while(scanf("%d%d%d%d",&p1,&p2,&p3,&n)!=EOF)
    {
        hum[0]=1;
        int i1=0,i2=0,i3=0;
        for(int i=1;i<=n;i++)
        {
              hum[i]=_min(hum[i1]*p1,_min(hum[i2]*p2,hum[i3]*p3));
              if(hum[i]==hum[i1]*p1) i1++;
              if(hum[i]==hum[i2]*p2) i2++;
              if(hum[i]==hum[i3]*p3) i3++;
        }
        printf("%I64d\n",hum[n]);
    }    
}
