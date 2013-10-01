#include<stdio.h>
#include<string.h>
struct Node
{
       char s[11];
       int step;
}q[1000000];
int head,tail;
char st[11],ed[11];
char rep[2][11][11],tmp[11];
int replace(int x)
{
    char t2[101];
    strcpy(t2,tmp);
    int j=0;
    for(int i=0;tmp[i];)
    {
         if(strncmp(tmp+i,rep[0][x],strlen(rep[0][x]))==0)
         {
               strncpy(t2+j,rep[1][x],strlen(rep[1][x]));
               j+=strlen(rep[1][x]);
               i+=strlen(rep[0][x]);
         }
         else t2[j++]=tmp[i++];
    }
    t2[j]=0;
    if(j<11) strcpy(tmp,t2);
    return j;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
             scanf("%s%s",rep[0][i],rep[1][i]);
         scanf("%s%s",st,ed);
         head=tail=0;
         q[tail].step=0;
         strcpy(q[tail].s,st);
         tail++;
         int edlen=strlen(ed);
         int flag=0;
         while(head<tail)
         {
              Node cur=q[head++];
              if(strcmp(cur.s,ed)==0)
              {
                    flag=1;
                    printf("%d\n",cur.step);
                    break;
              }
              for(int i=0;i<n;i++)
              {
                   strcpy(tmp,cur.s);
                   if(replace(i)>edlen||strcmp(tmp,cur.s)==0) continue;
                   strcpy(q[tail].s,tmp);
                   q[tail++].step=cur.step+1;
              }
         }
         if(flag==0) puts("-1");
    }
}
