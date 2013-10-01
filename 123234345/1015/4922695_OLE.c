#include<stdio.h>
int jury,a[2][201],r[21],f[201];
main()
{
   int n,m,i,j,d,p,id,ip,mind,maxh,k;
   while(1)
   {
      scanf("%d%d",&n,&m);
      if(n*m==0) break;
      jury++;
      for(i=1;i<=n;i++)
        {
        scanf("%d%d",&a[0][i],&a[1][i]);
        f[i]=0;
        }
      d=p=0;mind=~(1<<31),maxh=0;
      for(i=1;i<=m;i++)
      {  k=1;
        for(j=1;j<=n;j++,k++)
         if(!f[j]) 
        {
        if(k==1)
        {
           mind=abs((d+a[0][j])-(a[1][j]+p));
           r[i]=j;
           maxh=abs((d+a[0][j])+(a[1][j]+p));
        }
         if(abs((d+a[0][j])-(a[1][j]+p))<mind)
         {
            mind=abs((d+a[0][j])-(a[1][j]+p));
            r[i]=j;
         }
         if(abs((d+a[0][j])-(a[1][j]+p))==mind&&
                  (abs((d+a[0][j])+(a[1][j]+p))>maxh))
         {
             r[i]=j;
             maxh=abs((d+a[0][j])+(a[1][j]+p));
         }
        }
        f[r[i]]=1;
        d+=a[0][r[i]];
        p+=a[1][r[i]];
        mind=abs(d-p);
        maxh=abs(d+p);
      }
      printf("Jury #%d\n",jury);
      printf("Best jury has value %d for prosecution and value %d for defence:\n",d,p);
      for(i=1;i<=n;i++)
         if(f[i]) printf(" %d",i);
      printf("\n");
   }
}
