/**
 * 二维ACM计算几何模板
 * 注意变量类型更改和EPS
 * #include <cmath>
 * #include <cstdio>
 * By OWenT
 */
#include <cstdio>
#include <string.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
const double pi = std::acos(-1.0);
//点
class point
{
public:
	double x, y;
	point(){};
	point(double x, double y):x(x),y(y){};

	static double xmult(const point &ps, const point &pe, const point &po)
	{
		return ((ps.x - po.x) * (pe.y - po.y) - (pe.x - po.x) * (ps.y - po.y));
	}
	point operator +(point &_Off)
	{
	    return point(x+_Off.x, y+_Off.y);
	}
	point operator -(point &_Off)
	{
	    return point(x-_Off.x, y-_Off.y);
	}
	//两点间距离
	double dis(const point &_Off) const
	{
		return std::sqrt((x - _Off.x) * (x - _Off.x) + (y - _Off.y) * (y - _Off.y));
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

//两点表示的向量
class pVector
{
public:
	point s, e;//两点表示，起点[s]，终点[e]
	double a, b, c;//一般式,ax+by+c=0
	double ang;
	pVector(){}
	pVector(const point &s, const point &e):s(s),e(e){ang = atan2(e.y-s.y, e.x-s.x);}

	//向量与点的叉乘,参数：点[_Off]
	//[点相对向量位置判断]
	double operator *(const point &_Off) const
	{
		return (_Off.y - s.y) * (e.x - s.x) - (_Off.x - s.x) * (e.y - s.y);
	}
	//向量与向量的叉乘,参数：向量[_Off]
	double operator *(const pVector &_Off) const
	{
		return (e.x - s.x) * (_Off.e.y - _Off.s.y) - (e.y - s.y) * (_Off.e.x - _Off.s.x);
	}

	//直线平行，参数：直线向量[_Off]
	bool parallel(const pVector &_Off) const
	{
		return std::fabs((*this) * _Off) < eps;
	}
	//两直线交点，参数：目标直线[_Off]
	point crossLPt(pVector _Off)
	{
		//注意先判断平行和重合
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
	const static long maxpn = 100;
	point pt[maxpn];//点（顺时针或逆时针）
	long n;//点的个数

	point& operator[](int _p)
	{
		return pt[_p];
	}
	//求多边形面积，多边形内点必须顺时针或逆时针
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
	//-----------半平面交-------------
	//复杂度:O(nlog2(n))
	//#include <algorithm>
	//半平面计算极角函数[如果考虑效率可以用成员变量记录]
	//半平面交排序函数[优先顺序: 1.极角 2.前面的直线在后面的左边]
	static bool hpc_cmp(const pVector &l, const pVector &r)
	{
		//double lp = hpc_pa(l), rp = hpc_pa(r);
		double lp = l.ang, rp = r.ang;
		if(fabs(lp - rp) > eps)
			return lp < rp;
		return point::xmult(l.s, r.e, r.s) < 0.0;
	}
	//用于计算的双端队列
	pVector dequeue[maxpn];
	//获取半平面交的多边形（多边形的核）
	//参数：向量集合[l]，向量数量[ln];(半平面方向在向量左边）
	//函数运行后如果n[即返回多边形的点数量]为0则不存在半平面交的多边形（不存在区域或区域面积无穷大）
	polygon& halfPanelCross(pVector _Off[], int ln)
	{
		int i, tn;
		n = 0;
		//for(int i=0; i<ln; i++) printf("!!!!!%.4f\n", _Off[i].ang);
		std::sort(_Off, _Off + ln, hpc_cmp);

		//平面在向量左边的筛选
		for(i = tn = 1; i < ln; i ++)
		{
			//if(fabs(hpc_pa(_Off[i]) - hpc_pa(_Off[i - 1])) > eps)
			if(fabs(_Off[i].ang - _Off[i-1].ang) > eps)
				_Off[tn ++] = _Off[i];
		}
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
		//计算交点(注意不同直线形成的交点可能重合)
		if(top <= bot + 1)
			return (*this);
		for(i = bot; i < top; i ++)
			pt[n ++] = dequeue[i].crossLPt(dequeue[i + 1]);
		if(bot < top + 1)
			pt[n ++] = dequeue[bot].crossLPt(dequeue[top]);
		return (*this);
	}
};

pVector pv[30], pu[30];
point p[30];
int f[10][130000], cnt[10]; //length of 1's; num of number

inline int count(int d)
{
    int cnt = 0;
    while(d)
    {
        if(d&1) cnt++;
        d>>=1;
    }
    return cnt;
}

void init()
{
    int end = 1<<20;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<end; i++)
    {
        int rec = count(i);
        if(rec>8) continue;
        //printf("%d %d %d\n", i, rec, len);

        f[rec][cnt[rec]] = i;
        cnt[rec]++;

    }
}

double calc(int num, int n, int k, int h)
{
    int arr[22], pos = 0;

    //printf("%d ", num);
    while(num)
    {
        if(num&1) arr[pos++] = 1;
        else arr[pos++] = 0;
        num>>=1;
    }

    int c = 0;
    for(int i=0; i<n; i++) pv[i] = pu[i];
    //for(int i=0; i<n; i++) printf("&&&&&%.4f\n", pv[i].ang);
    for(int i=0; i<n; i++)
    {
        if(c<pos && arr[c++])
        {
            point py = (pv[i].e-pv[i].s).toLeft().setLength(h);
            pv[i] = pVector(pv[i].s+py, pv[i].e+py);
            num>>=1;
        }
    }
    polygon pp = pp.halfPanelCross(pv, n);
    return pp.area();
}

void func(int n, int k, int h)
{
    double Area, ans=0;
    polygon pp;
    for(int i=0; i<n; i++) pv[i] = pu[i];//printf("&&&&&%.4f\n", pv[i].ang);
    pp = pp.halfPanelCross(pv, n);
    Area = pp.area();
    //printf("Area: %.4f\n", Area);

    // main loop
    for(int i=0; i<cnt[k]; i++)
    {
        int tmp = f[k][i];
        if(tmp>(1<<n)) break;
        double rec = calc(tmp, n, k, h);
        //printf("%.4f\n", rec);
        ans = max(ans, Area-rec);
    }
    printf("%.2f\n", ans);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, k, h;
    init();
    while(scanf("%d %d %d", &n, &k, &h)!=EOF && (n||k||h))
    {

        for(int i=0; i<n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
        for(int i=0; i<n; i++)
        {
            pu[i] = pVector(p[i], p[(i+1)%n]);
            //pu[i].ang = atan2(pu[i].e.y - pu[i].s.y, pu[i].e.x - pu[i].s.x);
            //printf("*****%.4f\n", pu[i].ang);
        }
        func(n, k, h);
    }
    return 0;
}
