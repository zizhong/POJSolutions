#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL(a)				a<<1	
#define RR(a)              a<<1|1
#define FF(i,a)				for( int i = 0 ; i < a ; i ++ )
struct Seg_Tree{
	int left,right;
	int lbd,rbd;//?
	int cnt;//?
	int Len;//?
	int num_Seg;//?
	int mid() {
		return (left + right) >> 1;
	}
}tt[66666];
struct Seg{
	int left;
	int right;
	int high;
	int side;
}ss[10001];
bool cmp(const Seg &a,const Seg &b) {
	return a.high < b.high;
}
void build(int l,int r,int idx) {
	tt[idx].left = l;
	tt[idx].right = r;
	tt[idx].cnt = tt[idx].Len = tt[idx].num_Seg = 0;
	if(l == r)	return ;
	int mid = tt[idx].mid();
	build(l,mid,LL(idx));
	build(mid+1,r,RR(idx));
}
void update(int idx) 
{
	if(tt[idx].cnt) 
    {
		tt[idx].lbd = tt[idx].rbd = 1;
		tt[idx].Len = tt[idx].right - tt[idx].left + 1;
		tt[idx].num_Seg = 2;
	} 
    else if(tt[idx].left == tt[idx].right) 
    {
		tt[idx].lbd = tt[idx].rbd = 0;
		tt[idx].Len = 0;
		tt[idx].num_Seg = 0;
	} 
    else 
    {
		int l = LL(idx);
		int r = RR(idx);
		tt[idx].lbd = tt[l].lbd;
		tt[idx].rbd = tt[r].rbd;
		tt[idx].Len = tt[l].Len + tt[r].Len;
		tt[idx].num_Seg = tt[l].num_Seg + tt[r].num_Seg - 2 * (tt[l].rbd & tt[r].lbd);
	}
}
void update(int l,int r,int st,int idx) {
	if(tt[idx].left >= l && tt[idx].right <= r) {
		tt[idx].cnt += st;
		update(idx);
		return ;
	}
	int mid = tt[idx].mid();
	if(l <= mid) update(l,r,st,LL(idx));
	if(mid < r)	update(l,r,st,RR(idx));
	update(idx);
}
int main() {
	int n;
	while(scanf("%d",&n) == 1) 
    {
		if(n == 0) 
        {
			puts("0");
			continue;
		}
		int lup = 10000;
		int rup = -10000;
		int m = 0;
		FF(i,n) 
        {
			scanf("%d%d%d%d",&ss[m].left,&ss[m].high,&ss[m].right,&ss[m+1].high);
			ss[m+1].left = ss[m].left;
			ss[m+1].right = ss[m].right;
			ss[m].side = 1;
			ss[m+1].side = -1;
			lup = min(lup,ss[m].left);
			rup = max(rup,ss[m].right);
			m += 2;
		}
		sort(ss,ss+m,cmp);
		build(lup,rup-1,1);
		int ans = 0;
		int buf = 0;//?
		ss[m] = ss[m-1];//
		FF(i,m) {
			if(ss[i].left != ss[i].right) {
				update(ss[i].left,ss[i].right-1,ss[i].side,1);
			}
			ans += tt[1].num_Seg * (ss[i+1].high - ss[i].high);
			ans += abs(tt[1].Len - buf);
			//printf("%d %d %d\n",tt[1].num_Seg,tt[1].num_Seg * (ss[i+1].high - ss[i].high),abs(tt[1].Len - buf));
			buf = tt[1].Len;
		}
		printf("%d\n",ans);
	}
	return 0;
}


