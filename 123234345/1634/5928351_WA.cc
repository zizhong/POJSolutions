#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int N = 30001;
struct Employee
{
       int ID,height,income,boss,sub;
}emp[N];
int cmp(const void *a,const void *b)
{
    Employee *e1=(Employee *)a;
    Employee *e2=(Employee *)b;
    return e1->income - e2->income;
}
Employee *ans[899999];
int main()
{
    int nt;
    scanf("%d",&nt);
    while(nt--)
    {
         int n,q;
         scanf("%d%d",&n,&q);
         for(int i=0;i<n;i++)
             scanf("%d%d%d",&emp[i].ID,&emp[i].income,&emp[i].height),emp[i].sub=0;
         qsort(emp,n,sizeof(emp[0]),cmp);
         for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(emp[j].height>=emp[i].height)
                {
                      emp[i].boss=emp[j].ID;
                      emp[j].sub+=emp[i].sub+1;
                      break;
                }
            }
         for(int i=0;i<n;i++)
             ans[emp[i].ID-100000]=&emp[i];
         for(int i=0;i<q;i++)
         {
             int id;
             scanf("%d",&id);
             ans[id-100000]->boss?printf("%d",ans[id-100000]->boss):printf("0");
             printf(" %d\n",ans[id-100000]->sub);
         }
    }
}
