#include <iostream>
#include <cmath>
using namespace std;

int p;
unsigned euler(unsigned x)
{
 unsigned i,res=x;
 for(i=2;i<(int)sqrt(x*1.0)+1;i++)
  if(x%i==0)
  {
   res=res/i*(i-1);
   while(x % i==0)
    x/=i;
  }
 if(x>1)
  res=res/x*(x-1);
 return res;
}
int main()
{
 while(scanf("%d",&p)!=EOF)
 {
  printf("%d\n",euler(p-1));
 }
 return 0;
}