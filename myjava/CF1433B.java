/*
 * @Author: Overstars
 * @Date: 2020-10-20 22:48:06
 * @LastEditTime: 2020-10-20 22:53:53
 * @LastEditors: Overstars
 */
import java.util.*;
import java.io.*;
public class CF1433B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //BufferedReader in =new BufferedReader(new InputStreamReader(System.in));//Integer.parseInt(in.readLine())读入一行
        PrintWriter pr = new PrintWriter(new OutputStreamWriter(System.out)); // 用于输出的对象
        int t = sc.nextInt(),n,maxn=55;
        int []a = new int [maxn];
        while(t-- > 0)
        {
            n = sc.nextInt();
            int ok=0,pre=0,ans=0;
            for(int i=1;i<=n;i++)
            {
                a[i] = sc.nextInt();
                if(ok == 1 && a[i] == 1)
                {
                    ans += i-pre-1;
                    pre = i;
                }
                if(a[i] == 1)
                {
                    ok = 1;
                    pre = i;
                }
            }
            pr.println(ans);
        }
        sc.close();
        pr.flush();//不管用上述的哪一种输出，最后记得flush
    }
}
