#include<stdio.h>
#include<stdlib.h>
struct Opr
{
       int letter;
       int tm;
}opr[64];
int cmp(const void *a,const void *b)
{
    Opr * p1=(Opr *)a;
    Opr * p2=(Opr *)b;
    return p1->tm - p2->tm;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int board[26]={0};
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
             char s[8];
             int a,b;
             scanf("%s%d%d",s,&a,&b);
             opr[2*i].letter=s[0]-'A',opr[2*i].tm=a;
             opr[2*i+1].letter=s[0]-'A',opr[2*i+1].tm=b;
        }
        n*=2;
        qsort(opr,n,sizeof(opr[0]),cmp);
        
        for(int i=0;i<n;)
        {
             int nowt=opr[i].tm;
             while(i<n&&opr[i].tm==nowt)
             {
                 board[opr[i].letter]=(board[opr[i].letter]+1)%2;
                 i++;
             }
             if(i<n)
             {
                 int num=0;     
                 for(int k=0;k<26;k++) if(board[k]) ++num;
                 int nt=opr[i].tm-opr[i-1].tm;
                 if(num)
                 while(nt--)
                 {
                     printf("%c",num+'A'-1);
                 }
             }
             
        }
        printf("\n");
    }
    //system("pause");
}
