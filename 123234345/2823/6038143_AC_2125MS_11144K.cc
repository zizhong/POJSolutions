#include<stdio.h>
const int N=1000001;
int a[N],deck1[N],deck2[N],head1,tail1,head2,tail2;
int ans1[N],ans2[N],cnt;
int n,m;
void insert(int x)
{
     while(head1<=tail1&&a[x]<a[deck1[tail1]]) tail1--;
     deck1[++tail1]=x;
     while(head2<=tail2&&a[x]>a[deck2[tail2]]) tail2--;
     deck2[++tail2]=x;
}
void put(int x)
{
	if(x< 0){
		putchar('-');
		x = -x;
	}
	if(x == 0){
		putchar('0');
		return;
	}
	char s[20];
	int bas = 0;
	for(;x;x/=10)s[bas++] = x%10+'0';
	for(;bas--;)putchar(s[bas]);
	return;
}
int main()
{
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    head1=tail1=deck1[1]=1;
    head2=tail2=deck2[1]=cnt=1;
    for(i=2;i<=m;i++) insert(i);
    ans1[1]=a[deck1[1]];
    ans2[1]=a[deck2[1]];
    for(;i<=n;i++)
    {
        insert(i);
        if(deck1[head1]==i-m) head1++;
        if(deck2[head2]==i-m) head2++;
        ans1[++cnt]=a[deck1[head1]];
        ans2[cnt]=a[deck2[head2]];
    }
    for(i=1;i<cnt;i++) put(ans1[i]),putchar(' ');
    put(ans1[cnt]),puts("");
    for(i=1;i<cnt;i++) put(ans2[i]),putchar(' ');
    put(ans2[cnt]),puts("");
    //scanf("%d",&n);
}
