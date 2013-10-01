#include<stdio.h>
#include<string.h>
__int64 farey[1000001];
__int64 e[1000001];
__int64 p[1000001];
__int64 a[1000001];
const int N=1000001;
void Prime3() 
{ 
   memset(a, 0, N*sizeof(a[0])); 
   int num = 0, i, j; 
   p[num++]=2;a[2*2]=1; 
   for(i = 3; i < N; i+=2)
   { 
      if(!(a[i])) p[num++] = i;
         for(j = 0; (j<num && i*p[j]<N); ++j) 
         { 
           a[i*p[j]] = 1; 
           if(!(i%p[j])) break;
         } 
   } 
}
void table()
{
     Prime3();
     farey[2]=1;
     e[1]=1,e[2]=1;
     __int64 j;
     for(__int64 i=3;i<=1000000;i++)
     {
         if(!a[i]) e[i]=i-1;
         else
         {   
             for(j=0;i%p[j];j++);
             if(i/p[j]%p[j]) e[i]=e[i/p[j]]*(p[j]-1);
             else e[i]=e[i/p[j]]*p[j];
         }  
         //printf("%I64d  %I64d %I64d ",e[i],i,j);     
     }
     
     for(int i=3;i<=1000000;i++)
         farey[i]=farey[i-1]+e[i];
}
int main()
{
    int n;    
    table();
    while(scanf("%d",&n)&&n)
    {
        printf("%I64d\n",farey[n]);
    }
}
