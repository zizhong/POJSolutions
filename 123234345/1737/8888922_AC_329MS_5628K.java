import java.math.BigInteger;
import java.util.*;
class Main
{
	static final int N = 51;
	static BigInteger [] f = new BigInteger[N];
	static BigInteger [] g = new BigInteger[N];
	static BigInteger [][]c = new BigInteger[N][N];
	public static void main(String []args)
	{

		for(int i = 0 ;i < N; i++)
		{
			c[i][0] = BigInteger.ONE;
			c[i][i] = BigInteger.ONE;
		}
		for(int i =1 ; i < N ; i ++)
		{
			for(int j = 1; j <= i-1; j ++)
			{
				c[i][j]=c[i-1][j].add( c[i-1][j-1] );
			}
		}
		f[1] = BigInteger.ONE;
		f[2] = BigInteger.ONE;
		BigInteger Two = f[1].add(f[1]);
		int n;
		Scanner cin = new Scanner (System.in);
		n = cin.nextInt();
		while(n != 0)
		{
			for(int i = 3; i <= n; i ++)
			{
				g[i] = BigInteger.ZERO;
				for(int j = 1;j < i; j ++)
				{
					g[i]=g[i].add(c[i-1][j-1].multiply(f[j].multiply (Two.pow((i-j)*(i-j-1)/2) )));
					f[i]=Two.pow(i*(i-1)/2);
					f[i]=f[i].subtract(g[i]);
				}
			}
			System.out.println(f[n]);
			n = cin.nextInt();
		}
	}
}