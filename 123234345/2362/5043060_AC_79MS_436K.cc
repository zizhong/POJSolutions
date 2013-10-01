#include<iostream>
using namespace std;
int n,a[20];
bool used[20];
int start;
int cmp(const void*a1,const void*b1)
{
    return *(int *)a1-*(int *)b1;
}
bool deal(int n,int m,int left,int len)
{
     int i;
    if(m==0&&left==0) return true;
    if(left==0)
    {
        i=0;
        left=len;
    }
    else i=start+1;
    for(;i<n;i++)
    {
       if(used[i]||a[i]>left) continue;
       used[i]=true;
       start=i;
       if(deal(n,m-1,left-a[i],len)) return true;       
       used[i]=false;
       if(left==a[i]||left==len) break;
    }
    return false;
}
main()
{
   int t;
   cin>>t;
   while(t--)
   {
      int i,sum=0;
      cin>>n;
      for(i=0;i<n;i++)
       {  
       cin>>a[i];
       sum+=a[i];
       used[i]=false;
       }
      qsort(a,n,sizeof(int),cmp);
      if(sum%4||a[0]>sum/4)
      {
         cout<<"no\n";
      }
     else if(deal(n,n,0,sum/4))
          cout<<"yes\n";
      else cout<<"no"<<endl;
   }
}
