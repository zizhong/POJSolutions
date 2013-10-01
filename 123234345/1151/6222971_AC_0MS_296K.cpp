#include<iostream>
#include<algorithm>
#include<memory>
#include<cmath> 
#include<stdio.h>
using namespace std;
double x[210],y[210],in[110][4];
bool xy[210][210];
double N=1e-8,sum;
int i,j,k,n_map;
void input();  void solve();    void cacu(); 
int main()
{ 
	int T=1;
	while(scanf("%d",&n_map) && n_map)
	{
		input();
		sort(x,x+2*n_map);
		sort(y,y+2*n_map);
		memset(xy,0,sizeof(xy));
		solve();
		cacu();
		printf("Test case #%d\nTotal explored area: %.2f\n\n",T++,sum);
	}}
void input()
{
	k = 0;
	for(i = 0 ; i < n_map ; i++)
	{
		cin>>in[i][0]>>in[i][1]>>in[i][2]>>in[i][3];
		x[k] = in[i][0];
		y[k] = in[i][1];
		k++;
		x[k] = in[i][2];
		y[k] = in[i][3];
		k++;
	}

}

void solve(){
	for(i = 0 ; i < n_map; i++)	{
		int i1,j1,i2,j2, I, J;
		k = 0 ; 
		while(fabs(x[k]-in[i][0])>N && k < 2*n_map) k ++;
		i1 = k;	k = 0;
		while(fabs(y[k]-in[i][1])>N && k < 2*n_map) k ++;
		j1 = k; k = 0 ; 
		while(fabs(x[k]-in[i][2])>N && k < 2*n_map) k ++;		 	
		i2= k;k = 0;
		while(fabs(y[k]-in[i][3])>N && k < 2*n_map) k ++;
		j2 = k;
		for(I = i1 ; I < i2 ; I ++)
		for(J = j1 ; J < j2 ; J ++)	xy[I][J] = true;
	}
}
void cacu()
{
	sum = 0;
	for(i = 0 ; i < 2*n_map ; i ++)
	for(j = 0 ; j < 2 * n_map ; j++)
		sum += xy[i][j]*(x[i+1] - x[i] )*( y[j+1] - y[j]);
}