#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
const int N=40001;
struct Node
{
       int h,lv,cnt;
}block[410];
bool cmp(const Node &a,const Node &b)
{
     return a.lv < b.lv;
}
int v[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
       scanf("%d%d%d",&block[i].h,&block[i].lv,&block[i].cnt);
    //qsort(block,n,sizeof(block[0]),cmp);
    sort(block,block+n,cmp);
    int max=0;
    v[0]=1;
    for(int i=0;i<n;i++)
    {
        int tmp=0;
        for(int j=0;j<=max;j++)  if(v[j]&&v[j]<=i+1)
        {
            for(int k=1;j+k*block[i].h<=block[i].lv&&k<=block[i].cnt;k++)
            {
                if(v[j+k*block[i].h]==0)v[j+k*block[i].h]=i+2;
                if(tmp<j+k*block[i].h) tmp=j+k*block[i].h;
            }
        }
        if(max<tmp) max=tmp;
    }
    printf("%d\n",max);
    //scanf("%'d");
}
