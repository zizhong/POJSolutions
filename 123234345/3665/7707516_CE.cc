#include<iostream>
using namespace std;
int main()
{
    int n,i,t,r[1005];cin>>n>>t;
    for(i=1;i<=n;i++)
    cin>>r[i];
    for(int j=0;j<t;j++)
    {
          int max=-1,index;
          for(i=1;i<=n;i++)
          if(r[i]>max)
          {
              max=r[i];
              index=i;            
          }  
          cout<<index<<endl;
          int add=r[index]/(n-1);
          int mod=r[index]%(n-1);
          for(i=1;i<=n;i++)
          r[i]+=add;
          for(i=1;i<=mod;i++)
          {
               r[i]++;
               if(i==index)
               mod++;                
          }
          r[index]=0; 
    }
    scanf("%'d");
}
