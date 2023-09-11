/*
 * @Author: Overstars
 * @Date: 2020-09-11 19:33:08
 * @LastEditTime: 2020-09-11 19:44:35
 * @LastEditors: Overstars
 */
import java.util.*;
public class CF1382A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q=sc.nextInt();
        while(q-->0)
        {
            int n=sc.nextInt(),m=sc.nextInt();
            int []a = new int [n];
            int []b = new int [m];
            boolean []mp=new boolean [1005];
            for(int i=0;i<n;i++){
                a[i]=sc.nextInt();
                mp[a[i]]=true;
            }
            int ans=0;
            for(int i=0;i<m;i++)
            {
                b[i]=sc.nextInt();
                if(mp[b[i]])
                    ans=b[i];
            }
            if(ans>0)
            {
                System.out.println("YES");
                System.out.println("1 "+ans);
            }
            else
                System.out.println("NO");
        }
        sc.close();
    }
}
