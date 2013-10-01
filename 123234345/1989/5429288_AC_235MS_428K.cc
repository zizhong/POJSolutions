#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool find[100001];
int main()
{
    int n,k,mk,r=1;
    scanf("%d%d",&n,&k);
    mk=k;
    memset(find,false,sizeof(find));
    while(n--)
    {
        int j;
        scanf("%d",&j);
        if(find[j]==false)
        {
            find[j]=true;
            mk--;
            if(mk==0)
            {
                r++;
                mk=k;
                memset(find,false,sizeof(find));
            }
        }
    }
    printf("%d\n",r);
    //system("pause");
}
