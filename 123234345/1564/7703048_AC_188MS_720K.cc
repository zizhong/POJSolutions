#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<list>
#include<set>
using namespace std;
set<vector<int> > hash;
int a[12];
int main()
{
	int t,n;
	while(scanf("%d %d",&t,&n)&&t)
	{
		hash.clear();
		for(int i=0;i<n;i++) scanf("%d",a+i);
		printf("Sums of %d:\n",t);
		char ok=0;
		for(int i=(1<<n)-1;i>=0;i--)
		{
			int tmp=0,mask=1<<n;
			vector<int> tp1;
			for(int j=0;j<n;j++)
			{
				mask>>=1;
				if(mask&i) {tmp+=a[j]; tp1.push_back(a[j]);}
			}
			if(tmp==t&&hash.find(tp1)==hash.end())
			{
				hash.insert(tp1);
				ok=1;
				for(int j=0;j<tp1.size();j++)
				{
					printf("%d",tp1[j]);
					if(j==tp1.size()-1) putchar('\n');
					else putchar('+');
				}
			}
		}
		if(!ok) puts("NONE");
	}
}
