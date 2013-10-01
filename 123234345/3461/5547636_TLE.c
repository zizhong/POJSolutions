#include<stdio.h>
#include<string.h>
char w[10001];
char t[1000001];
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
         int i,j,k,occurance=0;
         gets(w);gets(t);
         for(k=0;t[k];k++)
         {
             for(i=0;w[i]&&(t[k+i]==w[i]);++i) ;
             if(!w[i]) ++occurance;
         }
         printf("%d\n",occurance);
    }
}
