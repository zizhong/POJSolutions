#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
    int sum;
    scanf("%d",&sum);
    queue< int > q;
    q.push(1),q.push(1),q.push(-1),q.push(1);
    while(q.size())
    {
       int n=q.front();
       q.pop();
       int step=q.front();
       q.pop();
       if(n==sum)
       {
           printf("%d\n",step);
           return 0;
       }
       step++;
       q.push(n+step),q.push(step);
       q.push(n-step),q.push(step);
    }
}
