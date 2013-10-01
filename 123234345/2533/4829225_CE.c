#include<iostream>
using namespace std;
int cmp(const void*a,const void*b)
{
   return *(int*)a-*(int*)b;
}
main()
{
   int a[1000],b[1000];
   int c[1000][1000];
   int n,m,i,j;
   while(cin>>n)
   {
     for(i=0;i<n;i++)
        cin>>a[i];
     for(i=0;i<n;i++)
          b[i]=a[i];
     qsort(a,n,sizeof(a[0]),cmp) ;
         
      for(i=0;i<n;i++)
          c[i][0]=0;
      for(j=0;j<n;j++)
          c[0][j]=0;
      for(i=0;i<n;i++)
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
      cout<<c[n-1][n-1]<<endl;
   }
}
