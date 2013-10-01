#include<stdio.h>
int min(int a,int b){return a>b?b:a;}
char dict[610][32];
int W;
char mesg[310];
int L;
int DP[310];
int solve()
{
  for(int i=0;i<=L;i++)DP[i]=i;
  for(int i=1;i<=L;i++){
    int j=i-1;
    for(int k=0;k<W;k++){
      int lk=0,lj=j;
      int cnt=0;
      while(dict[k][lk]!=0 && mesg[lj]!=0){
	if(dict[k][lk]==mesg[lj]){
	  lk++;
	  lj++;
	}else{
	  cnt++;
	  lj++;
	}
      }
      if(dict[k][lk]==0){
	if((DP[j]+cnt)<DP[lj]){
	  DP[lj]=DP[j]+cnt;
	  for(int n=lj+1;n<=L;n++)
	    DP[n]=min(DP[n],DP[lj]+n-lj);
	}
      }
    }
  }
  return DP[L];
}
int main()
{
  scanf("%d %d",&W,&L);
  scanf("%s",mesg);
  for(int i=0;i<W;i++){
    scanf("%s",dict[i]);
  }
  printf("%d\n",solve());
}
