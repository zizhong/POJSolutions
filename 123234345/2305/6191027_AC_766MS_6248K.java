import java.util.*;
import java.math.*;
public class Main
{
	public static void main(String args[])
	{
		int b;
		Scanner cin=new Scanner(System.in);
		BigInteger p,m,ans;
		while(cin.hasNext())
		{
			b=cin.nextInt();
			if(b==0) break;
			p=cin.nextBigInteger(b);
			m=cin.nextBigInteger(b);
			ans=p.mod(m);
			System.out.println(ans.toString(b));
		}
	}
}