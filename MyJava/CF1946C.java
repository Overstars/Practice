import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class CF1946C {
	static boolean LOCAL = System.getSecurityManager() == null;
	static boolean TO_FILE = false;
	Scanner sc = new Scanner(System.in);
	PrintWriter pr = new PrintWriter(new OutputStreamWriter(System.out));
	List<Integer>[] G;
	int cnt = 0;
	int dfs(int u, int fa, int x) {
		int siz = 1;
		for (int v : G[u]) {
			if (v == fa)
				continue;
			siz += dfs(v, u, x);
		}
		if (siz >= x) {
			cnt ++;
			return 0;
		}
		return siz;
	}
	// 删除边数k，块大小x
	boolean check(int k, int x) {
		boolean flag = true;
		cnt = 0;
		int siz = dfs(1, 0, x);
		if (cnt < k)
			flag = false;
		if (siz < x && cnt <= k)
			flag = false;
		return flag;
	}
	void run() {
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			G = new ArrayList[n + 1];
			Arrays.setAll(G, i -> new ArrayList<>());
			int k = sc.nextInt();
			for (int i = 1; i < n; i++) {
				int u = sc.nextInt();
				int v = sc.nextInt();
				G[u].add(v);
				G[v].add(u);
			}
			int ans = 0, l = 0, r = n;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (check(k, mid)) {
					ans = max(ans, mid);
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			System.out.println(ans);
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
		new CF1946C().run();
	}
}


