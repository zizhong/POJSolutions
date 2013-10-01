#include<stdio.h>
char pos[3][64]=
     {
          "Wide Receiver ",
          "Lineman ",
          "Quarterback "
     };
double need[3][3]=
       {
           {4.5,150,200},
           {6.0,300,500},
           {5.0,200,300}
       };
int main()
{
    double v,w,s;
    while(scanf("%lf%lf%lf",&v,&w,&s),v+w+s>=1e-8)
    {
          int flag=0;
          for(int i=0;i<3;i++)
               if(v<=need[i][0]&&w>=need[i][1]&&s>=need[i][2])
                     flag=1,printf("%s",pos[i]);
          if(!flag) printf("No positions");
          puts("");
    }
}
