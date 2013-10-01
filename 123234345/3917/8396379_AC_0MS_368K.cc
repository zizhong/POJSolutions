#include<stdio.h>
int d[128][128];
int main()
{
    d['R']['S']=1;
    d['S']['P']=1;
    d['P']['R']=1;
    char s1[76],s2[76];
    while(scanf("%s%s",s1,s2),s1[0]-'E')
    {
           int win1=0,win2=0;
           for(int i=0;s1[i];i++)
           {
                win1+=d[s1[i]][s2[i]];
                win2+=d[s2[i]][s1[i]];
           }
           printf("P1: %d\nP2: %d\n",win1,win2);
    }
}
