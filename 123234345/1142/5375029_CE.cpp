#include<stdio.h>
#include<cmath>
#include<string.h>
bool isPrime(int n)
{
     int m=(int)sqrt(n);
     for(int i=2;i<=m;i++)
        if(n%i==0) return false;
     return true;
}
int digSum(int n)
{
     char s[10]={0};
     sprintf(s,"%d",n);
     int len=strlen(s);
     int sum=0;
     for(int i=0;i<len;i++)
        sum+=s[i]-'0';
     return sum;
}
int cut(int n)
{
	if(isPrime(n))
		{return digSum(n);}
	for(int i = (int) sqrt(1.0*n); i >= 2; i--) 
    {
		if(!(n%i))
			return cut(i) + cut(n / i);
	}
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        ++n;
        while(isPrime(n)||digSum(n)!=cut(n)) ++n;
        printf("%d\n",n);
    }
}
