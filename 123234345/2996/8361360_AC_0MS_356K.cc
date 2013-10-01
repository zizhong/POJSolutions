#include<stdio.h>
const int N=8;
char map[N][N];
char Wh[]={"KQRBNP"};
char Bk[]={"kqrbnp"};
int firW,firB;
void find_Wh(char c)
{
     for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(map[i][j]==c)
            {
                 if(firW) putchar(',');
                 firW=1;
                 if(c!='P') putchar(c);
                 printf("%c%d",j+'a',i+1);
            }
}
void find_Bk(char c)
{
     for(int i=N-1;i>=0;i--)
         for(int j=0;j<N;j++)
            if(map[i][j]==c)
            {
                 if(firB) putchar(',');
                 firB=1;
                 if(c!='p') putchar(c-'a'+'A');
                 printf("%c%d",j+'a',i+1);
            }
}
int main()
{
    for(int i=N-1;i>=0;i--)
    {
         char s[32];
         scanf("%s",s);
         scanf("%s",s);
         for(int j=0;j<N;j++)
              map[i][j]=s[j*4+2];
    }
    printf("White: ");
    for(int i=0;Wh[i];i++) find_Wh(Wh[i]);
    puts("");
    printf("Black: ");
    for(int i=0;Bk[i];i++) find_Bk(Bk[i]);
    puts("");
}
