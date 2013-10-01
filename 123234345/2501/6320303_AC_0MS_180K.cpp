#include<stdio.h>
#include<string.h>
char pre[10]={"00:00:00\0"};
int cal(char *s)
{
    int h=(s[0]-'0')*10+s[1]-'0',
        m=(s[3]-'0')*10+s[4]-'0',
        c=(s[6]-'0')*10+s[7]-'0';
    return h*3600+m*60+c;
}
int delta(char *s1,char *s2)
{
    return cal(s2)-cal(s1);
}
int main()
{
    double v=0,s=0;    
    char run[50];
    while(gets(run))
    {
          int dt=0;
          double tv;
          char now[8];
          if(run[8])
          {
                    sscanf(run,"%s %lf",now,&tv);
                    dt=delta(pre,now);
                    s+=dt*v/3600; 
                    v=tv;
                    strcpy(pre,now);                                
          }
          else
          {
              dt=delta(pre,run);
              s+=dt*v/3600;
              strcpy(pre,run);
              printf("%s %.2f km\n",pre,s);
          }
    }
}
