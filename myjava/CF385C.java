/*
 * @Author: Overstars
 * @Date: 2020-09-12 20:54:55
 * @LastEditTime: 2020-10-13 15:50:05
 * @LastEditors: Overstars
 */
import java.io.*;
// import java.util.Scanner;
public class CF385C {
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
        //BufferedReader in =new BufferedReader(new InputStreamReader(System.in));//Integer.parseInt(in.readLine())读入一行
        PrintWriter pr = new PrintWriter(new OutputStreamWriter(System.out)); // 用于输出的对象
        int n = sc.nextInt();
        int []a = new int [n];
        int []sum = new int [(int)(1e7+10)];
        for(int i = 0 ; i<n ; i++){
            a[i]=sc.nextInt();
            for(int j =2 ; j*j <= a[i] ; j++){
                if(a[i]%j==0){
                    sum[j]++;
                    while(a[i]%j==0)
                        a[i]/=j;
                }
            }
            if(a[i]>1)
                sum[a[i]]++;
        }
        for(int i = 1 ; i<(int)(1e7+10) ; i++){
            // pr.println("sum["+i+"]="+sum[i]);
            sum[i] += sum[i-1];
        }
        int t = sc.nextInt();
        while(t-- > 0){
            int l = Math.min(sc.nextInt(),(int)(1e7+5)), r = Math.min(sc.nextInt(),(int)(1e7+5));
            pr.println(sum[r]-sum[l-1]);
        }
        // sc.close();
        pr.flush();//不管用上述的哪一种输出，最后记得flush
    }
}
/*
 *可以发现1e7之后必定为0,所以开的下
 *那就直接
 */