#include<cstdio>
#include<cstring>
char txt[1024][181];
int main()
{
    
    int n=0;
    while(gets(txt[n++])!=NULL) ;
    int maxlen[181]={0},maxc=0;
    for(int i=0;i<n;i++)
    {
        int p=0,j=0;
        char s[81];
        while(sscanf(txt[i]+p,"%s",s)==1)
        {
            int len=strlen(s);
            if(maxlen[j]<len) maxlen[j]=len;
            while(txt[i][p]==' ') p++;
            p+=len;
            j++;
        }
        if(maxc<j) maxc=j;
    }
    for(int i=0;i<n;i++)
    {
        int p=0,j=0,prelen;
        char s[81];
        while(sscanf(txt[i]+p,"%s",s)==1)
        {
            if(j)
            {
                int c=maxlen[j-1]+1-prelen;
                while(c--) putchar(' ');
            }
            int len=strlen(s);
            prelen=len;
            for(int k=0;k<len;k++) putchar(s[k]);
            while(txt[i][p]==' ') p++;
            p+=len;
            j++;
        }
        puts("");
    }
}
