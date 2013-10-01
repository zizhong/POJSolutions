#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int MAX=10001;
int a[MAX][2],day[MAX];
bool mk[MAX];
int cmp(const void *a,const void *b)
{
    return ((int *)b)[0]-((int *)a)[0];
}
int find(int d)
{
    int i=d,t;
    while(day[i]!=i)
       i=day[i];
    while(d!=i)
    {
       t=day[d];
       day[d]=i;
       d=t;
    }
    return i;
}
int main()
{
    int n;
    while(cin>>n)
    {
       int max=0;
       int i;
       for(i=0;i<n;i++)
       {
          scanf("%d%d",&a[i][0],&a[i][1]);
          mk[i]=false;
          max=max<a[i][0]?a[i][0]:max;
       }
       for(i=1;i<=max;i++)
          day[i]=i;
       qsort(a,n,sizeof(a[0]),cmp);
       int r=0;
       for(i=0;i<n;i++)
       {
          int today=a[i][1];
          if(mk[today]) today=find(today);
          if(today>0)
          {
              r+=a[i][0];
              mk[today]=true;
              day[today]=today-1;
          }
       }
       cout<<r<<endl;
    }
}