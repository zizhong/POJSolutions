#include<stdio.h>
#include<string.h>
int cton(char c)
{
    if(c<='z'&&c>='a')
        return c-'a'+1;
    if(c=='_') return 0;
    return 27;
}
char ntoc(int d)
{
     if(d==0) return '_';
     if(d==27) return '.';
     return 'a'+d-1;
}
int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int k;
    while(scanf("%d",&k)&&k)
    {
        char pt[81],ct[81];
        int pc[81],cc[81];
        scanf("%s",&ct);
        int n=strlen(ct),i;
        for(i=0;i<n;i++)
            cc[i]=cton(ct[i]);
        for(i=0;i<n;i++)
        {
           for(pc[k*i%n]=0;pc[k*i%n]<28;pc[k*i%n]++)
           {
                int f=pc[k*i%n]-i;
                if((cc[i]-f)%28==0)
                    break;
           }
        }
        for(i=0;i<n;i++)
           printf("%c",ntoc(pc[i]));
        printf("\n");  
    }
}
