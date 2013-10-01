#include<stdio.h>
#include<string.h>
const int N=5843;
int num[N];
int min(int a,int b){return a>b?b:a;}
int main()
{
    int n;
    num[1]=1;
    int i1=1,i2=1,i3=1,i4=1;
    for(int i=2;i<N;i++)
    {
         num[i]=min(min(num[i1]*2,num[i2]*3),min(num[i3]*5,num[i4]*7));
         if(num[i]==num[i1]*2) i1++;
         if(num[i]==num[i2]*3) i2++;
         if(num[i]==num[i3]*5) i3++;
         if(num[i]==num[i4]*7) i4++;         
    }
    while(scanf("%d",&n),n)
    {
          char suf[11]={0};
          if(n%100!=11&&n%10==1) strcpy(suf,"st");
          else if(n%100!=12&&n%10==2) strcpy(suf,"nd");
          else if(n%100!=13&&n%10==3) strcpy(suf,"rd");
          else strcpy(suf,"th");
          printf("The %d%s humble number is %d.\n",n,suf,num[n]);
    }
}
