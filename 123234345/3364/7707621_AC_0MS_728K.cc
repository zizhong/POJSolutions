#include <iostream>
using namespace std;
int f(int m,int n,int x)
{
	if(m%2==0||n%2==0 )
		return m*n/2;
    if(x==0)
		    return (m-1)*n/2 + (n-1)/2;
	return (m-1)*n/2 + (n+1)/2;
}
int main()
{
   int m,n,x;
   while( cin>>m>>n>>x&& n)
   {   
       if(x==1) 
	        cout<<f(m-7,n-8,1-x) + f(m-8,n-7,1-x) - f(m-8,n-8,x)+1<<endl;
       else 
		   cout<<f(m-7,n-8,1-x) + f(m-8,n-7,1-x) - f(m-8,n-8,x)<<endl;
   }
}
