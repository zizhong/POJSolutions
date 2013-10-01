#include<iostream>
#include<bitset>
#include<cstdio>
using namespace std;
const int SIZE=51;

struct P{
	int x,y;
}q[SIZE*SIZE];

int T,N,M,alienNum,bf,dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};
char map[SIZE][SIZE+1];
bitset<SIZE> vis[SIZE];

int BFS(){
	int i,front=0,rear=bf+1;

	for(i=1;i<=N;++i) vis[i].reset();

	for(int step=0;front<rear;++step){
		for(int LL=front,RR=rear;LL<RR;++LL,++front){
			for(i=0;i<4;++i){
				int tx=q[front].x+dir[i][0],ty=q[front].y+dir[i][1];

				if(tx>=1 && ty>=1 && tx<=N && ty<=M && map[tx][ty]!='#' && !vis[tx][ty]){
					if(map[tx][ty]=='A'){
						q[++bf].x=tx; q[bf].y=ty;
						map[tx][ty]='#';

						return step+1;
					}
					else if(map[tx][ty]==' '){
						q[rear].x=tx; q[rear++].y=ty;
						vis[tx][ty]=1;
					}
				}
			}
		}
	}
}

int prim(){
	int sum=0;

	while(alienNum--) sum+=BFS();

	return sum;
}

int main(){
	for(scanf("%d",&T);T--;){
		char buf[SIZE];
		scanf("%d %d",&M,&N); gets(buf);

		alienNum=bf=0;
		for(int i=1;i<=N;++i){
			getchar();
			for(int j=1;j<=M;++j){
				map[i][j]=getchar();
				if(map[i][j]=='A') ++alienNum;
				else if(map[i][j]=='S') q[0].x=i,q[0].y=j;				
			}
		}
		printf("%d\n",prim());
	}

}
