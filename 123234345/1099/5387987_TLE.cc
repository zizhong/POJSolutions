#include<stdio.h>
#include<string.h>
char ma[50][50];
int dig(int i,int j)
{
    return (ma[i-1][j]=='|')+(ma[i+1][j]=='|')+(ma[i][j-1]=='-')+(ma[i][j+1]=='-');
}
int main()
{
    int t=0,m,i,j;
    while(scanf("%d",&m)&&m)
    {
        t++;
        printf("Case %d:\n",t);
        int key[12][12];
        for(i=0;i<m;i++)
           for(j=0;j<m;j++)
           scanf("%d",&key[i][j]);
        memset(ma,' ',sizeof(ma));
        for(i=0;i<m;i++)
           for(j=0;j<m;j++)
              ma[4*i+1][4*j+3]='O';
        for(i=0;i<m;i++)
           for(j=0;j<=m;j++)
              ma[4*i+1][4*j+1]='H';
        for(i=0;i<m-1;i++)
           for(j=0;j<m;j++)
              ma[3+4*i][4*j+3]='H';
        for(i=0;i<4*m+1+2;i++)
           ma[0][i]=ma[m+(m-1)*3+1][i]='*';
        for(i=0;i<m+(m-1)*3+2;i++)
           ma[i][0]=ma[i][4*m+2]='*';
        for(i=0;i<m;i++)
           ma[4*i+1][2]=ma[4*i+1][4*m]='-';
           
        for(i=0;i<m;i++)
           for(j=0;j<m;j++)
           {
              if(key[i][j]==-1)
                  ma[4*i][4*j+3]=ma[4*i+2][4*j+3]='|';
              if(key[i][j]==1)
                  ma[4*i+1][4*j+2]=ma[4*i+1][4*j+4]='-';
           }
        
        for(i=0;i<m;i++)
           for(j=0;j<m;j++)
           {
               int cnt=dig(4*i+1,4*j+3);
               //printf("%d %d %d\n",cnt,4*i+1,4*j+3);
               while(cnt<2)
               {
                   //printf("test1 %d\n",cnt);
                   if(4*i+1-2>0&&ma[4*i+1-2][4*j+3]=='H'&&dig(4*i+1-2,4*j+3)==0) 
                   {
                       ma[4*i+1-1][4*j+3]='|';
                       
                       cnt++;
                       //printf("test2 %d\n",cnt);
                       continue;
                   }
                   if(4*i+1+2<4*m-1&&ma[4*i+1+2][4*j+3]=='H'&&dig(4*i+1+2,4*j+3)==0)
                   {
                       ma[4*i+1+1][4*j+3]='|';
                       cnt++;
                       continue;
                   }
                   if(4*j+3-2>0&&ma[4*i+1][4*j+3-2]=='H'&&dig(4*i+1,4*j+3-2)==0)
                   {
                       ma[4*i+1][4*j+3-1]='-';
                       cnt++;
                       continue;
                   }
                   if(4*j+3+2<4*m+3&&ma[4*i+1][4*j+3+2]=='H'&&dig(4*i+1,4*j+3+2)==0)
                   {
                       ma[4*i+1][4*j+3+1]='-';
                       cnt++;
                       continue;
                   }
               }
           }
          
        for(i=0;i<m+(m-1)*3+2;i++)
        {
            for(j=0;j<4*m+1+2;j++)
              printf("%c",ma[i][j]);
            printf("\n");
        }
        
        
        
           
    }
}
