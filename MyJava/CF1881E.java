import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;
 
public class CF1881E {
    static boolean LOCAL = System.getSecurityManager() == null;
    static boolean TO_FILE = false;
    Scanner sc = new Scanner(System.in);
	PrintWriter pr = new PrintWriter(new OutputStreamWriter(System.out));
 
    void run() {
		//pr.println("????");
		int t, n;
		t = sc.nextInt();
		while (t-- > 0) {
			n = sc.nextInt();
			int[] a = new int[n + 2];
			int[] dp = new int[n + 2];
			for (int i = 1; i <= n; i++) {
				a[i] = sc.nextInt();
			}
			Arrays.fill(dp, 0);
			for (int i = n; i >= 1; i--) {
				if (i + a[i] + 1 <= n + 1) {
					dp[i] = Math.min(dp[i + a[i] + 1], dp[i + 1] + 1);
				} else {
					dp[i] = dp[i + 1] + 1;
				}
			}
			System.out.println(dp[1]);
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
        new CF1881E().run();
    }
}
