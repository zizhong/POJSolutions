#include<iostream>
#include<algorithm>
using namespace std;
const int M=10003;
struct point
{
 int x;
 int y;
}a[M];
bool less(const struct point a, const struct point b)
{
 if(a.x==b.x)
  return a.y<b.y;
 else return a.x<b.x;
}
int main()
{
 int cases,num,tmpx,tmpy;
 int i,j,mark;
 while(scanf("%d",&cases)!=EOF)
  while(cases--)
  {
   mark=1;
   scanf("%d",&num);
   for(i=0;i<num;i++)
    scanf("%d%d",&a[i].x,&a[i].y); 
   sort(a,a+num,less);
   tmpx=a[0].x+a[num-1].x;
   tmpy=a[0].y+a[num-1].y;
   for(i=1,j=num-2;i<=j;i++,j--) 
    if((tmpx!=a[i].x+a[j].x)||(tmpy!=a[i].y+a[j].y))
    {
     mark=0;
     break;
    }
    puts(mark?"yes":"no");
  }
}