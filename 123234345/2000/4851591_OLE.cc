#include<iostream>
using namespace std;
int a[10001]={0,1};
int main()
{
    int i=1;
    double  n, q;
    while(1)
    {
     cin>>n;
     for(i=1;n>i*(i+1)*1/2.0;i++)
        a[i]=i*i;
     for(int j=1;j<i;j++)
         a[j]=a[j-1]+a[j];
     q=i*(n-(i-1)*i*1.0/2);
     cout<<n<<' '<<a[i-1]+q<<endl;
    }
}
