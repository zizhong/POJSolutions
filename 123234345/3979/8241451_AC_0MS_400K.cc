#include<stdio.h>
char s[8];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
    while(scanf("%s",s)==1)
    {
        int a=s[0]-'0',
            b=s[2]-'0',
            c=s[4]-'0',
            d=s[6]-'0';
        int D=gcd(b,d);
        int B=b*d/D;
        int A=(s[3]=='-')?(a*B/b-c*B/d):(a*B/b+c*B/d);
        if(A==0) printf("0\n");
        else if(A<0) putchar('-'),A=-A;
        if(A)
        {
             D=gcd(A,B);
             A/=D;
             B/=D;
             if(B==1) printf("%d\n",A);
             else printf("%d/%d\n",A,B);
        }
    }
}
