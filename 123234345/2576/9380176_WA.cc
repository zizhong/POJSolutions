#include <iostream>
#include <cstdlib>
using namespace std;
#define AS(x) ((x)<0?-(x):(x))
void in(int n,int a[],int& s)
{
	for(int i=s=0;i<n;++i)
		cin>>a[i],s+=a[i];
}
int main()
{
	int a[64],b[64],sa,sb,n,i,j,an,bn,t,d1,d2;
	cin>>n;
	an = n/2;
	bn = n-an;
	in(an,a,sa);
	in(bn,b,sb);
	for(t=0;t<100000;++t)
	{
		i = rand()%an;
		j = rand()%bn;
		d1 = AS(sa-sb);
		d2 = AS(sa-sb-((a[i]-b[j])<<1));
		if(d1 >= d2)
		{
			sa -= a[i] - b[j];
			sb -= b[j] - a[i];
			d1 = a[i];
			a[i] = b[j];
			b[j] = a[i];
		}
	}
	if(sa<sb)
		cout<<sa<<" "<<sb;
	else
		cout<<sb<<" "<<sa;
	cout<<endl;
}
