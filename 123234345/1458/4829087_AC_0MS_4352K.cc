#include<iostream>
using namespace std;
main()
{
   string a,b;
   int c[1001][1001];
   int n,m,i,j;
   while(cin>>a>>b)
   {
      m=a.size();
      n=b.size();
      for(i=0;i<m;i++)
          c[i][0]=0;
      for(j=0;j<m;j++)
          c[0][j]=0;
      for(i=0;i<m;i++)
      {
         for(j=0;j<n;j++)
         {
            if(a[i]==b[j])
             c[i][j]=c[i-1][j-1]+1;
            else if(c[i-1][j]>=c[i][j-1])
               c[i][j]=c[i-1][j];
            else c[i][j]=c[i][j-1];
         }
      }
      cout<<c[m-1][n-1]<<endl;
   }
}
