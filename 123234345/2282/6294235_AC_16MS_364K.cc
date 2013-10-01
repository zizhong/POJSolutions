#include<stdio.h>
int a[11]; 
void search(int x) 
{ 
    int i,k=1,l; 
    for(i=0;i<=9;i++) a[i]=0;
    while(x>=k) 
    { 
        k*=10; 
        for(i=0;i<=9;i++) 
            a[i]+=(x/k)*(k/10); 
        a[0]-=k/10; 
        l=(x%k)/(k/10); 
        for(i=0;i<l;i++) 
            a[i]+=(k/10); 
        a[l]+=x%(k/10)+1; 
    }
}
int main() 
{ 
    int m,tt,n,i,t[11]; 
    while(scanf("%d%d",&m,&n),n) 
    {
        if(m>n) {tt=n,n=m,m=tt;}
        search(n); 
        for(i=0;i<=9;i++)  t[i]=a[i]; 
        search(m-1); 
        for(i=0;i<=9;i++)  t[i]-=a[i]; 
        for(i=0;i<=9;i++) printf("%d%c",t[i],i==9?'\n':' ');
    } 
} 
