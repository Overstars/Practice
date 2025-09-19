import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class CF1872E {
	static boolean LOCAL = System.getSecurityManager() == null;
	static boolean TO_FILE = false;
	Scanner sc = new Scanner(System.in);
	PrintWriter pr = new PrintWriter(new OutputStreamWriter(System.out));

	void run() {
		int q, tp, l, r, g;
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			int[] a = new int[n + 1];
			int[] sum = new int[n + 1];
			int ans = 0, total = 0;
			fill(sum, 0);
			for (int i = 1; i <= n; i++) {
				a[i] = sc.nextInt();
				total ^= a[i];
			}
			String s = sc.next();
			for (int i = 1; i <= n; i++) {
				sum[i] = sum[i - 1] ^ a[i];
				if (s.charAt(i - 1) == '1')
					ans ^= a[i];
			}
			q = sc.nextInt();
			//System.out.print("ans = ");
			while (q-- > 0) {
				tp = sc.nextInt();
				if (tp == 1) {
					l = sc.nextInt();
					r = sc.nextInt();
					ans = ans ^ sum[r] ^ sum[l - 1];
				} else {
					g = sc.nextInt();
					System.out.printf("%d ", g == 1 ? ans : (sum[n] ^ ans));
				}
			}
			System.out.println();
		}
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		if (LOCAL) {
			try {
				System.setIn(new FileInputStream("./bin/in.txt"));
			} catch (Throwable e) {
				LOCAL = false;
			}
		}
		if (TO_FILE) {
			try {
				System.setOut(new PrintStream("./src/output.txt"));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		new CF1872E().run();
	}
}

