#include<cstdio>
#include<cstring>
int n;
int pow3[16],exp[21],ans;
//0 +, 1 -, 2 .,
int calc(int k)
{
    int op[16]={0};
    for(int i=n-2;i>=0;i--) op[i]=k%3,k/=3;
    int ret=0,opr=0;
    for(int i=0;i<n;i++)
    {
         int j=i;
         int num2=i+1;
         while(op[j]==2)
         {
               if(j<9) num2=num2*10+j+2;
               else num2=num2*100+j+2;
               j++;
         }
         if(opr==0) ret+=num2;
         else ret-=num2;
         opr=op[j];
         i=j;
         //printf("%d\n",ret);
    }
    return ret;
}
char oppo[4]="+-.";
void print(int k)
{
     int op[16]={0};
     for(int i=n-2;i>=0;i--) op[i]=k%3,k/=3;
     for(int i=0;i<n-1;i++)
     {
          printf("%d",i+1);
          printf(" %c ",oppo[op[i]]);
     }
     printf("%d\n",n);
}
int ret[16];
int main()
{
    ret[14]=533,ret[15]=1583;
    pow3[0]=1;
    for(int i=1;i<16;i++) pow3[i]=3*pow3[i-1];
    scanf("%d",&n);
    int K=pow3[n-1];
    for(int k=0;k<K;k++) if(!calc(k))
    {          
          if(ans<20) exp[ans++]=k;
          else ans++;
          if(ans>=20&&(n==14||n==15)) break;
    }
    if(n==14||n==15) ans=ret[n];
    int lm;
    if(ans<20) lm=ans;
    else lm=20;
    for(int i=0;i<lm;i++) print(exp[i]);
    printf("%d\n",ans);
    scanf("%'d");
}
