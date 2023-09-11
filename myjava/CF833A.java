
/*
 * @Author: Overstars
 * @Date: 2020-09-13 22:16:49
 * @LastEditTime: 2020-09-13 23:32:20
 * @LastEditors: Overstars
 */
import java.io.*;
import java.util.HashMap;
import java.util.Map;
public class CF833A {
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
    public static HashMap<Integer,Integer> get(int x){
        // ArrayList <Integer> A = new ArrayList<Integer>();
        HashMap<Integer,Integer> A = new HashMap<Integer,Integer>();
        for( int i = 2; i*i <= x; i++){
            if(x%i==0){
                A.put(i, 0);
                while(x%i==0){
                    int val = A.get(i)+1;
                    A.put(i, val);
                    x /= i;
                }
            }
        }
        if(x>1)
            A.put(x, 1);
        return A;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //BufferedReader in =new BufferedReader(new InputStreamReader(System.in));//Integer.parseInt(in.readLine())读入一行
        PrintWriter pr = new PrintWriter(new OutputStreamWriter(System.out)); // 用于输出的对象
        Integer t = sc.nextInt();
        while(t-- > 0){
            int a = sc.nextInt(), b = sc.nextInt(), ok=1;
            if((a==1||b==1) && a+b>2)
                ok=0;
            // ArrayList<Integer> A = get(a);//java内存自动回收
            //ArrayList<Integer> B = get(b);
            Map<Integer,Integer> c1 = get(a);
            Map<Integer,Integer> c2 = get(b);
            // Map<Integer,Integer> c2 = new HashMap<Integer,Integer>();
            for(Integer x:c1.keySet()){
                int n1 = c1.get(x), n2=0;
                if(c2.containsKey(x))
                    n2 = c2.get(x);
                if((n1+n2)%3 != 0||Math.max(n1, n2)>Math.min(n1, n2)*2)
                    ok=0;
            }
            pr.println(ok==1?"YES":"NO");
        }
        // sc.close();
        pr.flush();//不管用上述的哪一种输出，最后记得flush
    }
}
