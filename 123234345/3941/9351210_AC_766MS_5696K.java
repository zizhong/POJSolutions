import java.math.*;
import java.util.*;
public class Main
{
	public static void main(String []args)
	{
		int N = 10002;
		int n, m, kk;
		BigInteger f[][] = new BigInteger[2][N];
		Scanner cin = new Scanner (System.in);
		while(cin.hasNext())
		{
			n = cin.nextInt();
			m = cin.nextInt();
			kk = cin.nextInt();
			int x=0, p=1;
			for(int i=0;i<N;i++) f[x][i] = BigInteger.ZERO;
			for(int i=1; i<=m; i++) f[x][i] = BigInteger.ONE;
			for(int i=1; i<n; i++)
			{
				x^=1;
				for(int k=0; k<N; k++) f[x][k] = BigInteger.ZERO;
				for(int j=1; j<=m; j++)
					for(int k=0;k+j<N;k++) 
						f[x][k+j]=f[x][k+j].add(f[x^1][k]);
			}
			//for(int i=1;i<=n*m;i++)
			//	System.out.println(f[x][i]);
			//System.out.println("Ok");
			BigDecimal sum = BigDecimal.valueOf(m).pow(n);
			BigDecimal cnt = BigDecimal.ZERO;
			for(int i = 0; i <= kk + 1; i ++)
				cnt = cnt.add(new BigDecimal( f[x][i]));
			//System.out.println("SDSFSDF");
			BigDecimal ans = BigDecimal.ZERO;
			for(int i = kk + 2; i <= n*m; i++)
				cnt = cnt.add(new BigDecimal(f[x][i].multiply(BigInteger.valueOf(i-kk))));
			ans = cnt.divide(sum, 16, BigDecimal.ROUND_HALF_UP);
			System.out.println(ans);
		}
	}
}