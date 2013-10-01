#include<stdio.h>
#include<string.h>
#include<cmath>
#include<queue>
using namespace std;
const int MAX=10000;
bool flag[MAX+1];
int pow10[5]={1,10,100,1000,10000};
void prime()
{
     memset(flag,true,sizeof(flag));
     int i,j;
     for(i=2;i<=100;i++)
        if(flag[i])
          for(j=i*i;j<=MAX;j+=i)
          flag[j]=false;
}
int main()
{
    prime();
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int begin,end;
        scanf("%d%d",&begin,&end);
        int step[MAX]={0};
        queue< int > q;
        q.push(begin);
        step[begin]=1;
        while(q.size())
        {
           int num=q.front();
           q.pop();
           if(num==end) break;
           for(int i=1;i<5;i++)
             for(int j=0;j<10;j++)
             {
                 int keynum=num-num/pow10[i-1]%10*pow10[i-1]+j*pow10[i-1];
                 if(keynum>999&&keynum<MAX&&flag[keynum]&&!step[keynum])
                 {
                     q.push(keynum);
                     step[keynum]=step[num]+1;
                 }
             }           
        }
        printf("%d\n",step[end]-1);
    }
}
