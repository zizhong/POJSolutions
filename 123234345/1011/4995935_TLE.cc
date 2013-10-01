#include<iostream>
using namespace std;
int sticks[64],start;
bool used[64];
int cmp(const void* a,const void *b)
{
    return *(int *)a-*(int*)b;
}
bool mydeal(int n,int m,int left,int len)
{
   int i;
   if(m==0&&left==0) return true;
   if(left==0) { left=len; i=0;}
   else i=start+1;
   for(;i<n;i++)
   {
      if(used[i]||left<sticks[i])  continue;
      used[i]=true;
      start=i;
      if(mydeal(n,m-1,left-sticks[i],len)) return true;
      else used[i]=false;
      if(left==sticks[i]||left==len) break;
   }
   return false;
}
int main()
{
    int n;
    int i,sum=0;
    while(cin>>n&&n)
    {
       sum=0;
       for(i=0;i<n;i++)
         {  
         cin>>sticks[i];
         sum+=sticks[i];
         used[i]=false;
         }
       qsort(sticks,n,sizeof(sticks[0]),cmp);
       for(i=sticks[0];i<=sum;i++)
		{
			if(sum%i!=0) continue;
			if(mydeal(n,n,0,i))
			{
				cout<<i<<endl;
				break;
			}
       }
    }
}
