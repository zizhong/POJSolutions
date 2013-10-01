import java.util.*;
import java.math.BigInteger;
class Main
{
	void Pell(int n)
	{
			BigInteger p0 = BigInteger.ZERO;
			BigInteger N  =  BigInteger.valueOf (n);
			BigInteger p1 = BigInteger.ONE;
			BigInteger q0 = BigInteger.ONE;
			BigInteger q1 = BigInteger.ZERO;
			BigInteger p2,q2,a0 = BigInteger.valueOf( (int)Math.sqrt(n)),a1 = a0, a2;
			BigInteger h1 = BigInteger.ONE;
			BigInteger g1 = BigInteger.ZERO;
			while (true)
			{
				g1 = (a1.multiply(h1)).subtract(g1);
				h1 = (N.subtract(g1.multiply(g1))).divide(h1);
				a2 = (g1.add(a0)).divide(h1);
				p2 = a1.multiply(p1).add(p0);
				q2 = a1.multiply(q1).add(q0);
				if ( p2.multiply(p2).subtract(N.multiply(q2.multiply(q2))).equals(BigInteger.ONE))
				{
					System.out.println(p2 + " " + q2);
					return ;
				}
				p0 = p1;
				p1 = p2;
				q0 = q1;
				q1 = q2;
				a1 = a2;
			}
	}
	public static void main(String []args)
	{
		Main main1 = new Main();
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext())
		{
			int n = cin.nextInt();
			if(n % ((int)Math.sqrt(n)) == 0)
			{
				System.out.println("No solution!");
				continue;
			}
			main1.Pell(n);
		}
	}
}