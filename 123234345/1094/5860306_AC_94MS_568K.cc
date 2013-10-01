#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int g[26][26];
int floyd()
{
    for(int k=0;k<26;k++)
       for(int i=0;i<26;i++)
          for(int j=0;j<26;j++)
             g[i][j]=g[i][j]||(g[i][k]&&g[k][j]);
}
int cmp(const void *a,const void *b)
{
    return ((int *)b)[0]-((int *)a)[0];
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(int i=0;i<26;i++)
           for(int j=0;j<26;j++)
              g[i][j]=0;
        char s[4];
        int inc=0;
        int mark=0;
        for(int i=1;i<=m;i++)
        {           
            scanf("%s",s);
            if(inc||mark) continue;
            int a=s[0]-'A',b=s[2]-'A';
            if(g[b][a]||a==b)
            {
                //printf("%d\n",g[b][a]);
                inc=1;                
                printf("Inconsistency found after %d relations.\n",i);
                continue;
            }
            g[a][b]=g[a][a]=g[b][b]=1;
            floyd();
            int rank[26][2]={0};
            for(int j=0;j<26;j++) rank[j][1]=j;
            for(int k=0;k<n;k++)
               for(int j=0;j<n;j++)
                  rank[k][0]+=g[k][j];
            qsort(rank,n,sizeof(int)*2,cmp);
            int flag=0;
            for(int j=0;j<n;j++)
              if(rank[j][0]!=n-j)
              {
                flag=1;
                break;
              }
            if(flag==0)
            {
                mark=1;
                printf("Sorted sequence determined after %d relations: ",i);
                for(int k=0;k<n;k++)
                    printf("%c",rank[k][1]+'A');
                printf(".\n");
            }
        }
        if(mark==0&&inc==0) printf("Sorted sequence cannot be determined.\n");
    }
}
