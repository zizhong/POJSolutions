#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char chessboard[10][10];
bool usedr[10],usedc[10];
int n,k,j,i;
bool place(int i,int j,int k)
{
     if(k==0) return true;
     if(chessboard[i][j]!='#') return false;
     if(usedr[i]||usedc[j]) return false;
     usedr[i]=true,usedc[j]=true;
     for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
            if(place(i,j,k-1)) return true;
     usedr[i]=usedc[j]=false;
     return false;
}
int main()
{
    while(cin>>n>>k)
    {
        if(n==-1&&k==-1) break;
        memset(chessboard,'#',sizeof(chessboard));
        memset(usedr,false,sizeof(usedr));
        memset(usedc,false,sizeof(usedc));
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
              cin>>chessboard[i][j];
        int count=0;
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
           if(place(i,j,k)) count++;
        cout<<count<<endl;
    }
}
