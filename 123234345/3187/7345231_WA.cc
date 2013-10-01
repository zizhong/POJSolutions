#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=11;
int t[N][N]=
{
    {0},
    {0,1},
    {0,1,1},
    {0,1,2,1},
    {0,1,3,3,1},
    {0,1,4,6,4,1},
    {0,1,5,10,10,5,1},
    {0,1,6,15,20,15,6,1},
    {0,1,7,21,35,35,21,7,1},
    {0,1,8,28,56,70,56,28,8,1},
    {0,1,9,36,84,126,126,84,36,9,1},    
};
int ok(int *d,int n,int sum)
{
    int ans=0;
    for(int i=1;i<=n;i++)
          ans+=t[n][i]*d[i];
    return ans==sum;
}
int print(int *d,int n)
{
    for(int i=1;i<=n;i++)
       printf("%d%c",d[i],i==n?'\n':' ');
}
int main()
{
    int a[N];
    int sum,n;
    scanf("%d%d",&n,&sum);
    for(int i=1;i<=n;i++)
       a[i]=i;
    if(ok(a,n,sum)) 
    {    
         print(a,n);
         return 0;
    }
    while(next_permutation(a+1,a+n))
        if(ok(a,n,sum))
        {
            print(a,n);
            return 0;
        }
}
