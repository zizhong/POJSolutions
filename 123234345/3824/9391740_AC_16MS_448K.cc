#include<stdio.h>
const int N=101;
struct Card{int id,p;};
struct Pile
{
       Card card[N];
       int nc;
}pile[N];
int n,h,t;
Pile res;
void init()
{
     for(int i=1;i<=n;i++)
        pile[i].nc=1;
     h=1,t=n;
     for(int i=1;i<=n;i++)
         pile[i].card[1].id=i;
     char s[101];
     scanf("%s",s);
     for(int i=1;i<=n;i++)
          if(s[i-1]=='U')
              pile[i].card[1].p=1;
          else pile[i].card[1].p=0;
}
void deal()
{
     char op[101];
     scanf("%s",op);
     for(int k=0;op[k];k++)
     {
         if(op[k]=='L')
         {
              Pile pt;
              pt.nc=pile[h].nc+pile[h+1].nc;
              for(int i=1;i<=pile[h].nc;i++)
              {
                   pt.card[i].id=pile[h].card[pile[h].nc+1-i].id;
                   pt.card[i].p =pile[h].card[pile[h].nc+1-i].p^1;
              }
              for(int i=1;i<=pile[h+1].nc;i++)
              {
                   pt.card[i+pile[h].nc].id=pile[h+1].card[i].id;
                   pt.card[i+pile[h].nc].p =pile[h+1].card[i].p;
              }
              pile[h+1]=pt;
              h++;
         }
         else
         {
             Pile pt;
             pt.nc=pile[t].nc+pile[t-1].nc;
             for(int i=1;i<=pile[t].nc;i++)
             {
                   pt.card[i].id=pile[t].card[pile[t].nc+1-i].id;
                   pt.card[i].p =pile[t].card[pile[t].nc+1-i].p^1;
             }
             for(int i=1;i<=pile[t-1].nc;i++)
             {
                   pt.card[i+pile[t].nc].id=pile[t-1].card[i].id;
                   pt.card[i+pile[t].nc].p =pile[t-1].card[i].p;
             }
             pile[t-1]=pt;
             t--;
         }
     }
     res=pile[h];
}
int main()
{
    int T=1;
    while(scanf("%d",&n),n)
    {
         init();
         deal();
         printf("Pile %d\n",T++);
         int q;
         scanf("%d",&q);
         while(q--)
         {
              int k;
              scanf("%d",&k);
              printf("Card %d is a face %s %d.\n",k,res.card[k].p?"up":"down",res.card[k].id);
         }                    
    }
}
