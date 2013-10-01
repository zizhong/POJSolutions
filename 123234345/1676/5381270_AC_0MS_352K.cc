#include<stdio.h>
#include<string.h>
char time[3][28];
bool checknum(int j,int n)
{
     switch (n)
            {
                case 0:
                     {if(time[1][j+1]!=' ')
                       return false;                     
                     break;}
                case 1:{
                     if(time[1][j]!=' '||
                        time[2][j]!=' '||
                        time[0][j+1]!=' '||
                        time[1][j+1]!=' '||
                        time[2][j+1]!=' ')
                     return false;
                     break;}
                case 2:{
                     if(time[1][j]!=' '||
                        time[2][j+2]!=' ')
                     return false;
                     break;}
                case 3:
                     {if(time[1][j]!=' '||
                        time[2][j]!=' ')
                     return false;
                     break;}
                case 4:{
                     if(time[2][j]!=' '||
                        time[2][j+1]!=' '||
                        time[0][j+1]!=' ')
                     return false;
                     break;}
                case 5:
                     {if(time[1][j+2]!=' '||
                        time[2][j]!=' ')
                     return false;
                     break;}
                case 6:
                     {if(time[1][j+2]!=' ')
                     return false;
                     break;}
                case 7:
                     {if(time[1][j]!=' '||
                        time[2][j]!=' '||
                        time[2][j+1]!=' '||
                        time[1][j+1]!=' ')
                     return false;
                     break;}
                case 8:
                     break;
                case 9:
                    { if(time[2][j]!=' ')
                     return false;
                     break;   }                  
            }
     return true;
}
bool check(int i)
{
     if(!checknum(0,i/60/10)) 
     
     {return false;}
     if(!checknum(3,i/60%10)) {return false;}
     if(!checknum(6,i%60/10)) {return false;}
     if(!checknum(9,i%60%10)) {return false;}
     int k=i-15;
     if(k<0) k+=24*60;
     if(!checknum(13,k/60/10)) {return false;}
     if(!checknum(16,k/60%10)) {return false;}
     if(!checknum(19,k%60/10)) {return false;}
     if(!checknum(22,k%60%10)) {return false;}
     return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        int i,j,flag=0,mi=0;
        memset(time,' ',sizeof(time));
        for(i=0;i<3;i++)
        {
            gets(time[i]);
        }
        /*for(i=0;i<3;i++)
        {
            puts(time[i]);
        }*/
        for(i=0;i<24*60;i++)
        {
            if(check(i)){
             mi=i;
             flag++;
            }
            if(flag>1) break;
        }
        if(flag==1) printf("%d%d%d%d\n",mi/60/10,mi/60%10,mi%60/10,mi%60%10);
        else printf("Not Sure\n");
        /*printf("%d\n",check(505));
        i=505-15;
        printf("%d%d%d%d\n",i/60/10,i/60%10,i%60/10,i%60%10);*/
    }
}
