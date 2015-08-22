import java.util.*;
import java.math.BigInteger;
public class Main{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		BigInteger a, b, ans;
		int k;
		k= cin.nextInt();
		for(int i=1;i<=k;i++)
		{
			a = cin.nextBigInteger(2);
			b = cin.nextBigInteger(2);
			//System.out.println(a);
			//System.out.println(b);
			ans = a.gcd(b);
			System.out.print("Case #"+i+": ");
			System.out.println(ans.toString(2));
		}
	}
}