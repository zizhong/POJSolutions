#include<iostream>
using namespace std;
int n;
int solve(int N)
{
    int i,ans=1,t;
    for(i=2;i*i<=N;i++)
    {
        t=0;
        while(!(N%i))
        {
            t++;
            N/=i;
        }
        ans*=2*t+1;
    }
    if(ans==1||N!=1)ans*=3;
    return ans;
}
int main()
{
	int t,num=1,sum;
	cin>>t;
	while(t--){
	cin>>n;	
	sum=solve(n);
	if(n==1)sum=1;
	cout<<"Scenario #"<<num++<<":"<<endl;
	cout<<(sum+1)/2<<"\n"<<endl;}
	return 0;
}
