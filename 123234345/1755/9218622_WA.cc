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
struct Peo
{
       double v,u,w;
       void init()
       {
           scanf("%lf%lf%lf",&u,&v,&w);
       }
}peo[110];
pVector pv[110];
int sgn(double x){return (x>eps) - (x<-eps);}
int n;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)==1)
    {
         for(int i=0;i<n;i++)
             peo[i].init();
         
         for(int k=0;k<n;k++)
         {
             //x>0,y>0,1-x-y>0              
              pv[0]=pVector(point(0,1),point(0,-1));
              pv[1]=pVector(point(0,0),point(1, 0));
              pv[2]=pVector(point(1,0),point(0, 1));
              int nn=3,flag=0; 
              for(int i=0;i<n;i++) if(i!=k)
              {
                   double c=1/peo[k].w - 1/peo[i].w,
                          a=1/peo[k].u - 1/peo[i].u - 1/peo[k].w + 1/peo[i].w,
                          b=1/peo[k].v - 1/peo[i].v - 1/peo[k].w + 1/peo[i].w;
                   //ax+by+c>0 ==> <s,e> leftside half plane
                   point p1,p2;
                   if(sgn(a)==0&&sgn(b)==0)
                   {
                        if(sgn(c)>=0)
                        {
                              puts("No");
                              flag=1;
                              break;
                        }
                   }else if(sgn(b)==0)
                   {
                         p1=point(-c/a,0),p2=point(-c/a,1);
                         if(sgn(a)>0) pv[nn++]=pVector(p1,p2);
                         else pv[nn++]=pVector(p2,p1);
                   }else
                   {
                         p1=point(0,-c/b),p2=point(1,(-c-1*a)/b);
                         if(sgn(b)>0) pv[nn++]=pVector(p2,p1);
                         else pv[nn++]=pVector(p1,p2);
                   }                   
              }
              if(!flag)
              {
                    //for(int i=0;i<nn;i++) printf("<%6.2f,%6.2f>,<%6.2f,%6.2f>\n",pv[i].s.x,pv[i].s.y,pv[i].e.x,pv[i].e.y);   
                    polygon po1=po1.halfPanelCross(pv,nn);
                    //for(int i=0;i<po1.n;i++) printf("<%6.2f,%6.2f>\n",po1.pt[i].x,po1.pt[i].y);
                    puts(po1.area()>eps?"Yes":"No");
                    //printf("%d\n",po1.n);                    
              }
         }
    }
} 
