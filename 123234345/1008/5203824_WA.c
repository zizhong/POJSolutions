#include<stdio.h>
char tz[21][10]={"","imix", "ik", "akbal", "kan", "chicchan", "cimi","manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
char haad[20][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu"};
int mon(char *s)
{
    int i=0;
    for(;i<20;i++)
      if(strcmp(s,haad[i])==0) break;
    return i;
}
int main()
{
    int n,t;
    scanf("%d",&n);
    printf("%d\n",n);
    while(n--)
    {
       int d,dh,yh,dnt,yt,dct;
       char mh[10];
       scanf("%d.%s%d",&dh,mh,&yh);
       d=365*yh+(mon(mh))*20+dh+1;
       yt=d/260;
       d%=260;
       dnt=d%13;
       if(dnt==0) dnt=13;
       dct=d%20;
       if(dct==0) dct=20;
       printf("%d %s %d\n",dnt,tz[dct],yt);
    }
}
