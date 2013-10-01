#include<stdio.h>
int abs(int x){return x>0?x:-x;}
int max(int a,int b){return a>b?a:b;}
void cal(int &x,int &y,int n)
{
     int i=0,j,k;
     while(n>=1+6*i*(i+1)/2) i++;
     n-=1+6*i*(i-1)/2;
     j=n/i;
     k=n%i;
     switch (j)
     {
            case 1:x=i,y=-k;break;
            case 2:x=i-k,y=-i;break;
            case 3:x=-k,y=-i+k;break;
            case 4:x=-i,y=k;break;
            case 5:x=-i+k,y=i;break;
            case 0:x=k,y=i-k;if(n==0) y--;
     }
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b),a)
    {
         int x1,y1,x2,y2;
         cal(x1,y1,a);
         cal(x2,y2,b);
         x1-=x2,y1-=y2;
         int dis=x1*y1>0?abs(x1+y1):max(abs(x1),abs(y1));
         printf("The distance between cells %d and %d is %d.\n",a,b,dis);
    }
}
