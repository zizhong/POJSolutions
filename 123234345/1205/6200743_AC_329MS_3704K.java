import java.math.*;
import java.util.*;
public class Main
{
	public static void main(String args[])
	{
		BigInteger []a = new BigInteger[101];
		a[1]=BigInteger.ONE;
		for(int i=2;i<=100;i++)
		{
			BigInteger temp=BigInteger.ONE;
			for(int k=1;k<i-1;k++)
				temp=temp.add(a[k]);
			BigInteger te=a[i-1];
			te=te.add(a[i-1]);
			temp=temp.add(te);
			a[i]=temp;
		}
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			int x=cin.nextInt();
			System.out.println(a[x]);
		}
	}
}