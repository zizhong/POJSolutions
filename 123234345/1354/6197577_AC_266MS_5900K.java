import java.util.*;
import java.math.BigInteger;
public class Main
{
	public static void main(String args[])
	{
		Scanner cin=new Scanner(System.in);
		while(true)
		{
			int n=cin.nextInt();
			if(n==-1) break;
			BigInteger num=BigInteger.ONE;
			for(int i=2;i<n;i++)
				num=num.multiply(BigInteger.valueOf(i));
			num=num.multiply(BigInteger.valueOf(2));
			System.out.println("N="+n+":\n"+num);
		}
	}
}