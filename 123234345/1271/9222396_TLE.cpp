#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const double eps = 1e-10;
const double pi = std::acos(-1.0);
//0…80Š0
class point
{
public:
	double x, y;
	point(){};
	point(double x, double y):x(x),y(y){};

	static double xmult(const point &ps, const point &pe, const point &po)
	{
		return (ps.x - po.x) * (pe.y - po.y) - (pe.x - po.x) * (ps.y - po.y);
	}
	point operator - (const point &_Off) const
	{
		return point(x - _Off.x, y - _Off.y);
	}	
	bool operator == (const point &_Off) const
	{
		return std::fabs(_Off.x - x) < eps && std::fabs(_Off.y - y) < eps;
	}
	point operator + ( point &_Off) const
	{
		return point(x + _Off.x, y + _Off.y);
	}
	point toLeft()
	{
          return point(-y,x);
    }
    point setLength(double len2)
    {
          double len1=sqrt(x*x+y*y);
          return point(x/len1*len2,y/len1*len2);
    }

};
double dist2(point &p1,point &p2)
{
       return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
class pVector
{
public:
	point s, e;
	double a, b, c,ang;
	pVector(){}
	pVector(const point &s, const point &e):s(s),e(e){ang=atan2(e.y-s.y,e.x-s.x);}
    double operator *(const point &_Off) const
	{
		return (_Off.y - s.y) * (e.x - s.x) - (_Off.x - s.x) * (e.y - s.y);
	}
	
	double operator *(const pVector &_Off) const
	{
		return (e.x - s.x) * (_Off.e.y - _Off.s.y) - (e.y - s.y) * (_Off.e.x - _Off.s.x);
	}
	bool parallel(const pVector &_Off) const
	{
		return std::fabs((*this) * _Off) < eps;
	}
	point crossLPt(pVector _Off)
	{
		point ret = s;
		double t = ((s.x - _Off.s.x) * (_Off.s.y - _Off.e.y) - (s.y - _Off.s.y) * (_Off.s.x - _Off.e.x))
				/ ((s.x - e.x) * (_Off.s.y - _Off.e.y) - (s.y - e.y) * (_Off.s.x - _Off.e.x));
		ret.x += (e.x - s.x) * t;
		ret.y += (e.y - s.y) * t;
		return ret;
	}
	static pVector ppline(const point &_a, const point &_b)
	{
		pVector ret;
		ret.s.x = (_a.x + _b.x) / 2;
		ret.s.y = (_a.y + _b.y) / 2;
		//0ˆ60†3¡ã0Š00‡80†5
		ret.a = _b.x - _a.x;
		ret.b = _b.y - _a.y;
		ret.c = (_a.y - _b.y) * ret.s.y + (_a.x - _b.x) * ret.s.x;
		//0†90†50…80Š00‡80†5
		if(std::fabs(ret.a) > eps)
		{
			ret.e.y = 0.0;
			ret.e.x = - ret.c / ret.a;
			if(ret.e == ret. s)
			{
				ret.e.y = 1e10;
				ret.e.x = - (ret.c - ret.b * ret.e.y) / ret.a;
			}
		}
		else
		{
			ret.e.x = 0.0;
			ret.e.y = - ret.c / ret.b;
			if(ret.e == ret. s)
			{
				ret.e.x = 1e10;
				ret.e.y = - (ret.c - ret.a * ret.e.x) / ret.b;
			}
		}
		if(ret.s.x>ret.e.x) swap(ret.s,ret.e);
		else if(fabs(ret.s.x-ret.e.x)<eps && ret.s.y>ret.e.y) swap(ret.s,ret.e);
		return ret;
	}
};


class polygon
{
public:
	//0…80Š00„5¡§0‡90…60‡8¡À0ˆ90Š50†3¨°0‡20Š30‡8¡À0ˆ90Š50„50„8
	long n;//0…80Š00…80‡20†00‹20‡80‹5
  const static long maxpn = 100;
  point pt[maxpn];
	point& operator[](int _p)
	{
		return pt[_p];
	}
 	double area() const
	{
		double ans = 0.0;
		int i;
		for(i = 0; i < n; i ++)
		{
			int nt = (i + 1) % n;
			ans += pt[i].x * pt[nt].y - pt[nt].x * pt[i].y;
		}
		return std::fabs(ans / 2.0);
	}
    static bool hpc_cmp(const pVector &l, const pVector &r)
	{
		double lp = l.ang, rp = r.ang;
		if(fabs(lp - rp) > eps)
			return lp < rp;
		return point::xmult(l.s, r.e, r.s) < 0.0;
	}
	double area()
	{
		double ans = 0.0;
		int i;
		for(i = 0; i < n; i ++)
		{
			int nt = (i + 1) % n;
			ans += pt[i].x * pt[nt].y - pt[nt].x * pt[i].y;
		}
		return std::fabs(ans / 2.0);
	}
	pVector dequeue[maxpn];
	polygon& halfPanelCross(pVector _Off[], int ln)
	{
		int i, tn;
		n = 0;
		std::sort(_Off, _Off + ln, hpc_cmp);
		//0‡40†50‡10Š30ˆ80‰30ˆ3¨°0†90†7¡Á¨®¡À0‰80…80‡20‡70†00ˆ50„3
		for(i = tn = 1; i < ln; i ++)
			if(fabs(_Off[i].ang - _Off[i - 1].ang) > eps)
				_Off[tn ++] = _Off[i];
		ln = tn;
		int bot = 0, top = 1;
		dequeue[0] = _Off[0];
		dequeue[1] = _Off[1];
		for(i = 2; i < ln; i ++)
		{
			if(dequeue[top].parallel(dequeue[top - 1]) ||
				dequeue[bot].parallel(dequeue[bot + 1]))
				return (*this);
			while(bot < top &&
				point::xmult(dequeue[top].crossLPt(dequeue[top - 1]), _Off[i].e, _Off[i].s) > eps)
				top --;
			while(bot < top &&
				point::xmult(dequeue[bot].crossLPt(dequeue[bot + 1]), _Off[i].e, _Off[i].s) > eps)
				bot ++;
			dequeue[++ top] = _Off[i];
		}

		while(bot < top &&
			point::xmult(dequeue[top].crossLPt(dequeue[top - 1]), dequeue[bot].e, dequeue[bot].s) > eps)
			top --;
		while(bot < top &&
			point::xmult(dequeue[bot].crossLPt(dequeue[bot + 1]), dequeue[top].e, dequeue[top].s) > eps)
			bot ++;
		//0†40‡40‡90Š00†50†30…80Š0(¡Á0„40ˆ60‰90…50†30ˆ10…10‰0¡À0ˆ30‰80ˆ40ˆ20…60‡70…80‡20†50†30…80Š00†70‡70‡20‰50‰00‰10†20ˆ3)
		if(top <= bot + 1)
			return (*this);
		for(i = bot; i < top; i ++)
			pt[n ++] = dequeue[i].crossLPt(dequeue[i + 1]);
		if(bot < top + 1)
			pt[n ++] = dequeue[bot].crossLPt(dequeue[top]);
		return (*this);
	}
};
pVector pv1[24],pv2[24];
point pt[24],poff[24];
int n,k,h;
double sum,ans;
void dfs(int i,int kk,int key)
{
     if(k==kk)
     {
          pVector pv2[24];
          memcpy(pv2,pv1,sizeof(pv1));
          for(int j=0;j<n;j++) if(key&(1<<j))
          {
               pv2[j]=pVector(pv1[j].s+poff[j],pv1[j].e+poff[j]);
          }
          polygon po1=po1.halfPanelCross(pv2,n);
          double tmp=sum-po1.area();
          if(tmp>ans) ans=tmp;
          return ;
     }
     if(i>=n||n-i<k-kk) return ;
     for(int j=i;j<n;j++)
          dfs(j+1,kk+1,key|(1<<j));
}
#include<ctime>
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //int tmd1=clock();
    while(scanf("%d%d%d",&n,&k,&h),n)
    {
         if(k>n) k=n;
         for(int i=0;i<n;i++) scanf("%lf%lf",&pt[i].x,&pt[i].y);
         for(int i=0;i<n;i++) pv1[i]=pVector(pt[i],pt[(i+1)%n]);
         for(int i=0;i<n;i++) poff[i]=(pv1[i].e-pv1[i].s).toLeft().setLength(h);
         ans=0.0;
         polygon po1;
         po1.n=n;
         memcpy(po1.pt,pt,sizeof(pt));
         sum=po1.area();
         dfs(0,0,0);
         printf("%.2f\n",ans);
    }
   // printf("%d ms.\n",clock()-tmd1);
}
