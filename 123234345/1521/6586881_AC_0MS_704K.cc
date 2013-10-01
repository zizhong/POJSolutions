#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
int main()
{
    char s[82];
    while(scanf("%s",s),strcmp(s,"END"))
    {
         int len=strlen(s);
         int num[27]={0};
         for(int i=0;i<len;i++)
            if(s[i]=='_') num[0]++;
            else num[s[i]-'A'+1]++;
         int wpl=0;
         priority_queue <int ,vector<int>,greater<int> > myq;
         for(int i=0;i<27;i++)
             if(num[i]>0) myq.push(num[i]);
         int a,b;
         if(myq.size()==1) {printf("%d %d %.1f\n",myq.top()*8,myq.top(),8.0);continue;}
         a=myq.top();
         myq.pop();
         while(!myq.empty())
         {
              b=myq.top();
              myq.pop();
              wpl+=a+b;
              myq.push(a+b);
              a=myq.top();
              myq.pop();
         }
         printf("%d %d %.1f\n",len*8,wpl,(len*8.0/wpl));
    }
}
