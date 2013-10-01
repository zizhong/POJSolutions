import java.util.*;
import java.math.*;
public class Main
{
	public static void main(String args[])
	{
		Scanner cin=new Scanner (System.in);
		while(cin.hasNext())
		{
			int d=cin.nextInt();
			if(d==-1) break;
			d=d+2;
			int n=2*d-4,m=d-2;
			BigDecimal a=BigDecimal.ONE,
					   b=BigDecimal.ONE;
			for(int i=1;i<=n;i++)
			{
				a=a.multiply(BigDecimal.valueOf(i));
				if(i<=m) b=b.multiply(BigDecimal.valueOf(i));
				else b=b.multiply(BigDecimal.valueOf(i-m));
			}
			a=a.divide(b);
			a=a.divide(BigDecimal.valueOf(d-1));
			System.out.println(a);
		}
	}
}