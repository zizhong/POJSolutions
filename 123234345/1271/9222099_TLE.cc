#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const double eps = 1e-10;
const double pi = std::acos(-1.0);
//µã
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
//Á½µã±íÊ¾µÄÏòÁ¿
class pVector
{
public:
	point s, e;//Á½µã±íÊ¾£¬Æðµã[s]£¬ÖÕµã[e]
	double a, b, c;//Ò»°ãÊ½,ax+by+c=0
	pVector(){}
	pVector(const point &s, const point &e):s(s),e(e){}

	//ÏòÁ¿ÓëµãµÄ²æ³Ë,²ÎÊý£ºµã[_Off]
	//[µãÏà¶ÔÏòÁ¿Î»ÖÃÅÐ¶Ï]
	double operator *(const point &_Off) const
	{
		return (_Off.y - s.y) * (e.x - s.x) - (_Off.x - s.x) * (e.y - s.y);
	}
	//ÏòÁ¿ÓëÏòÁ¿µÄ²æ³Ë,²ÎÊý£ºÏòÁ¿[_Off]
	double operator *(const pVector &_Off) const
	{
		return (e.x - s.x) * (_Off.e.y - _Off.s.y) - (e.y - s.y) * (_Off.e.x - _Off.s.x);
	}

	//Ö±ÏßÆ½ÐÐ£¬²ÎÊý£ºÖ±ÏßÏòÁ¿[_Off]
	bool parallel(const pVector &_Off) const
	{
		return std::fabs((*this) * _Off) < eps;
	}
	//Á½Ö±Ïß½»µã£¬²ÎÊý£ºÄ¿±êÖ±Ïß[_Off]
	point crossLPt(pVector _Off)
	{
		//×¢ÒâÏÈÅÐ¶ÏÆ½ÐÐºÍÖØºÏ
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
		//Ò»°ãÊ½
		ret.a = _b.x - _a.x;
		ret.b = _b.y - _a.y;
		ret.c = (_a.y - _b.y) * ret.s.y + (_a.x - _b.x) * ret.s.x;
		//Á½µãÊ½
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

pVector pv1[24],pv2[24];
class polygon
{
public:
	//µã£¨Ë³Ê±Õë»òÄæÊ±Õë£©
	long n;//µãµÄ¸öÊý
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
	//-----------°ëÆ½Ãæ½»-------------
	//¸´ÔÓ¶È:O(nlog2(n))
	//#include <algorithm>
	//°ëÆ½Ãæ¼ÆËã¼«½Çº¯Êý[Èç¹û¿¼ÂÇÐ§ÂÊ¿ÉÒÔÓÃ³ÉÔ±±äÁ¿¼ÇÂ¼]
	static double hpc_pa(const pVector &_Off)
	{
		return atan2(_Off.e.y - _Off.s.y, _Off.e.x - _Off.s.x);
	}
	//°ëÆ½Ãæ½»ÅÅÐòº¯Êý[ÓÅÏÈË³Ðò: 1.¼«½Ç 2.Ç°ÃæµÄÖ±ÏßÔÚºóÃæµÄ×ó±ß]
	static bool hpc_cmp(const pVector &l, const pVector &r)
	{
		double lp = hpc_pa(l), rp = hpc_pa(r);
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
	//ÓÃÓÚ¼ÆËãµÄË«¶Ë¶ÓÁÐ
	pVector dequeue[maxpn];
	//»ñÈ¡°ëÆ½Ãæ½»µÄ¶à±ßÐÎ£¨¶à±ßÐÎµÄºË£©
	//²ÎÊý£ºÏòÁ¿¼¯ºÏ[l]£¬ÏòÁ¿ÊýÁ¿[ln];(°ëÆ½Ãæ·½ÏòÔÚÏòÁ¿×ó±ß£©
	//º¯ÊýÔËÐÐºóÈç¹ûn[¼´·µ»Ø¶à±ßÐÎµÄµãÊýÁ¿]Îª0Ôò²»´æÔÚ°ëÆ½Ãæ½»µÄ¶à±ßÐÎ£¨²»´æÔÚÇøÓò»òÇøÓòÃæ»ýÎÞÇî´ó£©
	polygon& halfPanelCross(int ln)
	{
		int i, tn;
		n = 0;
		std::sort(pv2, pv2 + ln, hpc_cmp);
		//Æ½ÃæÔÚÏòÁ¿×ó±ßµÄÉ¸Ñ¡
		for(i = tn = 1; i < ln; i ++)
			if(fabs(hpc_pa(pv2[i]) - hpc_pa(pv2[i - 1])) > eps)
				pv2[tn ++] = pv2[i];
		ln = tn;
		int bot = 0, top = 1;
		dequeue[0] = pv2[0];
		dequeue[1] = pv2[1];
		for(i = 2; i < ln; i ++)
		{
			if(dequeue[top].parallel(dequeue[top - 1]) ||
				dequeue[bot].parallel(dequeue[bot + 1]))
				return (*this);
			while(bot < top &&
				point::xmult(dequeue[top].crossLPt(dequeue[top - 1]), pv2[i].e, pv2[i].s) > eps)
				top --;
			while(bot < top &&
				point::xmult(dequeue[bot].crossLPt(dequeue[bot + 1]), pv2[i].e, pv2[i].s) > eps)
				bot ++;
			dequeue[++ top] = pv2[i];
		}

		while(bot < top &&
			point::xmult(dequeue[top].crossLPt(dequeue[top - 1]), dequeue[bot].e, dequeue[bot].s) > eps)
			top --;
		while(bot < top &&
			point::xmult(dequeue[bot].crossLPt(dequeue[bot + 1]), dequeue[top].e, dequeue[top].s) > eps)
			bot ++;
		//¼ÆËã½»µã(×¢Òâ²»Í¬Ö±ÏßÐÎ³ÉµÄ½»µã¿ÉÄÜÖØºÏ)
		if(top <= bot + 1)
			return (*this);
		for(i = bot; i < top; i ++)
			pt[n ++] = dequeue[i].crossLPt(dequeue[i + 1]);
		if(bot < top + 1)
			pt[n ++] = dequeue[bot].crossLPt(dequeue[top]);
		return (*this);
	}
};

point pt[24],poff[24];
int n,k,h;
double sum,ans;
const int N=125980;
int f[9][N],cnt[9];
void pref()
{
     int x,t,K=1<<20;
     for(int i=0;i<K;i++)
     {
          x=i,t=0;
          while(x) 
          {
              if(x&1) t++;
              x>>=1;
          }
          if(t<9) f[t][cnt[t]++]=i;
     }
}
int main()
{
    pref();
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d%d",&n,&k,&h),n)
    {
         if(k>n) k=n;
         for(int i=0;i<n;i++) scanf("%lf%lf",&pt[i].x,&pt[i].y);
         for(int i=0;i<n;i++) pv1[i]=pVector(pt[i],pt[(i+1)%n]);
         for(int i=0;i<n;i++) poff[i]=(pv1[i].e-pv1[i].s).toLeft().setLength(h);
         ans=0.0;
         if(h==0||k==0){puts("0.00");continue;}
         polygon po1;
         po1.n=n;
         memcpy(po1.pt,pt,sizeof(pt));
         sum=po1.area();
         for(int i=0;i<cnt[k];i++)
         {
              int key=f[k][i];
              //printf("%d\n",key);
              if(key>=(1<<n)) break;
              pVector pv2[24];
              for(int j=0;j<n;j++) if(key&(1<<j))
              {
                  pv2[j]=pVector(pv1[j].s+poff[j],pv1[j].e+poff[j]);
              }else pv2[j]=pv1[j];
              polygon po2=po2.halfPanelCross(n);
              double tmp=sum-po2.area();
              if(tmp>ans) ans=tmp;
         }
         printf("%.2f\n",ans);
    }
}
