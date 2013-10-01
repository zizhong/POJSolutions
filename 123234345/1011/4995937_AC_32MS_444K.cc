#include <iostream>
using namespace std;
int start;
int stricks[64];
bool isuse[64];
int compare(const void *ele1,const void *ele2)
{
	return *(int*)ele2-*(int*)ele1;
}
bool deal(int n,int m,int left,int len)
{
	int i;
	if(m==0&&left==0) return true;
	if(left==0)
	{
		i=0;
		left=len;
	}
	else
	{
		i=start+1;
	}
	for (;i<n;i++)
	{
		if(isuse[i]||stricks[i]>left) continue;
		isuse[i]=true;
		start=i;
		if(deal(n,m-1,left-stricks[i],len)) return true;
		else
			isuse[i]=false;
		if(left==stricks[i]||left==len) break;	}
	return false;
}
int main()
{
	int i,n,sum;
	while (cin>>n)
	{
		if(n==0) break;
		sum=0;
		for (i=0;i<n;i++)
		{
			cin>>stricks[i];
			sum+=stricks[i];
			isuse[i]=false;
		}
		qsort(stricks,n,sizeof(int),compare);
		for (i=stricks[0];i<=sum;i++)
		{
			if(sum%i!=0) continue;
			if(deal(n,n,0,i))
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
