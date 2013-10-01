#include<stdio.h>
#include<string.h>
int pairs[1001],num;
int Exp[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,1E10};
void Print(int n,int length)
{
     int i,j,t,tn=num;
     for(i=0;i<num-1;++i)
         for(j=i+1;j<num;j++) if(pairs[i]>pairs[j])
         {
               t=pairs[i];
               pairs[i]=pairs[j];
               pairs[j]=t;
         }
     for(i=0;i<num;i++) if(pairs[i+1]==pairs[i]) tn--;
     printf("%d\n",tn);
     for(i=0;i<num;i++)
     {
          if(pairs[i+1]==pairs[i]) continue;
          printf("%d + ",pairs[i]);
          char s[11];
          int k=n-pairs[i];
          sprintf(s,"%d",k);
          int len=strlen(s),h;
          if(pairs[i]<Exp[length-1]) h=length-2;
          else h=length-1;
          h-=len;
          while(h--) putchar('0');
          printf("%d = %d\n",k,n);
     }
}
void solve(int n)
{
     int i,j,t,len=1;
     for(;;++len) if(n<Exp[len]) break;
     for(i=0;i!=(len>>1);++i)
     {
         if(i&&(n%2)) break;
         for(t=-Exp[i+1]+1;(10*(n%11)+t)%11;t++) ;
         for(j=(10*(__int64)(n)+t)/11;t<Exp[i+1];t+=11,j++)
         {
               if(t==(j%Exp[i+1]-10*(j%Exp[i])))
                    pairs[num++]=j;
         }
     }
     for(;i!=len;++i)
     {
          if(n%2) break;
          j=(Exp[i]+n)>>1;
          for(;j<=n;j+=Exp[i]/2)
          {
                t=(2*j-n)/Exp[i];
                if(t==(j/Exp[i]-j/Exp[i+1])) pairs[num++]=j;
          }
     }
     Print(n,len);
}
int main()
{
    int n;
    scanf("%d",&n);
    solve(n);
   // scanf("%d",&n);
}
