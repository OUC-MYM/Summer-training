import java.util.*;
import java.math.BigInteger;
public class Main{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		
		BigInteger L=new BigInteger("2");
		BigInteger ans[]=new BigInteger[1010];
		ans[1]=new BigInteger("0");
		ans[2]=new BigInteger("1");
		ans[3]=new BigInteger("1");
		for(int i=4;i<1010;i++)
			ans[i]=ans[i-2].add(L.pow(i-3));
		int N;
		while(cin.hasNext())  
		{
			N=cin.nextInt();
			System.out.println(ans[N].toString());
		}
	}
}