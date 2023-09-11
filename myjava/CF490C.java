/*
 * @Author: Overstars
 * @Date: 2020-09-12 11:47:06
 * @LastEditTime: 2020-09-12 12:26:06
 * @LastEditors: Overstars
 */
import java.io.*;
import java.util.Scanner;
public class CF490C{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //BufferedReader in =new BufferedReader(new InputStreamReader(System.in));//Integer.parseInt(in.readLine())读入一行
        PrintWriter pr = new PrintWriter(new OutputStreamWriter(System.out)); // 用于输出的对象
        String s = sc.nextLine();
        int a = sc.nextInt(), b = sc.nextInt(),ans = 0;
        boolean []ok = new boolean [(int)s.length()];
        for(int i = 0, now=0 ; i<s.length() ; i++){
            now = ((now*10)+((int)s.charAt(i)-'0'))%a;
            if(now==0)
                ok[i] = true;
        }
        for(int i = s.length()-1, now=0 , f=1; i>0 ; i--){
            now = ((s.charAt(i)-'0')*f + now)%b;
            if(now==0 && s.charAt(i)!='0' && ok[i-1]==true){
                ans=i;
                break;
            }
            f = (f*10)%b;
        }
        if(ans>0){//ans为b串起始位置
            pr.println("YES\n"+s.substring(0, ans));
            pr.println(s.substring(ans));
        }
        else{
            pr.println("NO");
        }
        sc.close();
        pr.flush();
    }
}