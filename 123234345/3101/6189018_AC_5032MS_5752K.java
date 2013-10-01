import java.util.*;
import java.math.*;
public class Main
{
	private static final int N=10000;
	public static void main(String args[])
	{	int []p=new int[N];
		boolean []u=new boolean[2*N+1];
		int cp=0;
		for(int i=2;i<=2*N;i++)
			if(!u[i])
			{
				p[cp++]=i;
				for(int j=2*i;j<=2*N;j+=i)
					u[j]=true;
			}
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		int []t=new int [n];
		for(int i=0;i<n;i++)
			t[i]=cin.nextInt();
		int []ans=new int [cp];
		boolean flag=false;
		for(int i=1;i<n;i++)
			if(t[i]!=t[0])
			{
				int v1=2*Math.abs(t[i]-t[0]),
					v2=t[0],v3=t[i];
				for(int j=0;j<cp;j++)
				{
					int f=0;
					while(v1%p[j]==0)
					{v1/=p[j];f--;}
					while(v2%p[j]==0)
					{v2/=p[j];f++;}
					while(v3%p[j]==0)
					{v3/=p[j];f++;}
					if(flag) ans[j]=Math.max(ans[j],f);
					else ans[j]=f;
				}
				flag=true;
			}
		BigInteger nom=BigInteger.ONE,
				   den=BigInteger.ONE;
		for(int i=0;i<cp;i++)
		{
			for(int j=0;j<ans[i];j++)
			    nom=nom.multiply(BigInteger.valueOf(p[i]));
			for(int j=0;j>ans[i];j--)
				den=den.multiply(BigInteger.valueOf(p[i]));
		}
		System.out.println(nom+" "+den);
	}
}