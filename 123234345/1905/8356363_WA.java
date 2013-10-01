import java.util.*;
class Main
{
	static double calAng(double C)
	{
		double l=0.0,r=Math.PI*0.5;
		while(r - l > 1e-10)
		{
			double mid = (r + l) * 0.5;
			if(Math.sin(mid) < mid * C)
				r = mid;
			else l = mid;
		}
		return l;
	}
	public static void main(String []args)
	{
		double x,x1,d,c;
		Scanner cin = new Scanner(System.in);
		while(true)
		{
			x = cin.nextDouble();
			d = cin.nextDouble();
			c = cin.nextDouble();
			if(x < 1e-10) break;
			x1 = ( 1 + d * c ) * x;
			double a = calAng(x/x1);
			double ans = x1 * ( 1 - Math.cos(a)) / a * 0.5;
			System.out.format("%.3f\n",ans);
		}
	}
}