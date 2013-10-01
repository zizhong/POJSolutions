#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct PEO
{
     char name[50];
     int weight;  
}peo[1000];
int cmp(const void *a,const void *b)
{
    PEO* c=(PEO*)a;
    PEO* d=(PEO*)b;
    return d->weight - c->weight;
}
int main()
{
    char st[11];
    bool first=true;
    while(scanf("%s",st)!=EOF)
    {
        char nm[50];
        int i=0,day,w;
        while(scanf("%s",nm)&&strcmp(nm,"END"))
        {
            scanf("%d%d",&day,&w);
            strcpy(peo[i].name,nm);
            peo[i].weight=w-day;
            i++;
        }
        int n=i;
        qsort(peo,n,sizeof(peo[0]),cmp);
        if(!first) printf("\n");
        for(i=0;i<n;i++)
        {
            printf("%s\n",peo[i].name);
        }
        first=false;
    }
}
