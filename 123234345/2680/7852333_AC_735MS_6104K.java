import java.math.BigInteger;
import java.util.*;
class Main
{
	public static void main(String []args)
	{
		BigInteger array[] = new BigInteger[1001];
		int n;
		Scanner cin = new Scanner(System.in);
		array[1]=BigInteger.ZERO;
		array[2]=BigInteger.ONE;
		for(int i=3;i<=1000;i++)
		{
			array[i]=array[i-2].add(BigInteger.ONE.shiftLeft(i-3));
		}
		while(cin.hasNext())
		{
			n=cin.nextInt();
			System.out.println(array[n]);
		}
	}
}