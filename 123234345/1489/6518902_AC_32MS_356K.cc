#include<stdio.h>
#include<string.h>
int A[256],C[]={1,10,100,1000,10000,100000,1000000};
char B[6];
int num(char s[])
{
    int n=strlen(s),res=0;
    for(int i=0;i<n;i++) res+=A[s[i]];
    return res;
}
void str(char r[],int a)
{
     int n=0;
     for(int i=0;i<=5;i++)
     {
             int m=a%C[i+1]/C[i];
             if(m)
             {
                  while(m--) r[n++]=B[i];
                  r[n++]=' ';
             }
     }
     r[n]=0;
}
int main()
{
    char s1[100],s2[100];
    A['|']=1,A['n']=10,A['9']=100,A['8']=1000,A['r']=10000;
    B[0]='|',B[1]='n',B[2]='9',B[3]='8',B[4]='r',B[5]=0;
    while(gets(s1)&&s1[0]!='\n'&&gets(s2))
    {
          int a=num(s1),b=num(s2),cur=1;
          int aa=a;
          char r1[100],r2[100];
          for(int i=0;cur<=b;cur<<=1,a<<=1,i++)
          {
                str(r1,cur);
                str(r2,a);
                printf("%s%c",r1,(b&(1<<i))?'*':' ');
                int len=strlen(r1),m=34-len-1;
                while(m--) putchar(' ');
                puts(r2);                
          }
          str(r1,aa*b);
          printf("The solution is: %s\n",r1);
    }
}
