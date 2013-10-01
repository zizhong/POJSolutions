#include<stdio.h>
#include<math.h>
int com[4][1002];
int d;
int Find(int i)
{
   int r=i;
   while(com[0][i]>0)
      i=com[0][i];
   while(i!=r)
   {
     int q=com[0][r];
     com[0][r]=i;
     r=q;
   }
   return r;
}
void Union(int a,int b)
{
   int t1=Find(a);
   int t2=Find(b);
   int temp=com[0][t1]+com[0][t2];
   if(com[0][t1]<com[0][t2])
   {
      com[0][t2]=t1;
      com[0][t1]=temp;
   }
   else
   {
      com[0][t1]=t2;
      com[0][t2]=temp; 
   }   
}
main()
{
    int n,i,j,num,num2;
    double  t;
    char c;
    scanf("%d%d",&n,&d);
    for(i=1;i<=n;i++)
    {
       com[0][i]=-1;
       scanf("%d%d",&com[1][i],&com[2][i]);
       com[3][i]=0;
    }
    while(scanf("%c%d",&c,&num)!=EOF)
    {
       if(c=='O')
       {
          com[3][num]=1;
          for(i=1;i<=n;i++)
            if(com[3][i]&&i!=num&&Find(num)!=Find(i))
            {    
               t=sqrt((com[1][num]-com[1][i])*(com[1][num]-com[1][i])+(com[2][num]-com[2][i])*(com[2][num]-com[2][i]));
               if(d>=t)
               {
               Union(num,i);
               }
            }
       }
       if(c=='S')
       {
        scanf("%d",&num2);
        if(Find(num)==Find(num2)) printf("SUCCESS\n");
        else printf("FAIL\n");
       }
    }}
