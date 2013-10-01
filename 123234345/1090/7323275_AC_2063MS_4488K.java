import java.util.*;
import java.math.BigInteger;
class Main
{

	static BigInteger f[]=new BigInteger[1001];
	static BigInteger g[]=new BigInteger[1001];
	static BigInteger p2[]=new BigInteger[1001];
	static int []a= new int[1001];
	static int []v1=new int[1001];
	static int []v2=new int[1001];
	static BigInteger calg(int x)
	{
		if(x==0) return BigInteger.ZERO;
		if(v2[x]==1) return g[x];
		v2[x]=1;
		if(a[x]==1) g[x]=calf(x-1);
		else g[x]=p2[x-1].add(calg(x-1));
		return g[x];
	}
	static BigInteger calf(int x)
	{
		if(x==0) return BigInteger.ZERO;
		if(v1[x]==1) return f[x];
		v1[x]=1;
		if(a[x]==0) f[x]=calf(x-1);
		else f[x]=p2[x-1].add(calg(x-1));
		return f[x];
	}
	public static void main(String []args)
	{
		int n;		
		Scanner cin= new Scanner(System.in);
		n=cin.nextInt();
		for(int i=1;i<=n;i++)
			a[i]=cin.nextInt();
		p2[0]=BigInteger.ONE;
		for(int i=1;i<=n;i++)
			p2[i]=p2[i-1].shiftLeft(1);
		System.out.println(calf(n));
	}
}