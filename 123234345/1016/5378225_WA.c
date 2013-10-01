#include<stdio.h>
#include<string.h>
void invent(char *ns,char *s)
{
     
     for(int i=0;i<=9;i++)
     {
             int len=strlen(s);
             int num=0;
             char ss[10]={0};
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
    char s[100]={0};
    while(scanf("%s",s)&&s[0]!='-')
    {
        char bfs[100];
        strcpy(bfs,s);
        int flag=0,i;
        for(i=1;i<=15;i++)
        {
            char ns[100];
            memset(ns,0,sizeof(ns));
            invent(ns,bfs);
            if(!strcmp(ns,bfs))
            {
                flag=1;
                break;
            }
            if(!strcmp(ns,s))
            {
                flag=2;
                break;
            }
            strcpy(bfs,ns);          
        }
        if(flag==1)
        {
            if(i==1) printf("%s is self-inventorying\n",s);
            else printf("%s is self-inventorying after %d steps\n",s,i-1);
        }
        if(flag==2)
        {
            printf("%s enters an inventory loop of length %d\n",s,i);
        }
        if(flag==0)
           printf("%s can not be classified after 15 iterations\n",s);
    }
}
