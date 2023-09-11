/*
 * @Author: Overstars
 * @Date: 2020-09-11 17:41:08
 * @LastEditTime: 2020-09-11 18:03:24
 * @LastEditors: Overstars
 */
import java.util.*;
import java.util.Arrays;
public class CF706B {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int n = sc.nextInt();
        int []a = new int[n];
        for(int i=0;i<n;i++)
            a[i]=sc.nextInt();
        Arrays.sort(a);
        int q=sc.nextInt();
        while(q-->0)
        {
            int x=sc.nextInt(),l=1,r=n,ans=0;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(a[mid-1]<=x)
                {
                    l=mid+1;
                    ans=mid;
                }
                else
                    r=mid-1;
            }
            System.out.println(ans);
        }
    }
}
