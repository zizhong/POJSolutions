import java.math.*;
import java.util.*;
public class Main
{
	public static void main(String args[])
	{
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		BigInteger num=new BigInteger("2");
		for(int i=0;i<n;i++)
		{
			System.out.println(num);			BigInteger k=num;
			num=((num.multiply(k)).subtract(k)).add(BigInteger.ONE);
		}
	}
}