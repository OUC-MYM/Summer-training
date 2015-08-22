import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class Main{
	public static void main(String args[]){
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		PrintWriter cout = new PrintWriter(System.out);
		BigInteger ans;
		int k;
		k= cin.nextInt();
		for(int i=1;i<=k;i++)
		{
			ans = cin.nextBigInteger();
			BigInteger temp1;
			BigInteger temp2;
			temp1=ans.multiply(ans).multiply(new BigInteger("8"));
			temp2=ans.multiply(new BigInteger("7"));
			ans = new BigInteger("0");
			ans = ans.add(temp1);
			ans = ans.subtract(temp2);
			ans = ans.add(new BigInteger("1"));
			cout.print("Case #"+i+": ");
			cout.println(ans);
		}
		cout.flush();
	}
}