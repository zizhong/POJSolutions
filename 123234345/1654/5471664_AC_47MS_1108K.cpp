#include<stdio.h>
#include<string.h>
int dic[][2]={{0,0},{-1,-1},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};
__int64 Area(__int64 x1,__int64 y1,__int64 x2,__int64 y2)
{
        return x1*y2-x2*y1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[1000001];
        scanf("%s",s);
        int len=strlen(s);
        __int64 A=0,x1=0,y1=0,x2=0,y2=0;
        for(int i=0;i<len;i++)
        {
            x2+=dic[s[i]-'0'][0];
            y2+=dic[s[i]-'0'][1];
            if(s[i]=='5') x2=y2=0;
            A+=Area(x1,y1,x2,y2);
            x1=x2,y1=y2;
        }
        if(A<0) A=0-A;
        __int64 A1=A/2;
        if(A1*2==A) printf("%I64d\n",A1);
        else printf("%I64d.5\n",A1);
    }
}
