#include<stdio.h> 
typedef unsigned int UINT;
int n;

UINT ip[1000][4];
UINT ipCover[1000];

int main()
{
 //freopen("1.txt", "r", stdin);
 scanf("%d", &n);
 for (int i = 0; i < n; ++i)
 {
  scanf("%u.%u.%u.%u", &ip[i][0], &ip[i][1], &ip[i][2], &ip[i][3]);
  ipCover[i] = (ip[i][0]<<24) + (ip[i][1]<<16) + (ip[i][2]<<8) + ip[i][3];
 }

 UINT sample = ipCover[0];
 
 int bit = 0;
 for (bit = 31; bit >= 0; --bit)
 {
  UINT sum = 0;
  
  for (int i = 0; i < n; ++i)
  {
   UINT temp = ipCover[i]>>bit;
   sum += ((ipCover[i]>>bit)&1);
  }

  if (sum != 0 && sum != n)
   break;
 }

 bit++;

 UINT mark = 0xFFFFFFFF;
 mark = mark << bit;

 if (bit == 32)
 {
  mark = 0;
 }

 int Min = mark & sample;

 printf("%u.%u.%u.%u\n", (Min>>24)&0xFF, (Min>>16)&0xFF, (Min>>8)&0xFF, (Min>>0)&0xFF);
 printf("%u.%u.%u.%u\n", (mark>>24)&0xFF, (mark>>16)&0xFF, (mark>>8)&0xFF, (mark>>0)&0xFF);
 return 0;
}