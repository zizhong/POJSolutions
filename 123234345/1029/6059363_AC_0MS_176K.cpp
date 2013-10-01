#include<stdio.h>
#include<string.h>
const int N=1002;
int mark[N],left[N/2],right[N/2],sure[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    while(k--)
    {
         int m;
         scanf("%d",&m);
         for(int i=0;i<m;i++) scanf("%d",&left[i]);
         for(int i=0;i<m;i++) scanf("%d",&right[i]);
         getchar();
         char c=getchar();
         if(c=='=')
              for(int i=0;i<m;i++)
              {
                   sure[left[i]]=sure[right[i]]=1;
                   mark[right[i]]=mark[left[i]]=0;
              }
         else if(c=='<')
              for(int i=0;i<m;i++)
              {
                   if(sure[left[i]]==0) mark[left[i]]--;
                   if(sure[right[i]]==0) mark[right[i]]++;
              }
         else
             for(int i=0;i<m;i++)
             {
                   if(sure[left[i]]==0) mark[left[i]]++;
                   if(sure[right[i]]==0) mark[right[i]]--;
             }
    }
    for(int i=1;i<=n;i++)
        if(mark[i]<0) mark[i]=-mark[i];
    int max=-1,mi=-1;
    for(int i=1;i<=n;i++)
    {
          if(sure[i]==0&&max<mark[i]) max=mark[i],mi=i;
    }
    for(int i=1;i<=n;i++)
          if(sure[i]==0&&max==mark[i]&&mi!=i)
          {
              printf("0\n");
              //scanf("%d",&n);
              return 0;
          }
    if(max==-1) printf("0\n");
    else printf("%d\n",mi);
    //scanf("%d",&n);
    
}
