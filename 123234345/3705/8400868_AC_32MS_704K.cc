#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
        int n;
        cin>>n;
        int k=n/2,i;
		if(n==1)cout<<0<<endl;
		else if(n==2)
		{
			cout<<1<<endl;
			cout<<2<<' '<<1<<' '<<0<<endl;
		}
		else{		
		cout<<k+1<<endl;
		cout<<1<<' '<<k<<' '<<n-k-1<<endl;
		for(i=0;i<=n-k-2;i++)
		{
            cout<<n-k+1-i<<' '<<k<<' '<<n-k-2-i<<endl;
		}
		if(n%2==0)
			cout<<1<<' '<<1<<' '<<k<<endl;
		}
	return 0;
}

