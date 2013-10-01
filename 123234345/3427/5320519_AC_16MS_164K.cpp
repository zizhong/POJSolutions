#include<iostream>
using namespace std;

int data[30000];

int main()
{
    int n,l;
    int k;
    scanf("%d%d",&n,&l);

    int i,j;
    for(i = 0;i<l;i++)
          data[i] = 0;
    
    for(i = 0;i< n;i++)
    {
          scanf("%d",&j);
          j %= l;
          data[j]++;
    }
    int t = l;
    int out,sum,min=2147483641;
    while(t>0)
    {
           sum = 0;
           for(i = 0;i<l;i++)
           {
                 sum += data[i]*i;
           }
           int d = data[l-1];
           for(i = l-1;i>0;i--)
           {
                 data[i] = data[i-1];
           }
           data[0] = d;
           if(sum < min)
           {
                  min = sum;
                  out = l-t;
           }
           t--;           
    }
    printf("%d\n",out);
}

