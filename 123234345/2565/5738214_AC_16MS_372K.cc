#include<stdio.h>
int main()
{
    int n,num;
    double d;
    scanf("%d%lf",&n,&d);
    while(scanf("%d",&num)!=EOF)
    {
          int h=0,m=0,s=0;
          char r[8];
          int flag=1;
          for(int i=0;i<n;i++)
          {
               scanf("%s",r);
               if(flag)
               {
                    for(int i=0;i<7;i++)
                        if(r[i]=='-') flag=0;
                    if(flag)
                    {
                        h+=(r[0]-'0');
                        m+=(r[2]-'0')*10+r[3]-'0';
                        s+=(r[5]-'0')*10+r[6]-'0';             
                    }
               }
          }
          if(!flag) printf("%3d: -\n",num);
          else
          {
              int ss=s+60*(m+60*h);
              double fs=ss/d;
              ss=int(ss/d);
              if(fs-ss>ss+1-fs) ss++;
              double mm=ss/60;
              ss%=60;
              printf("%3d: %.0f:%s%d min/km\n",num,mm,ss<10?"0":"",ss);
          }
    }
}
