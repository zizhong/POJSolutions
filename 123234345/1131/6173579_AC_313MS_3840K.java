import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
	public static void main(String agrs[])
	{
		Scanner cin=new Scanner(System.in);
		BigDecimal num,temp,ans,sum;
		String s,t;
		temp=BigDecimal.valueOf(8.0);
		while(cin.hasNext())
		{
			s=cin.next();
			ans=BigDecimal.ZERO;
			sum=BigDecimal.ONE;
			int len=s.length();
			for(int i=2;i<len;i++)
			{
				sum=sum.multiply(temp);
				int val=s.charAt(i)-'0';
				num=BigDecimal.valueOf(val);
				num=num.divide(sum);
				ans=ans.add(num);
			}
			System.out.println(s+" [8] = "+ans+" [10]");
		}
	}
}