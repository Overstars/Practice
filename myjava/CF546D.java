/*
 * @Author: Overstars
 * @Date: 2020-09-11 23:38:11
 * @LastEditTime: 2020-09-13 22:29:03
 * @LastEditors: Overstars
 */
import java.io.*;
import java.util.*;
import java.util.Scanner;
@SuppressWarnings("unused")
public class CF546D {
    static class Scanner {
		Scanner(InputStream in) { this.in = in; } InputStream in;
		int k, l; byte[] bb = new byte[1 << 15];
		byte getc() {
			if (k >= l) {
				k = 0;
				try { l = in.read(bb); } catch (IOException e) { l = 0; }
				if (l <= 0) return -1;
			}
			return bb[k++];
		}
		int nextInt() {
			byte c = 0; while (c <= 32) c = getc();
			int a = 0;
			while (c > 32) { a = a * 10 + c - '0'; c = getc(); }
			return a;
		}
	}
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pr = new PrintWriter(new OutputStreamWriter(System.out)); // 用于输出的对象
        int lim = (int)5e6+5;
        int []sum = new int [lim];
        for(int i=2;i<lim;i++){
            if(sum[i] == 0){//i为素数
                for(int j=i; j < lim; j += i){//i对其每个倍数的贡献
                    int now=0,tmp=j;
                    while(tmp % i == 0){
                        now++;
                        tmp /= i;
                    }
                    sum[j] += now;
                }
            }
            sum[i] += sum[i-1];
        }
        int t = sc.nextInt();
        while(t-->0){
            int a = sc.nextInt(), b = sc.nextInt();
            pr.println(sum[a]-sum[b]);
        }
        pr.flush();//不管用上述的哪一种输出，最后记得flush
        // sc.close();
    }
}