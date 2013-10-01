#include<stdio.h>
#include<string.h>
const int N=28;
void analy(char s[],int a[][N])
{
     int mark[110][3]={0},n=strlen(s);
     for(int i=0;i<n;i++)
     {
             if(s[i]>='0'&&s[i]<='9')
             {
                  if(i==0||s[i-1]<'0'||s[i-1]>'9')
                       mark[i][0]=s[i]-'0',mark[i][1]=1;
                  if(i>0&&s[i-1]>='0'&&s[i-1]<='9')
                  {
                       mark[i][0]=mark[i-1][0]*10+s[i]-'0';
                       mark[i][1]=1,mark[i-1][1]=5;
                  }
             }
             if(s[i]>='A'&&s[i]<='Z')
             {
                  if(s[i+1]>='a'&&s[i+1]<='z')
                  {
                       mark[i+1][1]=5;
                       mark[i][0]=(s[i]-'A'+1)*N+s[i+1]-'a'+1;
                       mark[i][1]=2;
                       i++;
                       continue;
                  }
                  mark[i][0]=(s[i]-'A'+1)*N;
                  mark[i][1]=2;
             }
             if(s[i]=='(') mark[i][0]=1,mark[i][1]=3;
             if(s[i]==')') mark[i][0]=-1,mark[i][1]=3;
             if(s[i]=='+') mark[i][1]=4;
     }
     int m=0;
     for(int i=0;i<n;i++)
     {
             if(mark[i][1]==2) mark[i][2]=1;
             if(mark[i][1]==5) continue;
             if(i==m) m++;
             else
             {
                 mark[m][0]=mark[i][0];
                 mark[m][1]=mark[i][1];
                 mark[m][2]=mark[i][2];                 
                 m++;
             }
     }
     for(int i=0;i<m;i++)
     {
          if(mark[i][1]==1&&mark[i][2]==0)
          {
               if(i>0&&mark[i-1][1]==2)
                      mark[i][2]=1,mark[i-1][2]*=mark[i][0];
          }   
     }
     int st[110]={0},top=0;
     for(int i=0;i<m;i++)
     {
             if(mark[i][1]==3)
             {
                   if(mark[i][0]==1) st[top++]=i;
                   else
                   {
                       int left=st[--top],right=i,X=1;
                       if(mark[left-1][1]==1&&mark[left-1][2]==0) mark[left-1][2]=1,X*=mark[left-1][0];
                       if(mark[right+1][1]==1&&mark[right+1][2]==0) mark[right+1][2]=1,X*=mark[right+1][0];
                       if(X>1) for(int j=left;j<=right;j++) if(mark[j][1]==2)
                       mark[j][2]*=X;
                   }
             }
     }
     int d=1;
     for(int i=0;i<m;i++)
     {
             if(mark[i][1]==1&&mark[i][2]==0&&(i==0||mark[i-1][1]==4)) d=mark[i][0];
             if(d>1)
             while(i<m&&mark[i][1]!=4)
             {
                    if(mark[i][1]==2) mark[i][2]*=d;
                    i++;
             }
             if(mark[i][1]==4) d=1;
     }
     for(int i=0;i<m;i++) if(mark[i][1]==2)
             a[mark[i][0]/N][mark[i][0]%N]+=mark[i][2];
}
int main()
{
    char s1[110];
    scanf("%s",s1);
    int ET1[N][N]={0};
    analy(s1,ET1);
    int T;
    scanf("%d",&T);
    while(T--)
    {
         char s2[110];
         scanf("%s",s2);
         int ET2[N][N]={0};
         analy(s2,ET2);
         int flag=1;
         for(int i=0;i<N;i++)
             for(int j=0;j<N;j++)
                 if(ET1[i][j]!=ET2[i][j])
                    {flag=0;break;}
         printf("%s%c=%s\n",s1,flag?'=':'!',s2);
    }
}
