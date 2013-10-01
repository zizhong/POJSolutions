#include<stdio.h>
#include<string.h>
const int N=1001;
int l,c,w;
int trie[N*N][26];
short line[N],col[N],idx[N*N];
char dir[N],map[N][N];
int d[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int main()
{
    scanf("%d%d%d",&l,&c,&w);
    getchar();
    for(int i=0;i<l;i++) gets(map[i]);
    char word[N];
    int pos=1;
    for(int i=0;i<w;i++)
    {
            gets(word);
            int k=0,len=strlen(word),bg=0;
            int flag=0;
            while(k<len)
            {
                 int key=word[k]-'A';
                 if(!trie[bg][key])
                      trie[bg][key]=pos++,flag=1;;
                 if(k==len-1)
                 {
                             idx[bg]=i;
                             trie[bg][key]=-trie[bg][key];
                 }
                 bg=trie[bg][key];       
                 if(bg<0) bg=-bg;
                 k++;
            }
            pos-=flag;
    }
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
                for(int k=0;k<8;k++)
                {                       
                       int cur=0,num=0;                 
                       while(1)
                       {
                               int x=i+num*d[k][0],y=j+num*d[k][1];
                               if(x<0||y<0||x>=l||y>=c) break;
                               int key=map[x][y]-'A';
                               if(!trie[cur][key]) break;
                               if(trie[cur][key]<0)
                               {
                                     int id=idx[cur];
                                     line[id]=i,col[id]=j,dir[id]=k+'A';
                                     trie[cur][key]=-trie[cur][key];
                               }
                               num++;
                               cur=trie[cur][key];
                       } 
                }
        }
    }
    for(int i=0;i<w;i++)
        printf("%d %d %c\n",line[i],col[i],dir[i]);
}
