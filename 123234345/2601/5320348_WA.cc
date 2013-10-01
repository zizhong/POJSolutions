#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    double a0,an1;
    cin>>n>>a0>>an1;
    double *c=new double[n+1];    
    for(int i=1;i<=n;i++)
       cin>>c[i];
    double sum=0;
    for(int i=1;i<=n;i++)
      sum+=c[i]*(n+1-i);
    double r=0;
    r=(n*a0+an1-2*sum)/(n+1);
    printf("%.2lf\n",r);
    delete []c;
}
