#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
const int NMAX=1000000;
bool flag[NMAX];
void iprime()
{
     memset(flag,true,sizeof(flag));
     int max=int(sqrt(NMAX)),i,j;
     flag[0]=flag[1]=false;
     for(i=2;i<=max;i++)
          if(flag[i])
           for(j=i*i;j<=NMAX;j+=i)
             flag[j]=false;      
}
int  main()
{
     iprime();
     int a,d,n;
     while(cin>>a>>d>>n&&(a||d||n))
     {
          int i=0;
          while(i<n)
          {
              if(flag[a]) i++;
              a+=d;
          }
          cout<<a-d<<endl;
     }
}
