#include<stdio.h>
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char a[257];
    char ch[17]={"0123456789ABCDEF"};
    int nm[257]={0};
    for(int i=1;i<16;i++) nm[ch[i]]=i;
    while(gets(a)&&a[0]!='8')
    {
         int x=0;
         int a1=0,a2=0,ad,t,sum;
         while(a[x]!='8')
         {
              switch (a[x])
              {
                     case '0':
                          ad=nm[a[x+1]]*16+nm[a[x+2]];
                          a1=nm[a[ad]];
                          x+=3;
                          //printf("a1=%d\n",a1);
                          break;
                     case '1':
                          ad=nm[a[x+1]]*16+nm[a[x+2]];
                          a[ad]=ch[a1];
                          x+=3;
                          break;                          
                     case '2':
                          t=a2;
                          a2=a1;
                          a1=t;
                          x++;
                          break;
                     case '3':
                          sum=a1+a2;
                          a1=sum%16;
                          a2=sum/16;
                          x++;
                          break;
                     case '4':
                          a1=(a1+1)%16;
                          x++;
                          break;
                     case '5':
                          a1=(a1+15)%16;
                          x++;
                          break;
                     case '6':
                          if(a1==0)
                          {
                                   x=nm[a[x+1]]*16+nm[a[x+2]];
                          }
                          else x+=3;
                          break;
                     case '7':
                          x=nm[a[x+1]]*16+nm[a[x+2]];
                          break;                     
              }
         }
         puts(a);
    }
}
