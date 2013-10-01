#include<stdio.h>
#include<string.h>
const int MAXN=1515;

#define INF 2100000000

int SAP(int map[][MAXN],int v_count,int s,int t)      //邻接矩阵，节点总数，始点，汇点
{
	int i;
	int cur_flow,max_flow,cur,min_label,temp;         //当前流，最大流，当前节点，最小标号，临时变量
	char flag;                                        //标志当前是否有可行流
	int cur_arc[MAXN],label[MAXN],neck[MAXN];         //当前弧，标号，瓶颈边的入点（姑且这么叫吧）
	int label_count[MAXN],back_up[MAXN],pre[MAXN];    //标号为i节点的数量，cur_flow的纪录,当前流路径中前驱

	//初始化
	memset(label,0,MAXN*sizeof(int));
	memset(label_count,0,MAXN*sizeof(int));

	memset(cur_arc,0,MAXN*sizeof(int));
	label_count[0]=v_count;                           //全部初始化为距离为0

	neck[s]=s;
	max_flow=0;
	cur=s;
	cur_flow=INF;

	//循环代替递归
	while(label[s]<v_count)
	{
		back_up[cur]=cur_flow;
		flag=0;

		//选择允许路径（此处还可用邻接表优化）
		for(i=cur_arc[cur];i<v_count;i++)    //当前弧优化
		{
		   if(map[cur][i]!=0&&label[cur]==label[i]+1)    //找到允许路径
		   {
			   flag=1;
			   cur_arc[cur]=i;    //更新当前弧
			   if(map[cur][i]<cur_flow)    //更新当前流
			   {
				   cur_flow=map[cur][i];
				   neck[i]=cur;     //瓶颈为当前节点
			   }
			   else
			   {
				   neck[i]=neck[cur];     //瓶颈相对前驱节点不变
			   }
			   pre[i]=cur;    //记录前驱
			   cur=i;
			   if(i==t)    //找到可行流
			   {
				   max_flow+=cur_flow;    //更新最大流

				   //修改残量网络
				   while(cur!=s)
				   {
					   if(map[pre[cur]][cur]!=INF)map[pre[cur]][cur]-=cur_flow;
					   back_up[cur] -= cur_flow;
					   if(map[cur][pre[cur]]!=INF)map[cur][pre[cur]]+=cur_flow;
					   cur=pre[cur];
				   }

				   //优化，瓶颈之后的节点出栈
				   cur=neck[t];
				   cur_flow=back_up[cur]; 
			   }
			   break;
		   }
		}
		if(flag)continue;

		min_label=v_count-1;    //初始化min_label为节点总数-1

		//找到相邻的标号最小的节点   
		for(i=0;i<v_count;i++)
		{
			if(map[cur][i]!=0&&label[i]<min_label)
			{
				min_label=label[i];
				temp=i;
			}
		}
		cur_arc[cur]=temp;    //记录当前弧，下次从提供最小标号的节点开始搜索
		label_count[label[cur]]--;    //修改标号纪录
		if(label_count[label[cur]]==0)break;    //GAP优化
		label[cur]=min_label+1;    //修改当前节点标号
		label_count[label[cur]]++;     //修改标号记录
		if(cur!=s)
		{
		   //从栈中弹出一个节点
		   cur=pre[cur];
		   cur_flow=back_up[cur];
		}
	}
	return max_flow;
}
int n,m;
int g[MAXN][MAXN];
int map[MAXN][MAXN],s,t;
int ok(int x)
{
    for(int i=0;i<=n+m+1;i++)
       for(int j=0;j<=n+m+1;j++)
           g[i][j]=map[i][j];
    for(int i=n+1;i<=n+m;i++)
        g[i][t]=x;
    return SAP(g,n+m+2,s,t)==n;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&m),n)
    {
          memset(map,0,sizeof(map));
          s=0,t=n+m+1;
          getchar();
          for(int i=1;i<=n;i++)
          {
               char c;
               int f1=0,d=0;
               char s[1024];
               gets(s);
               for(int j=0;s[j];j++)
               {
                    c=s[j];
                    if(!(c>='0'&&c<='9'))
                    {
                          if(f1)
                          {
                              map[i][n+d+1]=1;
                              f1=d=0;
                          }
                          continue;
                    }
                    d=d*10+c-'0';
                    f1=1;
               }
               if(f1) map[i][n+d+1]=1;
          }
          for(int i=1;i<=n;i++)
             map[s][i]=1;
          int high=1000,low=1,mid;
          while(low+1<high)
          {
               //printf("%d %d\n",low,high);
               mid=low+high>>1;
               if(ok(mid)) high=mid;
               else low=mid;
          }
          printf("%d\n",high);
          /*for(int i=0;i<=n+m;i++,puts(""))
              for(int j=0;j<=n+m;j++)
                  printf("%d ",map[i][j]);*/
    }
}
