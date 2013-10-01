#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}
struct ST
{
       char s[21];
       int i;
}s[1000];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i=0;
    char str[1000][2][21];
    while(gets(s[i].s)!=NULL) strcpy(str[i][0],s[i].s),s[i].i=i++;
    int n=i,j,k;
    qsort(s,n,sizeof(s[0]),cmp);
    //for(i=0;i<n;i++) printf("%s\n",s[i].s);
    for(j=0;s[0].s[j]==s[1].s[j]&&s[0].s[j];j++);
    strncpy(str[s[0].i][1],s[0].s,j+1);
    for(i=1;i<n-1;i++)
    {
         for(j=0;s[i].s[j]==s[i-1].s[j]&&s[i].s[j];j++) ;
         for(k=0;s[i].s[k]==s[i+1].s[k]&&s[i].s[k];k++) ;
         j=(j>k?j:k)+1;
         strncpy(str[s[i].i][1],s[i].s,j);
         if(i==n-2) strncpy(str[s[n-1].i][1],s[n-1].s,k+1);
    }
    for(i=0;i<n;i++) printf("%s %s\n",str[i][0],str[i][1]);
}
