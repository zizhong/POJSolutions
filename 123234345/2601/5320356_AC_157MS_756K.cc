#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    float a0,an1;
    cin>>n>>a0>>an1;
    float *c=new float[n+1];    
    for(int i=1;i<=n;i++)
       cin>>c[i];
    float sum=0;
    for(int i=1;i<=n;i++)
      sum+=c[i]*(n+1-i);
    float r=0;
    r=(n*a0+an1-2*sum)/(n+1);
    printf("%.2f\n",r);
    delete []c;
}
