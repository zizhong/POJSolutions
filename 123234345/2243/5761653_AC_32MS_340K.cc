#include<stdio.h>
int a[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int in(int x,int y)
{
    return x>=1&&x<=8&&y>=1&&y<=8;
}
int main()
{
    char s[10];
    while(gets(s)!=NULL)
    {
         int x1=s[0]-'a'+1,y1=s[1]-'0',ex=s[3]-'a'+1,ey=s[4]-'0';
         int v[9][9]={0},q[256]={0},head=0,tail=0;
         if(x1==ex&&y1==ey) printf("To get from %c%c to %c%c takes 0 knight moves.\n",s[0],s[1],s[0],s[1]);
         v[x1][y1]=0;
         q[tail++]=x1,q[tail++]=y1;
         while(head!=tail&&!v[ex][ey])
         {
             int x=q[head++],y=q[head++];
             for(int i=0;i<8;i++)
             {
                     int nx=x+a[i][0],ny=y+a[i][1];
                     if(!in(nx,ny)||v[nx][ny]||(nx==x1&&ny==y1)) continue;
                     q[tail++]=nx,q[tail++]=ny;
                     v[nx][ny]=v[x][y]+1;
                     
             }
             if(v[ex][ey]) printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0],s[1],s[3],s[4],v[ex][ey]);
         }
    }
}
