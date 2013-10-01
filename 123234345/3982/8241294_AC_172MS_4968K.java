import java.math.*;
import java.util.*;
class Main
{
	public static void main(String [] args)
	{
		Scanner cin = new Scanner(System.in);
		BigInteger[] A = new BigInteger[100];
		while(cin.hasNext())
		{
				A[0] = cin.nextBigInteger();
				A[1] = cin.nextBigInteger();
				A[2] = cin.nextBigInteger();
				for(int i=3;i<=99;i++)
				{
					A[i] = A[i-1].add(A[i-2].add(A[i-3]));
				}
				System.out.println(A[99]);
		}
	}
}