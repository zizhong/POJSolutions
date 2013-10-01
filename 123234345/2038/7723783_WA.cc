#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int N=101;
char s[121][6];
char f[N][6];
int pos(char c,char s1[])
{
    int ans=0;
    while(s1[ans]!=c) ans++;
    return ans;
}
int main()
{
    char str[6]={"ABCDE"};
    int nn=0;
    do
    {
         strcpy(s[nn++],str);
    }while(next_permutation(str,str+5));
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
             scanf("%s",f[i]);
         int min=10*100+1,mi=-1;
         for(int i=0;i<nn;i++)
         {
              int ans=0;
              for(int j=0;j<n;j++)
              {
                   for(int x=0;x<5;x++)
                      for(int y=x+1;y<5;y++)
                      {
                           int px1=pos(s[i][x],s[i]),
                               px2=pos(s[i][x],f[j]),
                               py1=pos(s[i][y],s[i]),
                               py2=pos(s[i][y],f[j]);
                           if((px1-py1)*(px2-py2)<0) ans++;
                      }
              }
              if(ans<min) min=ans,mi=i;
         }
         printf("%s is the median ranking with value %d.\n",f[mi],min);
    }
}
