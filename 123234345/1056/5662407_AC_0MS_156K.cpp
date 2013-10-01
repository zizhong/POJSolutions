#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}
int main()
{
    char s[16][16];
    int idx=0;
    int nt=0;
    while(1)
    {
        scanf("%s",s[idx++]);
        if(s[idx-1][0]=='9')
        {
            int i;
            qsort(s,idx,sizeof(s[0]),cmp);
            for(i=0;i<idx-1;i++)
                if(strncmp(s[i],s[i+1],strlen(s[i]))==0) break;
            printf("Set %d is %simmediately decodable\n",++nt,i<idx-1?"not ":"");
            idx=0;
            if(scanf("%s",s[idx++])==EOF) return 0;
        }
    }
}
