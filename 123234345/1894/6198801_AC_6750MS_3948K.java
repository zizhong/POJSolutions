import java.util.*;
import java.math.BigInteger;
public class Main
{
	public static void main(String args[])
	{
		Scanner cin=new Scanner(System.in);
		BigInteger B=BigInteger.valueOf(cin.nextInt());
		BigInteger x=new BigInteger(cin.next());
		if(x.compareTo(BigInteger.ZERO)==0) return ;
		int len=0;
		BigInteger y=BigInteger.ONE,sum=BigInteger.ZERO;
		while(true)
		{
			sum=sum.add(y);
			if(x.compareTo(sum)<0) break;
			y=y.multiply(B);
			len++;
		}
		int n=len;
		sum=sum.subtract(y);
		y=y.divide(B);
		sum=sum.subtract(y);
		for(int i=0;i<n;i++)
		{
			BigInteger temp=x.subtract(sum);
			temp=temp.divide(y);
			x=x.subtract(y.multiply(temp));
			y=y.divide(B);
			sum=sum.subtract(y);
			System.out.print(temp);	
		}
		System.out.println("");
	}
}