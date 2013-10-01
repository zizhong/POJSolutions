
#include<stdio.h>
#include<string.h>
const int N=101;
int len;
struct Node
{
       char path[N];
       int step;
}q[N*N*N];
int ok(char s[])
{
    int i=0,j=len-1;
    while(s[i]!='B') i++;
    while(s[j]!='B') j--;
    for(int k=i;k<=j;k++)
       if(s[k]=='W') return 0;
    return 1;
}
int main()
{
    int T=1;
    char s[N];
    while(scanf("%s",s),s[0]!='-')
    {
         int head=0,tail=0;
         len=strlen(s);
         int sb=0;
         for(int i=0;i<len;i++)
             if(s[i]=='B') sb++;
         printf("%d. ",T++);
         if(sb<2)
         {
              printf("0\n");
              continue;
         }
         strcpy(q[tail].path,s);
         q[tail++].step=0;
         int flag=0;
         
         while(head<tail)
         {
              Node cur=q[head++];
              if(ok(cur.path))
              {
                  flag=1;
                  printf("%d\n",cur.step);
                  break;
              }
              if(cur.step>=9) break;
              int fp=0;
              for(int i=0;i<len;i++)
                 if(cur.path[i]=='F')
                    {fp=i;break;}
              if(fp>0)
              {
                   strcpy(q[tail].path,cur.path);
                   q[tail].step=cur.step+1;
                   q[tail].path[fp]=q[tail].path[fp-1];
                   q[tail].path[fp-1]='F';
                   tail++;
              }
              if(fp>1)
              {
                   strcpy(q[tail].path,cur.path);
                   q[tail].step=cur.step+1;
                   q[tail].path[fp]=q[tail].path[fp-2]=='W'?'B':'W';
                   q[tail].path[fp-2]='F';
                   tail++;
              }
              if(fp<len-1)
              {
                   strcpy(q[tail].path,cur.path);
                   q[tail].step=cur.step+1;
                   q[tail].path[fp]=q[tail].path[fp+1];
                   q[tail].path[fp+1]='F';
                   tail++;
              }
              if(fp+2<len)
              {
                   strcpy(q[tail].path,cur.path);
                   q[tail].step=cur.step+1;
                   q[tail].path[fp]=q[tail].path[fp+2]=='W'?'B':'W';
                   q[tail].path[fp+2]='F';
                   tail++;
              }
         }
         if(flag==0) puts("-1");
    }
}

