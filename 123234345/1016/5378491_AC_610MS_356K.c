#include<stdio.h>
#include<string.h>
void invent(char *ns,char *s)
{
     
     for(int i=0;i<=9;i++)
     {
             int len=strlen(s);
             int num=0;
             char ss[100]={0};
             for(int j=0;j<len;j++)
             {
                     if(s[j]=='0'+i)
                         num++;
             }
             if(num)
               sprintf(ss,"%d%d",num,i);
             strcat(ns,ss);
     }
}
int main()
{
    char s[200]={0};
    /*while(scanf("%s",s))
    {
        for(int i=1;i<=15;i++)
        {
            char ns[100];
            memset(ns,0,sizeof(ns));
            invent(ns,s);
            printf("%s\n",ns);
            strcpy(s,ns);
        }
    }*/
    while(scanf("%s",s)&&s[0]!='-')
    {
        char bfs[200];
        strcpy(bfs,s);
        int flag=0,i;
        char ns[16][200];
        memset(ns,0,sizeof(ns));
        for(i=1;i<=15;i++)
        {
            invent(ns[i],bfs);
            strcpy(bfs,ns[i]);          
        }
        if(!strcmp(ns[1],ns[2])) 
        {
           printf("%s is self-inventorying\n",s);
        }
        else 
        {
            int flag=0;
            for(i=3;i<=15;i++)
               if(!strcmp(ns[i],ns[i-1])) 
               {
                 printf("%s is self-inventorying after %d steps\n",s,i-1);
                 flag=1;
                 break;
               }
            if(flag==0)
            {
               int j,k;
               for(j=1;j<=15;j++)
               {
                  for(k=j+2;k<=15;k++)
                  if(!strcmp(ns[j],ns[k]))
                  {
                      printf("%s enters an inventory loop of length %d\n",s,k-j);
                      flag=2;
                      break;
                  }
                  if(flag) break;
               }
            if(flag==0)
               printf("%s can not be classified after 15 iterations\n",s);
            }
        }
    }
}
