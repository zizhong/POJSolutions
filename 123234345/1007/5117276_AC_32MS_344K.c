#include<stdio.h>
#include<stdlib.h>
struct DNA
{
       char str[52];
       int n;
}dna[101];
int cmp(const void*a,const void* b)
{
    struct DNA* c=(struct DNA*)a;
    struct DNA* d=(struct DNA*)b;
    return c->n-d->n;
}
int main()
{
    int m,i,j,k,len;
    scanf("%d%d",&len,&m);
    for(i=0;i<m;i++)
    {
      scanf("%s",dna[i].str);
      for(j=0;j<len;j++)
        for(k=j+1;k<len;k++)
        if(dna[i].str[j]>dna[i].str[k]) dna[i].n++;
    }
    qsort(dna,m,sizeof(dna[0]),cmp);
    for(i=0;i<m;i++)
      printf("%s\n",dna[i].str);}
