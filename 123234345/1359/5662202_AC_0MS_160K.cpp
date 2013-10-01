#include<stdio.h>
#include<string.h>
int a[300][2];
int num,n;
int index(int x)
{
    int i;
    for(i=0;i<num;i++)
        if(a[i][0]==x) return i;
    a[num][0]=x;
    return num++;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        num=0;
        memset(a,0,sizeof(a));
        int flag=0;
        scanf("%d",&n);
        while(n--)
        {
            int x,y,z;
            char s1[5],s2[5];
            scanf("%d%d%s%d%s",&x,&y,s1,&z,s2);
            if(flag) continue;
            int xi=index(x),yi=index(y),zi=index(z);
            if(s1[0]=='N'&&s2[0]=='N')
            {
                 a[xi][1]=-2;
                 a[yi][1]=a[zi][1]=1;
            }
            else if(s1[0]=='Y'&&s2[0]=='Y')
                 a[yi][1]=a[zi][1]=1;
            else if(s1[0]=='N')
                 a[xi][1]--,a[yi][1]--,a[zi][1]=1;
            else a[xi][1]--,a[zi][1]--,a[yi][1]=1;            
        }
        int min=1,mi=-1;
        for(int i=0;i<num;i++)
           if(a[i][1]<min) min=a[i][1],mi=i;
        int nu=0;
        for(int i=0;i<num;i++)
           if(a[i][1]==min) nu++;
        if(min>0||nu>1) printf("impossible\n");
        else printf("%d\n",a[mi][0]);
    }
}
