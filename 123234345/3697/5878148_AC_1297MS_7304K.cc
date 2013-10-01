#include<stdio.h>
#include<string.h>
const int mod=10091;
const int Max=1000117;
struct node
{
	int x,y;
};
bool flag[10001];
node edge[Max];
int sum,N,q[10010],next[Max],hash[Max],list[10010],size;
int main()
{
	int M,i,u,v,t,ca,code,head,tail,len,x,y,j;
	ca=1;
	bool s;
	while(scanf("%d %d",&N,&M) && N && M)
	{
		memset(hash,-1,sizeof(hash));
		len=0;
		for(i=0;i<M;i++)
		{
			scanf("%d %d",&u,&v);
			if(u>v)
				t=u,u=v,v=t;
			code=(u*mod+v)%Max;
			edge[len].x=u;
			edge[len].y=v;
			next[len]=hash[code];
			hash[code]=len++;
		}
//		memset(flag,0,sizeof(flag));
		size=0;
		for(i=2;i<=N;i++)
			list[size++]=i;
		sum=0;
		flag[1]=1;
		q[0]=1;head=0;tail=1;
		while(head!=tail)
		{
			u=q[head++];
			j=0;
			for(i=0;i<size;i++)
				{
					x=u,y=list[i];
					if(x>y)
						t=x,x=y,y=t;
					s=false;
					code=(x*mod+y)%Max;
					for(t=hash[code];t>-1;t=next[t])
						if(edge[t].x==x && edge[t].y==y)
						{
							s=1;
							break;
						}
					if(!s)
					{
						sum++;
						q[tail++]=list[i];
					}
					else
						list[j++]=list[i];
				}
			size=j;
		}
		printf("Case %d: %d\n",ca,sum);
		ca++;
	}
	return 0;
}
