#include<stdio.h>
#define N 1000
int  Stack[N];
int top=-1;
void clear()
{
    top=-1;
}
void pop()
{
    top--;
}
int front()
{
    return Stack[top];
}
void push(int n)
{
    Stack[++top]=n;
}
bool empty()
{
     return top==-1;
}

int main()
{
    int n;
    int i,j,k;
    while(scanf("%d",&n)&&n)
    {
        int per[N]={0};
        while(scanf("%d",&per[0]))
        {
            if(!per[0])
            {
                printf("\n");
                break;
            }
            for(i=1;i<n;i++)
                scanf("%d",&per[i]);
            for(i=n,j=n-1;j>=0;j--)
            {
                push(per[j]);
                while(!empty()&&front()==i)
                    pop(),i--;
            }
            if(empty()) printf("Yes\n");
            else printf("No\n"),clear();
        }
    }
}
