#include<stdio.h>
#include<string.h>
const int N=62;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m;
        char dna[10][N],s1[N],ans[N]={0},l=0;
        scanf("%d",&m);
        for(int i=0;i<m;i++) scanf("%s",&dna[i]);
        for(int i=0;i<59;i++)
        {
              for(int j=3;j<61-i;j++)
              {
                   strncpy(s1,dna[0]+i,j);
                   s1[j]=0;
                   int flag=1;
                   for(int k=1;k<m;k++)
                   {
                        if(!strstr(dna[k],s1))
                        {
                            flag=0;break;
                        }
                   }
                   if(flag)
                   {
                        if(l<j) strcpy(ans,s1),l=j;
                        else if(l==j)
                        {
                             if(strcmp(ans,s1)>0) strcpy(ans,s1);                             
                        }        
                   }
              }
        }
        puts(l>2?ans:"no significant commonalities");
    }
}
