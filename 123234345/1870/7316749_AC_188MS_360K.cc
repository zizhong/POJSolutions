#include<stdio.h>
using namespace std;
int abs(int x)
{
	if(x>0) return x;
	else return -x;
}
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
void solve(int l,int& x,int& y)
{
	int type,temp,k;
	k=0;
	while(l>=1+3*k*(k+1))
		k++;
	l-=1+3*k*(k-1);
	type=l/k;
	temp=l%k;
	if(type==1) {
		x=k;y=-temp;
	} else if(type==2) {
		x=k-temp;y=-k;
	} else if(type==3) {
		x=-temp;y=-k+temp;
	} else if(type==4) {
		x=-k;y=temp;
	} else if(type==5) {
		x=-k+temp;y=k;
	} else if(type==0) {
		x=temp;y=k-temp;
		if(l==0) y--;
	}
}

int main()
{
	int a,b,ax,ay,bx,by,dis;
	while(scanf("%d%d",&a,&b)&&(a||b))
	{
		solve(a,ax,ay);
		solve(b,bx,by);
		ax-=bx;
		ay-=by;
		if(ax*ay>0) 
			dis=abs(ax+ay);
               else 
			dis=max(abs(ax),abs(ay));
		printf("The distance between cells %d and %d is %d.\n",a,b,dis);
	}
}
