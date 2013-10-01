#include<stdio.h>
int main()
{
    int A,a,B,b,p;
    scanf("%d%d%d%d%d",&A,&a,&B,&b,&p);
    if(A<B)
    {
         int t=A;A=B;B=t;
         t=a;a=b;b=t;
    }
    puts((p>=A&&(B<=a||B<=p-A))?"Yes":"No");
}
