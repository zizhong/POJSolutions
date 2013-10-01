#include <iostream>   
using namespace std;   
bool map[125][125];   
int pre[125];   
bool visited[125];   
int no_of_intersections,no_of_streets;   
int Find_DFS(int left)   
{   
    for(int i=0;i<no_of_intersections;i++)   
    {   
        if(map[left][i]&&!visited[i])   
        {   
            visited[i]=true;   
            int temp=pre[i];   
            pre[i]=left;   
            if(temp==-1||Find_DFS(temp)) return true;   
            pre[i]=temp;   
        }   
    }   
    return false;   
}   
int main()   
{   
    int t,start,end,sum;   
    scanf("%d",&t);   
    while(t--)   
    {   
        memset(map,0,sizeof(map));   
        memset(pre,-1,sizeof(pre));   
        scanf("%d%d",&no_of_intersections,&no_of_streets);   
        for(int i=0;i<no_of_streets;i++)   
        {   
            scanf("%d%d",&start,&end);   
            map[start-1][end-1]=true;   
        }   
        sum=0;   
        for(int i=0;i<no_of_intersections;i++)   
        {   
            memset(visited,0,sizeof(visited));   
            if(Find_DFS(i)) sum++;   
        }   
        printf("%d\n",no_of_intersections-sum);   
    }   
    return 0;   
}  
#include <iostream>
using namespace std;
bool map[125][125];
int pre[125];
bool visited[125];
int no_of_intersections,no_of_streets;
int Find_DFS(int left)
{
	for(int i=0;i<no_of_intersections;i++)
	{
		if(map[left][i]&&!visited[i])
		{
			visited[i]=true;
			int temp=pre[i];
			pre[i]=left;
			if(temp==-1||Find_DFS(temp)) return true;
			pre[i]=temp;
		}
	}
	return false;
}
int main()
{
	int t,start,end,sum;
	scanf("%d",&t);
	while(t--)
	{
		memset(map,0,sizeof(map));
		memset(pre,-1,sizeof(pre));
		scanf("%d%d",&no_of_intersections,&no_of_streets);
		for(int i=0;i<no_of_streets;i++)
		{
			scanf("%d%d",&start,&end);
			map[start-1][end-1]=true;
		}
		sum=0;
		for(int i=0;i<no_of_intersections;i++)
		{
			memset(visited,0,sizeof(visited));
			if(Find_DFS(i)) sum++;
		}
		printf("%d\n",no_of_intersections-sum);
	}
	return 0;
}
 