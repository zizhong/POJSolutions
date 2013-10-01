#include<stdio.h>
bool cal[500001];
int rec[500001];
int find(int m)
{
    if(m==0)  return 0;
    if(rec[m]) return rec[m];    
    if(find(m-1)-m>0&&!cal[find(m-1)-m])
    {
        cal[find(m-1)-m]=true;
        return rec[m]=find(m-1)-m;
    }
    cal[find(m-1)+m]=true;
    return rec[m]=find(m-1)+m;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n!=-1)
       printf("%d\n",find(n));
}
