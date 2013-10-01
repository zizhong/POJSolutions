#include<stdio.h>
#include<string.h>
int g[27][27],in[27];
char map[51][21];
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    memset(map,'.',sizeof(map));
    memset(in,-1,sizeof(in));
    for(int i=n-1;i>=0;i--)
       gets(map[i]);
    for(int i=0;i<n;i++)
       for(int j=0;j<20;j++)
         if(map[i][j]!='.')
         { 
               if(in[map[i][j]-'A']==-1) in[map[i][j]-'A']=0;
               if(map[i+1][j]!='.')
               {
                    if(in[map[i+1][j]-'A']==-1) in[map[i+1][j]-'A']=0;
                    if(map[i][j]!=map[i+1][j]&&g[map[i][j]-'A'][map[i+1][j]-'A']==0)
                    g[map[i][j]-'A'][map[i+1][j]-'A']=1,in[map[i+1][j]-'A']++;
               }
               
         }
    //for(int i=0;i<26;i++)  printf("(%c %d),",i+'A',in[i]);
    //puts("");
    for(int k=0;k<26;k++)
    {
        int i;
        for(i=0;i<26&&in[i];i++) ;
        if(i==26) break;
        printf("%c",i+'A');
        in[i]=-1;
        for(int j=0;j<26;j++)
            if(g[i][j]) in[j]--;
    }
    //for(int i=0;i<26;i++) printf("(%c %d),",i+'A',in[i]);
    puts("");
    //scanf("%d",&n);
}
