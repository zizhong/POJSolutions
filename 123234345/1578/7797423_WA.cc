#include<stdio.h>
#include<string.h>
char entry[22][100][100];
char map[22][100];
int n,m;
void draw_table(char ag[])
{
     memset(map,' ',sizeof(map));
     int col[100]={0};
     int len[22][100];
     for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
            len[i][j]=strlen(entry[i][j]);
     for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(col[j]<len[i][j]) col[j]=len[i][j];
     int ll[100]={0};//'|' 
     
     
     for(int i=1;i<=m;i++)
         ll[i]=ll[i-1]+3+col[i-1];
     int N=n+3,M=ll[m]+1;
     // draw '-'
     for(int i=0;i<M;i++)
             map[0][i]=map[N-1][i]=map[2][i]='-';
     //draw '|' or '+'
     for(int i=0;i<=m;i++)
         for(int j=0;j<N;j++)
            if(map[j][ll[i]]==' ') map[j][ll[i]]='|';
            else map[j][ll[i]]='+';
     //draw '@'
     map[0][0]=map[0][M-1]=map[N-1][0]=map[N-1][M-1]='@';
     //draw words
     for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
         {
               int k;
               switch(ag[j])
               {
                   case '<':k=ll[j]+2;break;
                   case '>':k=ll[j+1]-1-len[i][j];break;
                   case '=':k=ll[j]+(ll[j+1]-ll[j]-len[i][j])/2;break;
               }
               for(int h=0;entry[i][j][h];h++)
                   if(i==0) map[1][k++]=entry[i][j][h];
                   else map[i+2][k++]=entry[i][j][h];
         }
     //draw '\0'
     for(int i=0;i<N;i++)
         map[i][M]=0;
     for(int i=0;i<N;i++)
         puts(map[i]);
}
int main()
{
    
    char s[100],ag[100];
    gets(ag);
    while(1)
    {
         m=strlen(ag);
         n=0;
         while(gets(s),s[0]!='<'&&s[0]!='='&&s[0]!='>'&&s[0]!='*')
         {
              int j=0,k=0;
              for(int i=0;s[i];i++)
              {
                   if(s[i]=='&')
                   {
                       entry[n][j][k]=0;
                       j++;
                       k=0;
                   }
                   else entry[n][j][k++]=s[i];
              }
              entry[n][j][k]=0;
              n++;
         }
         /*for(int i=0;i<n;i++,puts(""))
              for(int j=0;j<m;j++)
                  printf("%s ",entry[i][j]);*/
         draw_table(ag);
         if(s[0]=='*') break;
         strcpy(ag,s);
    }
}
