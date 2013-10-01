#include<stdio.h>
#include<string.h>
#define maxn 32
int maze[maxn][maxn];
int main()
{
	//freopen("f.in","r",stdin);

	int t,i,j,x,y,k,cs=1;
	char str[1000];
	scanf("%d",&t);
	while(t--)
	{
		printf("Bitmap #%d\n",cs++);
		scanf("%d%d\n",&x,&y);
		for(i=0;i<maxn;i++)
			for(j=0;j<maxn;j++)
				maze[i][j]=0;
		scanf("%s\n",str);
		for(i=0;str[i]!='.' && str[i];i++)
		{
			switch(str[i])
			{
			case 'E':maze[x][y-1]=1;x++;break;
			case 'N':maze[x][y]=1;y++;break;
			case 'W':maze[x-1][y]=1;x--;break;
			case 'S':maze[x-1][y-1]=1;y--;break;
			default:break;
			}
		}
		for(j=31;j>=0;j--){
			for(i=0;i<32;i++)
				if(maze[i][j])
					printf("X");
				else
					printf(".");
			printf("\n");
		}
		printf("\n");
	}
}
