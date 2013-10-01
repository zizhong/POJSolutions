import java.io.*;
import java.math.*;
import java.util.*;
public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner (System.in);
		int T = cin.nextInt();
		while(true)
		{
			int n=cin.nextInt(),v=cin.nextInt(),cnt=0;
			BigDecimal num=BigDecimal.ONE;
			for(long i=1;i<=n;i++)
				num=num.multiply(BigDecimal.valueOf(i));
			String s=num.toString();
			int len=s.length();
			for(int i=0;i<len;i++)
				if(s.charAt(i)=='0'+v) cnt++;
			System.out.println(cnt);
			T=T-1;
			if(T==0) break;
		}
	}
}