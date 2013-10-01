#include<stdio.h>
#define pMAX 40000
int LIS(int B[],int d[], int n);
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int p,i,d[pMAX]={0},B[pMAX]={0};
        scanf("%d",&p);
        for(i=1;i<=p;i++)
           scanf("%d",&d[i]);
        int r=LIS(B,d,p);
        printf("%d\n",r);
    }
}
int LIS(int B[],int d[], int n){
    int left, right, mid, len = 1;
    B[1] = d[1]; 
    for(int i = 2; i <= n; ++i){
        left = 1, right = len;
        while(left <= right){
            mid = (left + right) / 2;
            if(B[mid] < d[i]) left = mid + 1; 
            else right = mid - 1;
        }
        B[left] = d[i]; 
        if(left > len) len++; 
    }
    return len;
}
