#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
bool found; 
int map[MAX][MAX],n,m,col[MAX];
bool check(int d, int color) 
{ 
int i;
  for(i=1; i<=n; i++) 
    if(map[i][d]==1&&color==col[i] && i!=d)
      return false; 
  return true; 
}

bool DFS(int d) 
{
int i; 
  if(d>n) 
    return true; 
  for(i=1; i<=4; i++) 
  {  
    if(check(d,i)) 
    { 
      col[d]=i;          
      if(DFS(d+1))
        return true; 
    }
  }   
  return false; 
}


int main()
{
    int i,j,k,l,max=0;
    char a[100];
  while(scanf("%d",&n),n!=0)
  {
    max=0;
    memset(a,'0',sizeof(a));
    for(i=1;i<=MAX-1;i++)
      for(j=1;j<=MAX-1;j++)
        map[i][j]=0;
    for(i=1;i<=n;i++)
    {
      scanf("%s",a);
      j=2;
      while(a[j]!='\0') 
      {
        map[i][a[j]-'A'+1]=1;
        j++;
      }
    }
    for(i=1;i<=MAX-1;i++)
      col[i]=0;
    if(DFS(1))
      for(i = 1; i <= n; i++)
        if(col[i]>max) max=col[i];
    if(max==1)
      printf("1 channel needed.\n");
    else
      printf("%d channels needed.\n",max); 
  } 
}
