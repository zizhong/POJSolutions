#include<stdio.h>
char s1[101][31],s2[101][31];
char s[101][101];
int t=0;
void print_lcs(int i,int j)
{
     if(!i||!j) return ;
     if(s[i][j]=='D')
     {
         print_lcs(i-1,j-1);            
         if(t) printf(" ");
         printf("%s",s1[i]);
         t++;
     }
     if(s[i][j]=='U') print_lcs(i-1,j);
     if(s[i][j]=='L') print_lcs(i,j-1);
}
int main()
{
    int i=1,j,m,n;
    while(scanf("%s",s1[1])+1)
    {
    t=0;
    int f[101][101]={0};
    i=2;
    while(scanf("%s",s1[i])&&strcmp(s1[i],"#")) i++;
    m=i-1;
    i=1;
    while(scanf("%s",s2[i])&&strcmp(s2[i],"#")) i++;
    n=i-1;     
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
       {
           if(strcmp(s1[i],s2[j])==0) s[i][j]='D',f[i][j]=f[i-1][j-1]+1;
           else if(f[i][j-1]<f[i-1][j]) f[i][j]=f[i-1][j],s[i][j]='U';
           else f[i][j]=f[i][j-1],s[i][j]='L';    
       }
    print_lcs(m,n);
    printf("\n");
    }
}
