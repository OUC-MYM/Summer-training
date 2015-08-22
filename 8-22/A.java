import java.util.*;
import java.math.BigInteger;
public class Main{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		BigInteger a, b, ans;
		int k;
		String aa,bb;
		k= cin.nextInt();
		for(int i=1;i<=k;i++)
		{
			aa=cin.next();
			bb=cin.next();
			a = new BigInteger(aa,2);
			b = new BigInteger(bb,2);
			//System.out.println(a);
			//System.out.println(b);
			ans = a.gcd(b);
			System.out.print("Case #"+i+": ");
			System.out.println(ans.toString(2));
		}
	}
}