#include <iostream>
#include <algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int cmp(const void *a,const void *b)
{
  int *aa=(int *)a;
  int *bb=(int *)b;
  if(aa[0]!=bb[0])return aa[0]-bb[0];
  return bb[1]-aa[1];
}
int t, n, m;
int stick[20005][2];
int flag[20005];
int main()
{
 scanf("%d", &t);
 while(t--)
 {
  int i,min=0,max;
  scanf("%d", &n);
  for( i=0; i<n; i++)
   scanf("%d%d", &stick[i][0], &stick[i][1]);
  qsort(stick,n,sizeof(stick[0]),cmp);
 
  memset(flag,0,sizeof(flag));
  
  for(i=0; i<n; i++)
  {
   if(!flag[i])a
   {
    min++;
    flag[i]=1;
    max=stick[i][1];
    for(int j=i+1; j<n; j++)
    {
     if(!flag[j]&&stick[j][0]>stick[i][0]&&stick[j][1]>max)
     {
      max=stick[j][1];
      flag[j]=1;
     }
    }
   }
  }
  printf("%d\n", min);
 }
 return 0;
}