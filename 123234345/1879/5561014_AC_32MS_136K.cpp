#include<stdio.h>
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
struct Stack
{
       int stack[15];
       int top;
       Stack():top(0) {}
       void push(int n) {stack[top++]=n;}
       int pop() {return stack[--top];}
       int Top() {return stack[top-1];}
       bool empty() {return top==0;}
       void clear() {top=0;}
       int size() {return top;}
};
struct Queue
{
       int queue[128];
       int head,tail;
       Queue():head(0),tail(0){}
       void push(int n){queue[tail]=n;tail=(tail+1)%128;}
       int pop(){int x=queue[head];head=(head+1)%128;return x;}
       bool empty(){return head==tail;}
       bool full(){return tail+1==head;}
       void clear(){tail=head=0;}
};
int main()
{
    int n,i,j,k,l;
    while(scanf("%d",&n)&&n)
    {
        Queue q;
        Stack min1,min5,hour;
        for(i=1;i<=n;i++)  q.push(i);
        
        for(l=0;l<24*60;l++)
        {            
            min1.push(q.pop());
            if(min1.size()==5)
            {
                min5.push(min1.pop());
                while(min1.size()) q.push(min1.pop());                
            }
            if(min5.size()==12)
            {
                hour.push(min5.pop());
                while(min5.size()) q.push(min5.pop());
                
            }
            if(hour.size()==12)
            {
                int x=hour.pop();
                while(hour.size()) q.push(hour.pop());
                q.push(x);
            }
        }
        int cycle[128]={0},f[128]={0},a[128]={0};
        i=0; 
        while(!q.empty()) cycle[q.pop()]=++i;
        for(k=1;k<=n;k++)
        {
            int t=k;
            while(1)
            {
                t=cycle[t];
                if(t!=k) f[k]++;
                else break;
            }
            f[k]++;
        }
         int m=f[1];
         for(int i=2;i<=n;i++)
             m=f[i]*m/gcd(f[i],m);
          printf("%d balls cycle after %d days.\n",n,m); 
       }
}










