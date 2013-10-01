#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char s[250];
    int T=0;
    while(gets(s),strcmp(s,"END"))
    {
         double x=0.0,y=0.0;
         int d=0,fnum,dis;
         for(int i=0;s[i]!='.';i++)
         {
               if(s[i]==','||s[i]==' ') {d=0;continue;}
               if(s[i]>='0'&&s[i]<='9')
               {
                    d=d*10+s[i]-'0';
                    continue;
               }
               if(s[i]=='N')
               {
                   if(s[i+1]==','||s[i+1]=='.')
                       y+=d*1.0;
                   else if(s[i+1]=='W')
                   {
                        y+=d*sqrt(0.5);
                        x-=d*sqrt(0.5);
                        i++;
                   }else if(s[i+1]=='E')
                   {
                        y+=d*sqrt(0.5);
                        x+=d*sqrt(0.5);
                        i++;
                   }
                   continue;
               }
                if(s[i]=='S')
               {
                   
                   if(s[i+1]==','||s[i+1]=='.')
                     y-=d*1.0;
                   else if(s[i+1]=='W')
                   {
                        y-=d*sqrt(0.5);
                        x-=d*sqrt(0.5);
                        i++;
                   }else if(s[i+1]=='E')
                   {
                        y-=d*sqrt(0.5);
                        x+=d*sqrt(0.5);
                        i++;
                   }
                   continue;
               }
               if(s[i]=='E')
                     x+=d*1.0;
               if(s[i]=='W')
                    x-=d*1.0;
               d=0;
         }
         printf("Map #%d\nThe treasure is located at (%.3lf,%.3lf).\n",++T,x+1e-8,y+1e-8);
         printf("The distance to the treasure is %.3lf.\n\n",sqrt(x*x+y*y)+1e-8);
    }    
}
