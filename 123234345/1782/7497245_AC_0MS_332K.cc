#include<stdio.h>
char s[1000000];
int main()
{
    while(gets(s))
    {
        int k,i,ki;
        for(i=0;s[i];)
        {
             k=1,ki=1;
             /*if((s[i]=='1'&&s[i+1]!='1'))
             {
                  putchar('1'),putchar('1');
                  i++;
                  continue;
             }*/
             while(k<9&&s[i]==s[i+k]) k++;
             while(s[i+ki]&&s[i+ki-1]!=s[i+ki]&&s[i+ki]!=s[i+ki+1]) ki++;
             if(k>1)
             {
                  putchar('0'+k);
                  putchar(s[i]);
                  i+=k;
             }else
             {
                  putchar('1');
                  for(int j=i;j<i+ki;j++)
                  {
                      putchar(s[j]);
                      if(s[j]=='1') putchar('1');
                  }
                  putchar('1');
                  i+=ki;
                  
             }
        }
        puts("");
    }
}
