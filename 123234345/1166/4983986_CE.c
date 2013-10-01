#include<iostream>
using namespace std;
int move[9][9]=
    {
    1,1,0,1,1,0,0,0,0,
    1,1,1,0,0,0,0,0,0,
    0,1,1,0,1,1,0,0,0,
    1,0,0,1,0,0,1,0,0,
    0,1,0,1,1,1,0,1,0,
    0,0,1,0,0,1,0,0,1,
    0,0,0,1,1,0,1,1,0,
    0,0,0,0,0,0,1,1,1,
    0,0,0,0,1,1,0,1,1
    };
int states[9],way[9];
bool check()
{  
    int i,j,sum[9]={0};
    for(i=0;i<9;i++)
       for(j=0;j<9;j++)
       sum[i]=way[j]*move[j][i]+sum[i];
    for(i=0;i<9;i++)
       if((sum[i]+states[i])%4)
       return false;
    return true;
}
int main()
{ 
   int i,k=0;
   for(i=0;i<9;i++)
      cin>>states[i];
   for(way[0]=0;way[0]<4;way[0]++)
   for(way[1]=0;way[1]<4;way[1]++)
   for(way[2]=0;way[2]<4;way[2]++)
   for(way[3]=0;way[3]<4;way[3]++)
   for(way[4]=0;way[4]<4;way[4]++)
   for(way[5]=0;way[5]<4;way[5]++)
   for(way[6]=0;way[6]<4;way[6]++)
   for(way[7]=0;way[7]<4;way[7]++)
   for(way[8]=0;way[8]<4;way[8]++)
   {
      if(check())
      {
        
        for(i=0;i<9;i++)
        while(way[i]--)
           cout<<i+1<<' ';
        cout<<endl;
        return 0;
      }
   }
}
