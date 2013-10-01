#include<stdio.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
int a[1024];
int main()
{
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
           scanf("%d",&a[i]);
        for(int i=0;i<k;i++)
        {
            if(!next_permutation(a,a+n))
                sort(a,a+n);
        }
        for(int i=0;i<n;i++)
        {
            if(i) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
}
