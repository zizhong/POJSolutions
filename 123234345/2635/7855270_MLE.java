import java.math.BigInteger;
import java.util.*;
class Main
{
	public static void main(String []args)
	{
		final int N=1000001;
		BigInteger p[]=new BigInteger[N];
		int plen=0;
		int v[]=new int[N];
		for(int i=2;i<N;i++)
			if(v[i]==0)
			{
				p[plen]=new BigInteger(new Integer(i).toString());
				plen++;
				for(int j=i+i;j<N;j+=i)
					v[i]=1;
			}
		Scanner cin=new Scanner(System.in);
		while(true)
		{
			boolean flag=false;
			int lm;
			BigInteger key=cin.nextBigInteger();
			lm=cin.nextInt();
			if(lm==0) break;
			for(int i=0;i<plen;i++)
			{
				if(p[i].intValue()>=lm) break;
				if(key.remainder(p[i]).equals(BigInteger.ZERO)==true)
				{
					flag=true;
					System.out.println("BAD "+p[i]);
					break;
				}
			}
			if(!flag)
			{
				System.out.println("GOOD");
			}
		}
	}
}