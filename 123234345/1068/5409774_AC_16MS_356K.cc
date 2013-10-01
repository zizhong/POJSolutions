#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int p[21]={0},w[21]={0};
        char path[45];
        bool used[45];
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
           scanf("%d",&p[i]);           
        
        memset(path,0,sizeof(path));
        memset(used,false,sizeof(used));
        
        int h=0;
        for(int i=1;i<=n;i++)
        {
             int k=p[i]-p[i-1];
             while(k--)
             {
                 path[h++]='(';
             }
             path[h++]=')';
        }
        path[h]='\0';
        //printf("%s\n",path);
        
        int k=0;
        for(int i=0;i<2*n;i++)
        {
            if(path[i]==')')
            {
                w[k]=1;
                for(int j=i-1;j>=0;j--)
                {
                    if(path[j]=='('&&used[j]==false)
                    {
                        used[j]=true;
                        break;
                    }
                    if(path[j]==')')
                       w[k]++;
                }
                k++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i) printf(" ");
            printf("%d",w[i]);
        }
        printf("\n");
    }
}
