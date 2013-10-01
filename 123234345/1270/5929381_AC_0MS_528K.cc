#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char g[22][22],str1[75],str2[250],color[250],in[22];
int mark[150],l;
int cmp(const void *a,const void *b)
{
    return *(char *)a-*(char *)b;
}
void Recur(int level,int n,char cc[])
{
     int i,j,k,m;
     for(i=0;i<level-1;i++) if(g[mark[cc[i]]][n]) return ;
     cc[level-1]=str1[n];
     if(level==l)
     {
         cc[level]='\0';
         puts(cc);
         return ;
     }
     color[n]=1;
     for(i=0;i<l;i++)
        if(g[n][i]==0&&color[i]==0)
           Recur(level+1,i,cc);
     color[n]=0;
}
void Set()
{
     int i,k=0;
     for(i=0;str1[i];i++)
         if(str1[i]!=' ') str1[k++]=str1[i];
     str1[k]='\0';
     l=k;
     qsort(str1,k,sizeof(str1[0]),cmp);
     for(i=0;str1[i];i++) mark[str1[i]]=i;   
}
void Mark()
{
     int i,j,k=0;
     for(i=0;str2[i];i++)
        if(str2[i]!=' ') str2[k++]=str2[i];
     str2[k]='\0';
     for(i=0;str2[i];i+=2)
        g[mark[str2[i+1]]][mark[str2[i]]]=1;
     /*for(k=0;k<l;k++)
        for(i=0;i<l;i++)
           for(j=0;j<l;j++)
             g[i][j]=g[i][j]||(g[i][k]&&g[k][j]);
     memset(in,0,sizeof(in));
     for(i=0;i<l;i++)
        for(j=0;j<l;j++)
          in[i]+=g[j][i];*/
}
void Cal()
{
     char cc[50];
     for(int i=0;str1[i];i++)
        Recur(1,i,cc);
}
int main()
{
    int kcase=0;
    while(gets(str1))
    {
        memset(g,0,sizeof(g));
        for(int i=1;i<22;i++) g[i][i]=i;
        if(kcase++) puts("");
        Set();
        gets(str2);
        Mark();
        Cal();
    }
}
