#include "iostream"

using namespace std;

int n;
long long c,r,k;
char map[100][100];
bool visit[100];

void Dfs(int a,int b)
{
     //cout<<a<<" "<<b<<" "<<r<<c<<endl;
     if(r==k)
     {
       c++;
    //   r--;
     }  
     else
     {
        visit[b]=true;//每次搜完置该列为不可放 
        for(int i=a+1;i<=n;i++)
           for(int j=1;j<=n;j++) //回溯后向右搜索 
           {
                if(map[i][j]=='#'&&!visit[j])
                {
                      r++; 
                      Dfs(i,j); 
                      r--;
                }    
           }
            visit[b]=false;// 注意：当往上回溯时置该列可放 
     }
     
}
           
int main()
{
      //freopen("data.in","r",stdin);
      while(scanf("%d%d",&n,&k)&&n!=-1)
      {
            c=0;                
            for(int i=1;i<=n;i++)
               for(int j=1;j<=n;j++)
                   cin>>map[i][j];    
            for(int i=1;i<=n;i++)
               for(int j=1;j<=n;j++)
               {
                   if(map[i][j]=='#')     
                   {   
                       r=1;
                       memset(visit,false,sizeof(visit));//置每每一列可放                  
                       Dfs(i,j);//从每一个开始搜索 
                       //cout<<endl;
                   }      
                 
               }
             printf("%d\n",c);
      }//while(1);
      return 0;           
}
