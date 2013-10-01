#include<stdio.h>
const int N=61,MID=20;
int table[3][3][2]={{{1,0},{1,-1},{2,-1}},{{0,1},{0,0},{1,0}},{{-1,2},{0,0},{0,-1}}};
double f[21][N][N];
int v[21][N][N];
int main()
{
    f[0][MID][MID]=1;
    v[0][MID][MID]=1;
    puts("Round   A wins    B wins    Tie");
    for(int i=1;i<=20;i++)
    {
            for(int j=0;j<N;j++)
               for(int k=0;k<N;k++) if(v[i-1][j][k])
               for(int ii=0;ii<3;ii++) for(int jj=0;jj<3;jj++)
               {
                    double f1=0.5,f2=0.5;
                    if(ii-1) f1*=0.5;
                    if(jj-1) f2*=0.5;
                    v[i][j+table[ii][jj][0]][k+table[ii][jj][1]]=1;
                    f[i][j+table[ii][jj][0]][k+table[ii][jj][1]]+=f1*f2*f[i-1][j][k];
               }
            double Awin=0,Bwin=0,tie=0;
            for(int j=0;j<N;j++)
            {
                for(int k=0;k<N;k++)
                {
                    if(v[i][j][k])
                    if(j>k) Awin+=f[i][j][k];
                    else if(j<k) Bwin+=f[i][j][k];
                    else tie+=f[i][j][k];
                }
            }
            printf("    %d   %.4f%%  %.4f%%  %.4f%%\n",i,Awin*100,Bwin*100,tie*100);
    }
   }
