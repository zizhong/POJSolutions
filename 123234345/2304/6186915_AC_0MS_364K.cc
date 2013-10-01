#include<stdio.h>
int main()
{
    int x0,x,y,z;
    while(scanf("%d%d%d%d",&x0,&x,&y,&z),x0||x||y||z)
    {
          printf("%d\n",9*(40*3+(x0-x+40)%40+(40+y-x)%40+(40+y-z)%40));
    }
}
