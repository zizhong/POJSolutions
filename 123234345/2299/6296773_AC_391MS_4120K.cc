#include <string.h>
#include<stdio.h>
#define MAXN 5000000
#define _cp(a,b) ((a)<=(b))
typedef int elem_t;
elem_t _tmp[MAXN];
elem_t k[MAXN];
__int64 inv(int n,elem_t* a){
    int l=n>>1,r=n-l,i,j;
    __int64 ret=(r>1?(inv(l,a)+inv(r,a+l)):0);
    for (i=j=0;i<=l;_tmp[i+j]=a[i],i++)
        for (ret+=j;j<r&&(i==l||!_cp(a[i],a[l+j]));_tmp[i+j]=a[l+j],j++);
    memcpy(a,_tmp,sizeof(elem_t)*n);
    return ret;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
          for(int i=0;i<n;i++) scanf("%d",&k[i]);
          printf("%I64d\n",inv(n,k));
    }
}
