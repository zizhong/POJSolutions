#include<stdio.h>
#include<stdlib.h>
void dfs(int x,int y,int &l,int &r)
{
     if(x==1||y==1)
     {
         r=y-1,l=x-1;
         return ;
     }
     if(x>y)
     {         
         dfs(x%y,y,l,r);         
         l+=x/y;
     }
     if(x<y)
     {
         dfs(x,y%x,l,r);
         r+=y/x;
     }
     

}
int main()
{   
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int ncase;
    scanf("%d",&ncase);
    int t=ncase;
    while(t--)
    {
        printf("Scenario #%d:\n",ncase-t);
        int x,y;
        scanf("%d%d",&x,&y);
        int l,r;
        dfs(x,y,l,r);
        
        printf("%d %d\n\n",l,r);
    }
}
