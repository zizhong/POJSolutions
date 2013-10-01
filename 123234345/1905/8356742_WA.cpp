#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double l,l1,d,u,h,c,t,ang,d_u;
	while(cin>>l>>t>>c)
	{
		if(l<0)
			break;
		if(l<1e-10) {puts("0.000");continue;}
		l1=l+c*t*l;
		d=0;
		u=2.5;
		while(fabs(d-u)>1e-10){
			ang=(d+u)/2;
			d_u=sin(ang)/ang;
			if(l1*d_u<=l)   
				u=ang;
			else d=ang;
		}
		h=l*tan(ang/2)/2;
		printf("%.3lf\n",h);
	}
	return 0;
}
