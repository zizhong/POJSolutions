import java.math.*;
import java.io.*;
import java.util.*;
class Main{
	public static void main(String args[]){
		long n;
		boolean sign[] = new boolean[70];
		int sum ;
		Scanner cin = new Scanner(System.in);
		while(true){
		n = cin.nextLong();
		sum  = 0;
		Arrays.fill(sign,false);	
		if(n == 0) break;
		n--;
		if(n == 0) {System.out.println("{ }");continue;}
       int l=0;
		while(n>0){
			if(n%2==1) {sign[l] = true;sum++;} 
			n=n/2;
			l++;
			
		}
		System.out.print("{ ");
		for(int i=0;i<64;i++)
			if(sign[i]) {
				System.out.print(BigInteger.valueOf(3).pow(i));
				sum--;
				if(sum!=0) System.out.print(", ");
			}
		System.out.println(" }");
		}
	}
	
}