#include<iostream>
using namespace std;
int main()
{
   int n,r,e,c;
   cin>>n;
   while(n--)
   {
      cin>>r>>e>>c;
      if(r<e-c) cout<<"advertise\n";
      if(r==e-c) cout<<"does not matter\n";
      if(r>e-c)  cout<<"do not advertise\n";     
   }
}
