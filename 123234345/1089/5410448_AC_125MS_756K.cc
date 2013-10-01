#include<stdio.h>
#include<stdlib.h>
int a[500001][2];
int cmp(const void *a,const void *b)
{
    return ((int *)a)[0]-((int *)b)[0];
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
       scanf("%d%d",&a[i][0],&a[i][1]);
    qsort(a,n,sizeof(a[0]),cmp);
    int j=0;
    for(int i=1;i<n;i++)
    {      
        if(a[j][1]<a[i][0])
        {    
            printf("%d %d\n",a[j][0],a[j][1]);
            j=i;     
        }
        else
        {
            a[j][1]=a[j][1]<a[i][1]?a[i][1]:a[j][1];
        }
    }
    printf("%d %d\n",a[j][0],a[j][1]);
}
