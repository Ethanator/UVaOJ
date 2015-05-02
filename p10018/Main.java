import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

	public static String reverse(String s) {
		return new StringBuilder(s).reverse().toString();
	}

	public static boolean isPalindrome(String s) {
		String r = "";
		for (int i = s.length() - 1; i >= 0; --i) {
			r += s.charAt(i);
		}
		return s.equals(r);
	}

	public static void findPalindrome(String xStr) {
		BigInteger x = new BigInteger(xStr);
		String s = xStr;
		
		int count = 0;
		while (!isPalindrome(s)) {
			x = x.add(new BigInteger(reverse(s)));
			s = String.valueOf(x);
			++count;
			if (count == 1001 && !isPalindrome(s)) {
				System.out.printf("*** Never palindrome: %s\n", xStr);
			}
		}

		System.out.printf("%d %s\n", count, s);
	}

	public static void main(String[] args) throws IOException {
		Scanner cin = new Scanner(new BufferedReader(new InputStreamReader(
										System.in)));

		int n = cin.nextInt();
		cin.nextLine();
		for (int i = 0; i < n; ++i) {
			 findPalindrome(cin.nextLine());
		}
	}
}
