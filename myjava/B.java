import java.util.Scanner;
public class B{
    public  static void main(String[] args) {
        Scanner input = new Scanner(System.in);

  //      System.out.print("Enter yearly interest rate, for example 8.25:");
        int num1=(int)(Math.random()*10);
        int num2=(int)(Math.random()*10);
        if(num1<num2)
        {
            num1=num1^num2;
            num2=num1^num2;
            num1=num1^num2;
        }
        int ans=input.nextInt();
        if(num1-num2==ans)
            System.out.print("wtf");
        else
           System.out.println(num1+"-"+num2+"!="+ans);
        input.close();
    }
}
