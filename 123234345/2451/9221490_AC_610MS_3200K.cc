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


class polygon
{
public:
	//µã£¨Ë³Ê±Õë»òÄæÊ±Õë£©
	long n;//µãµÄ¸öÊý
  const static long maxpn = 20010;
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
	polygon& halfPanelCross(pVector _Off[], int ln)
	{
		int i, tn;
		n = 0;
		std::sort(_Off, _Off + ln, hpc_cmp);
		//Æ½ÃæÔÚÏòÁ¿×ó±ßµÄÉ¸Ñ¡
		for(i = tn = 1; i < ln; i ++)
			if(fabs(hpc_pa(_Off[i]) - hpc_pa(_Off[i - 1])) > eps)
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
pVector pv[20010];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
         pv[0]=pVector(point(0,1),point(0,0)); 
         pv[1]=pVector(point(0,0),point(1,0)); 
         pv[2]=pVector(point(10000,0),point(10000,1));
         pv[3]=pVector(point(1,10000),point(0,10000));
         int nn=4;
         double x1,y1,x2,y2;
         for(int i=0;i<n;i++)
         {
               scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
               pv[nn++]=pVector(point(x1,y1),point(x2,y2));
         }
         polygon po1=po1.halfPanelCross(pv,nn);
         printf("%.1f\n",po1.area());
    }
}
