#include<stdio.h>
#include<string.h>
const int N=8;
char ch[N][N];
char con[4]={":."};
int main()
{
    memset(ch,0,sizeof(ch));
    char s[100];
    scanf("%s",s);
    scanf("%s",s);
    for(int i=0;s[i];)
    {
         int c=0,x,y;
         while(s[i]!=','&&s[i]!=0)
         {
              if(s[i]>='0'&&s[i]<='9')
                  x=8-(s[i]-'0');
              if(s[i]>='a'&&s[i]<='z')
                  y=s[i]-'a';
              if(s[i]>='A'&&s[i]<='Z')
                  c=s[i];
              i++;
         }
         //printf("<%d %d %d>\n",c,x,y);
         if(c==0) c='P';
         ch[x][y]=c;
         if(s[i]) i++;
    }
    //for(int i=0;i<8;i++,puts(""))
    //    for(int j=0;j<8;j++) putchar(ch[i][j]);
    scanf("%s",s);
    scanf("%s",s);
    for(int i=0;s[i];)
    {
         int c=0,x,y;
         while(s[i]!=','&&s[i]!=0)
         {
              if(s[i]>='0'&&s[i]<='9')
                  x=8-(s[i]-'0');
              if(s[i]>='a'&&s[i]<='z')
                  y=s[i]-'a';
              if(s[i]>='A'&&s[i]<='Z')
                  c=s[i]-'A'+'a';
              i++;
         }
         if(c==0) c='p';
         ch[x][y]=c;
         if(s[i]) i++;
    }
    
    for(int i=0;i<17;i++)
    {
         for(int j=0;j<17;j++)
         {
              if(((i+1)&1) && ((j+1)&1))
                  putchar('+');
              if(((i  )&1) && ((j+1)&1))
                  putchar('|');
              if(((i+1)&1) && ((j  )&1))
                  putchar('-'),putchar('-'),putchar('-');
              if(((i  )&1) && ((j  )&1))
              {
                    int idx=((i+j)>>1)&1;
                    putchar(con[idx]);
                    putchar(ch[i>>1][j>>1]?ch[i>>1][j>>1]:con[idx]);
                    putchar(con[idx]);
              }
              
         }
         puts("");
    }
}
