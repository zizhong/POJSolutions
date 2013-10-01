#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps = 1e-8;
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
};

class polygon
{
public:
	const static long maxpn = 110;
	point pt[maxpn];//µã£¨Ë³Ê±Õë»òÄæÊ±Õë£©
	long n;//µãµÄ¸öÊý

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
point pt[110],poff[110];
int n;
pVector pv[110];
int main()
{
    while(scanf("%d",&n)==1)
    {
         double r;
         scanf("%lf",&r);
         for(int i=0;i<n;i++)
              scanf("%lf%lf",&pt[i].x,&pt[i].y);
         for(int i=n-1;i>=0;i--)
         {
              poff[i]=(pt[i]-pt[(i+1)%n]).toLeft().setLength(r);
              pv[i]=pVector(pt[(i+1)%n]+poff[i],pt[i]+poff[i]);
         }
         polygon poly1=poly1.halfPanelCross(pv,n);
         point rp1,rp2;
         double ans=-1e10;
         for(int i=0;i<poly1.n;i++)
            for(int j=i+1;j<poly1.n;j++)
            {
                  if(ans<dist2(poly1.pt[i],poly1.pt[j]))
                  {
                        ans=dist2(poly1.pt[i],poly1.pt[j]);
                        rp1=poly1.pt[i];
                        rp2=poly1.pt[j];
                  }
            }
         //printf("%d\n",poly1.n);
         //for(int i=0;i<poly1.n;i++) printf("<%.3f,%.3f>\n",poly1[i].x,poly1[i].y);
         printf("%.4f %.4f %.4f %.4f\n",rp1.x,rp1.y,rp2.x,rp2.y);
    }
} 
