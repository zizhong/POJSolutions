#include <stdlib.h>
#include <stdio.h>
const int MAXN = 1000000;
struct cow
{
  char breed;
  int pos;
}herd[MAXN];
int n;
int left_most[2*MAXN+1];
int cowcmp(const void *p1, const void *p2)
{
  return(((cow*)p1) -> pos - ((cow*)p2) -> pos);
}

int main()
{
  for(int i = 0; i < n; ++i)
  {
    int b;
    scanf("%d %d", &b, &herd[i].pos);
    herd[i].breed = (b == 1) ? +1 : -1;
  }
  qsort(herd, n, sizeof(cow), cowcmp);
  for(int i = -n; i <= +n; ++i)
    left_most[n+i]=-1;
  int best = 0,sum = 0;
  for(int i=0; i<n; ++i)
  {
    if(left_most[n+sum]==-1)
      left_most[n+sum] = herd[i].pos;
    sum += herd[i].breed;
    if(left_most[n+sum] != -1){
      best >?= herd[i].pos - left_most[n+sum];
    }
  }
  printf("%d\n", best);
}

