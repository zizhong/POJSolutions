#include <stdio.h>
int main(void)
{
	int m,n,i,j,mid,k;
	int distance[302];
	int cost[302][302];
	int opt[302][302];
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++)
		scanf("%d",&distance[i]);
	for(i=1;i<=m;i++)
		for(j=i;j<=m;j++)
		{
			cost[i][j] = 0;
			mid = (i+j)/2;
			for(k=i;k<=j;k++)
				cost[i][j] += (distance[mid]-distance[k])>=0?distance[mid]-distance[k]:distance[k]-distance[mid];
		}
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			opt[i][j] = 3000000;
	opt[0][0] = 0;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			if(opt[i][j]<3000000)
			{
				for(k=1;j+k<=m;k++)
				{
					if(opt[i+1][j+k]>opt[i][j]+cost[j+1][j+k])
					{
						opt[i+1][j+k] = opt[i][j]+cost[j+1][j+k];
					}
				}
			}
	printf("%d\n",opt[n][m]);
}