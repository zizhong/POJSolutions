#include<stdio.h>
#include<string.h>
#include<stdlib.h>
bool map[52][52];
int num,n,list[11];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
bool canput(int r,int c,int len)
{
     int i,j;
     if(r+len-1>2*n||c+len-1>4*n) return 0;
     if(c%2==0)
     {
         for(i=r;i<r+len;i++)
            for(j=0;j<2*len-1-2*(i-r);++j)
              if(map[i][j+c+2*(i-r)]) return 0;
     }
     else
     {
         for(i=r;i<r+len;i++)
            for(j=c;j<c+2*(i-r+1)-1;++j)
              if(map[i][j]) return 0;
     }
     return 1;
}
void put(int r,int c,int len)
{
     int i,j;
     if(c%2==0)
     {
         for(i=r;i<r+len;i++)
            for(j=0;j<2*len-1-2*(i-r);++j)
              map[i][j+c+2*(i-r)]=1;
     }
     else
     {
         for(i=r;i<r+len;i++)
            for(j=c;j<c+2*(i-r+1)-1;++j)
              map[i][j]=1;
     }
}
void take(int r,int c,int len)
{
     int i,j;
     if(c%2==0)
     {
         for(i=r;i<r+len;i++)
            for(j=0;j<2*len-1-2*(i-r);++j)
              map[i][j+c+2*(i-r)]=0;
     }
     else
     {
         for(i=r;i<r+len;i++)
            for(j=c;j<c+2*(i-r+1)-1;++j)
              map[i][j]=0;
     }
}
bool dfs(int r,int c)
{
     if(r>2*n) return 1;
     if(c>4*n) return dfs(r+1,1);
     int i;
     if(map[r][c])
     {
         for(i=c+1;i<=4*n;i++)
            if(!map[r][i]) break;
         return dfs(r,i);
     }
     for(i=1;i<=num;i++)
     {
         if(canput(r,c,list[i]))
         {
            put(r,c,list[i]);
            if(dfs(r,c+1)) return 1;
            take(r,c,list[i]);
         }
         else return 0;
     }
     return 0;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
         scanf("%d%d",&n,&num);
         for(int i=1;i<=num;i++)
            scanf("%d",&list[i]);
         qsort(list+1,num,sizeof(int),cmp);
         
         int flag=0;
         for(int i=1;i<=num;i++)
             if(n%list[i]==0)
             {
                 flag=1;
                 printf("YES\n");
                 break;
             }
         if(flag) continue;
         for(int i=1;i<num;i++)
         {
             for(int j=i+1;j<=num;j++)
             {
                 if(list[j]%list[i]==0)
                 {
                     for(int k=j+1;k<num;k++) list[k]=list[k+1];
                     --num;
                     --j;
                 }
             }
             if(list[i]>n)
             {
                 num=i-1;
                 break;
             }
         }
         memset(map,1,sizeof(map));
         for(int j=1;j<=n;j++)
             for(int k=1;k<=2*n+1+(j-1)*2;k++)
                 map[j][k]=0;
         for(int j=n+1;j<=n+n;j++)
            for(int k=(j-n)*2;k<=4*n;k++)
                 map[j][k]=0;
         if(dfs(1,1)) printf("YES\n");
         else printf("NO\n");
    }
}
