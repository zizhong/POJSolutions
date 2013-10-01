#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int sum,m,n,bestvalue,value,sumvalue,station[10];

typedef struct node
{
    int st;
    int ed;
    int num;
    int earn;
}node;

node p[30];

bool cmp(node p1,node p2)
{
    return p1.earn > p2.earn;
}

void dfs(int q)
{
    int i;
    if(q > n)
    {
        if(bestvalue < value)
            bestvalue = value;
        return ;
    }
    bool flag = 0;
    for(i = p[q].st;i < p[q].ed;i ++)
    {
        if(station[i] + p[q].num > sum)
        {
            flag = 1;
            break;
        }
    }
    if(!flag)
    {
        for(i = p[q].st;i < p[q].ed;i ++)
            station[i] += p[q].num;
        value += p[q].earn;
        sumvalue -= p[q].earn;
        dfs(q + 1);
        for(i = p[q].st;i < p[q].ed;i ++)
            station[i] -= p[q].num;
        value -= p[q].earn;
        sumvalue += p[q].earn;
    }
    if(sumvalue + value > bestvalue)
        dfs(q + 1);
}
int main()
{
    int i;
    while(scanf("%d%d%d",&sum,&m,&n) != EOF)
    {
        if(sum == 0 && m == 0 && n == 0)
            break;
        for(i = 1;i <= n;i ++)
        {
            scanf("%d %d %d",&p[i].st,&p[i].ed,&p[i].num);
            p[i].earn = p[i].num * (p[i].ed - p[i].st);
            sumvalue += p[i].earn;
        }
        memset(station,0,sizeof(station));
        sort(p + 1,p + n + 1,cmp);
        bestvalue = 0;
        value = 0;
        dfs(1);
        printf("%d\n",bestvalue);
    }
    return 0;
}
