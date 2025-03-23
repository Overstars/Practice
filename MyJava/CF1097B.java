/*
 * @Author: Overstars
 * @Date: 2020-09-11 19:00:58
 * @LastEditTime: 2020-09-11 19:22:18
 * @LastEditors: Overstars
 */
import java.util.*;
public class CF1097B {
    public static boolean dfs(int []a,int x,int now,int n){
        if(x==n)
        {
            if(now%360==0)
                return true;
            else
                return false;
        }
        boolean flag = false;
        flag|=dfs(a, x+1, now+a[x], n);
        flag|=dfs(a, x+1, now-a[x], n);
        return flag;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int []a = new int [n];
        for(int i = 0 ; i < n ; i++ )
            a[i]=sc.nextInt();
        if(dfs(a,0,0,n))
            System.out.println("YES");
        else
            System.out.println("NO");
        sc.close();
    }
}
