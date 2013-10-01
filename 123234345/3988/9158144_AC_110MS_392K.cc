#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Cour
{
    int a,b;
}cour[312];
bool cmp(const Cour& c1,const Cour &c2)
{
     return c1.b-c2.b?c1.b<c2.b:c1.a<c2.a;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++) scanf("%d%d",&cour[i].a,&cour[i].b);
         sort(cour,cour+n,cmp);
         int ans=0;
         for(int st=0;st<5;st++)
         {
              int tmp=0,p=0;
              int v[312]={0};
              for(int i=0;i+st<1000;i+=5)
              {
                   int j=0;
                   double tm=i+st+0.5;
                   for(;j<n;j++)
                   if(!v[j] && cour[j].a<tm && tm<cour[j].b)
                   {
                         v[j]=1;
                         tmp++;
                         break;
                   }
              }
              if(tmp>ans) ans=tmp;
         }
         printf("%d\n",ans);
    }
}
