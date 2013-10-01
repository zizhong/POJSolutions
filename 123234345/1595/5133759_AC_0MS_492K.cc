#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
#define MAXN  1015
#define pMaxCount 200
int  pCount;           
bool flags[MAXN+1];     
int  plist[pMaxCount];  
int main()
{
    int i, j, idx, max = (int)sqrt(MAXN*1.0);
    memset(flags, true, sizeof(flags));
    for(i = 2 ; i <= max; ++i)
        if(flags[i])  
		for(j = i*i; j <= MAXN; j += i)
             flags[j] = false;
    for(idx = 0, i = 1; i <= MAXN; ++i)  
        if(flags[i])
           {plist[idx] = i;  ++idx;}
   pCount = idx;
   int n,c;
   while(cin>>n>>c)
   {
      int length,mi,mj,k;
      for(i=0;plist[i]<=n;i++) ;
      length=i;
      memset(flags,false,sizeof(flags));
      if(length%2) mi=mj=length/2;
      else mi=length/2-1,mj=length/2;
      for(i=mi,j=mj,k=0;k<c&&j<length;k++,i--,j++)
          flags[i]=flags[j]=true;
      cout<<n<<' '<<c<<':';
      for(k=i;k<=j;k++)
         if(flags[k]) cout<<' '<<plist[k];
      cout<<endl<<endl;         
   }
}
