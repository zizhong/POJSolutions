#include<iostream.h>
typedef long long l64;
l64 Cnm(l64 n,l64 m)
{		  
	 return m>0?(Cnm(n-1,m-1)*n)/m:1;
}
 int main()
{			 
	 l64 m,n;
	 while(cin>>n>>m&&m+n>0)
		 cout<<Cnm(m+n,(m<n)?m:n)<<endl;
	 return 0;	
} 
