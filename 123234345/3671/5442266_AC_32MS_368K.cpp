#include<stdio.h>
#include<string.h>
#define MAX 100000000
int n,a[30010];
int b[30010];
int main()
{
	memset(b,0,30010*sizeof(int));
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1)
			b[i]=b[i-1]+1;
		else b[i]=b[i-1];
	}
	if(b[n]==n||b[n]==0){
		printf("%d",0);return 0;}
	int min=MAX;
	for(i=1;i<=n;i++){
		int sum=(i-b[i])+b[n]-b[i];
		if(sum<min)
			min=sum;
	}
	printf("%d\n",min);
	return 0;
}
