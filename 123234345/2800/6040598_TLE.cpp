#include <iostream>
using namespace std;

int k;
__int64 mod_sum(int n)
{
	int d = k/n;
	int t1 = n;
	int t2 = k/(d + 1);
	int s, e;
	__int64 sum = 0;
	while(k/d - k*(d + 1) > 10 )
	{
		s = k%t1;
		e = k%(t2 + 1);
		sum +=  (__int64)(s + e)*(t1 - t2)/2;
		d ++;
                  t1 = t2;
		t2 = k/(d + 1);
	}
	int i;
	for(i = 2; i <= t1; i ++)
		sum += k%i;
	return sum;
}
int  main()
{
   int n;
   scanf("%d %d", &n, &k);
   __int64 sum = 0;
   if(n == 1)
	   sum = 0;
   else if(k == 1)
	   sum = n - 1;
   else
   { 
	   if(n <= k)
		   sum = mod_sum(n);
	   else
	   {
		   sum = mod_sum(k);
		   sum += (__int64)(k)*(n - k);
	   }
   }
   printf("%I64d\n", sum);
   return 0;   
}

