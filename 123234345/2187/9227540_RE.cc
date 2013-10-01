#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);
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

	//Ïà¶ÔÔ­µãµÄ²î³Ë½á¹û£¬²ÎÊý£ºµã[_Off]
	//¼´ÓÉÔ­µãºÍÕâÁ½¸öµã×é³ÉµÄÆ½ÐÐËÄ±ßÐÎÃæ»ý
	double operator *(const point &_Off) const
	{
		return x * _Off.y - y * _Off.x;
	}
	//Ïà¶ÔÆ«ÒÆ
	point operator - (const point &_Off) const
	{
		return point(x - _Off.x, y - _Off.y);
	}
	point operator + (const point &_Off) const
	{
		return point(x - _Off.x, y - _Off.y);
	}
	point  toLeft()
	{
          return point(-y,x);
    }
    point setLength(double len2)
    {
          double len1=sqrt(x*x+y*y);
          return point(x/len1*len2,y/len1*len2);
    }
	//µãÎ»ÖÃÏàÍ¬(doubleÀàÐÍ)
	bool operator == (const point &_Off) const
	{
		return fabs(_Off.x - x) < eps && fabs(_Off.y - y) < eps;
	}
	//µãÎ»ÖÃ²»Í¬(doubleÀàÐÍ)
	bool operator != (const point &_Off) const
	{
		return ((*this) == _Off) == false;
	}
	//Á½µã¼ä¾àÀëµÄÆ½·½
	double dis2(const point &_Off) const
	{
		return (x - _Off.x) * (x - _Off.x) + (y - _Off.y) * (y - _Off.y);
	}
	//Á½µã¼ä¾àÀë
	double dis(const point &_Off) const
	{
		return sqrt((x - _Off.x) * (x - _Off.x) + (y - _Off.y) * (y - _Off.y));
	}
};

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
	//´ÓÁ½µã±íÊ¾×ª»»ÎªÒ»°ã±íÊ¾

};

class polygon
{
public:
	const static long maxpn = 100;
	point pt[maxpn];//µã£¨Ë³Ê±Õë»òÄæÊ±Õë£©
	long n;//µãµÄ¸öÊý

	point& operator[](int _p)
	{
		return pt[_p];
	}

	//Çó¶à±ßÐÎÃæ»ý£¬¶à±ßÐÎÄÚµã±ØÐëË³Ê±Õë»òÄæÊ±Õë
	double area() const
	{
		double ans = 0.0;
		int i;
		for(i = 0; i < n; i ++)
		{
			int nt = (i + 1) % n;
			ans += pt[i].x * pt[nt].y - pt[nt].x * pt[i].y;
		}
		return fabs(ans / 2.0);
	}

	//-------------Í¹°ü-------------
	//GrahamÉ¨Ãè·¨£¬¸´ÔÓ¶ÈO(nlg(n)),½á¹ûÎªÄæÊ±Õë
	//#include <algorithm>
	static bool graham_cmp(const point &l, const point &r)//Í¹°üÅÅÐòº¯Êý
	{
		return l.y < r.y || (l.y == r.y && l.x < r.x);
	}
	polygon& graham(point _p[], int _n)
	{
		int i, len;
		sort(_p, _p + _n, polygon::graham_cmp);
		n = 1;
		pt[0] = _p[0], pt[1] = _p[1];
		for(i = 2; i < _n; i ++)
		{
			while(n && point::xmult(_p[i], pt[n], pt[n - 1]) >= 0)
				n --;
			pt[++ n] = _p[i];
		}
		len = n;
		pt[++ n] = _p[_n - 2];
		for(i = _n - 3; i >= 0; i --)
		{
			while(n != len && point::xmult(_p[i], pt[n], pt[n - 1]) >= 0)
				n --;
			pt[++ n] = _p[i];
		}
		return (*this);
	}

	//Í¹°üÐý×ª¿¨¿Ç(×¢Òâµã±ØÐëË³Ê±Õë»òÄæÊ±ÕëÅÅÁÐ)
	//·µ»ØÖµÍ¹°üÖ±¾¶µÄÆ½·½£¨×îÔ¶Á½µã¾àÀëµÄÆ½·½£©
	double rotating_calipers()
	{
		int i = 1;
		double ret = 0.0;
		pt[n] = pt[0];
		for(int j = 0; j < n; j ++)
		{
			while(fabs(point::xmult(pt[j], pt[j + 1], pt[i + 1])) > 
            fabs(point::xmult(pt[j], pt[j + 1], pt[i])) + eps)
				i = (i + 1) % n;
			//pt[i]ºÍpt[j],pt[i + 1]ºÍpt[j + 1]¿ÉÄÜÊÇ¶Ôõàµã
			ret = max(ret, max(pt[i].dis2(pt[j]), pt[i + 1].dis2(pt[j + 1])));
		}
		return ret;
	}
};
int n;
point pt[50010];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
         scanf("%lf%lf",&pt[i].x,&pt[i].y);
    polygon po1=po1.graham(pt,n);
    printf("%d\n",(int)(po1.rotating_calipers()+eps));
}
