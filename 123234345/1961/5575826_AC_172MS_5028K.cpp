#include<stdio.h>
#define N 1000005
int next[N];
char s[N];
int n;
void Next()
{
     int k=-1,q=0;
     next[0]=-1;
     for(;s[q];)
     {
         if(k==-1||s[q]==s[k]) k++,q++,next[q]=k;
         else k=next[k];
     }
}
int main()
{
    int ncase=0;
    int n;
    while(scanf("%d",&n)&&n)
    {
        gets(s),gets(s);
        Next();
        printf("Test case #%d\n",++ncase);
        for(int i=2;i<=n;i++)
        {
             int t=i-next[i];
             if(i%t==0&&i/t>1)
                 printf("%d %d\n",i,i/t);
        }
        printf("\n");
    }
}
