#include<iostream>
using namespace std;
int main()
{
       int i,k,n;
       while (scanf("%d",&n)+1)
       {
              for (k=0;n--;)
              {
                     scanf("%d",&i);
                     k^=i;
              }
              if (k)
                     printf("Yes\n");
              else
                     printf("No\n");
       }
       return 0;
}

