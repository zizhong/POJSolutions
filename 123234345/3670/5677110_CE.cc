#include <iostream>
using namespace std;

int a[30001];
int b[30001];
int c[30001];
int res;
int n;
int maxs1 = -1;
int maxs2 = -1;
int len1;
int len2;

int binary(int n) //不下降的二分函数

{

       int left=0,right=len1,mid=(left+right)/2;

       while(left<=right)

       {

              if(n>=c[mid]) left=mid+1;

              else if(n<c[mid]) right=mid-1;


              mid=(left+right)/2;

       }

       return left;

}

int binary2(int n)//不上升的二分函数

{

       int left=0,right=len2,mid=(left+right)/2;

       while(left<=right)

       {

              if(n>c[mid]) right=mid-1;

              else if(n<=c[mid]) left=mid+1;


              mid=(left+right)/2;

       }

       return left;

}

void LIS()
{
    int num ;
    int loc;
    for(int i = 1; i <n ;i++)
    {
      loc = binary(a[i]);
      c[loc] = a[i];
      if(loc>len1)
      len1 = loc;
    }
        
}

void LDS()
{
    int num ;
    int loc;
    for(int i = 1; i <n ;i++)
    {
      loc = binary2(a[i]);
      c[loc] = a[i];
      if(loc>len2)
      len2 = loc; 
    }
}

int main()
{
    cin>>n;
    for(int i = 0 ; i < n ;i++)
    scanf("%d",&a[i]);
    b[0] =1;
    c[0] = -1;
    c[1] = a[0];
    len1 = 1;
    LIS();
    //cout<<len1;
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    c[0] = 999999;
    c[1] = a[0];
    b[0] = 1;
    len2 = 1;
    LDS();
    //cout<<len2<<endl;
    cout<<n - (len1>len2?len1:len2)<<endl;
    //system("pause");
    return 0;
}
