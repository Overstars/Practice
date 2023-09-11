package gobang;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.swing.JOptionPane;

class Dir
{
	int x;
	int y;
	public Dir(int x,int y) {
		// TODO Auto-generated constructor stub
		this.x = x;
		this.y = y;
	}
}
class Point
{
	int x;
	int y;
	public Point(int x,int y) {
		// TODO Auto-generated constructor stub
		this.x = x;
		this.y = y;
	}
	public Point newPoint(int len, Dir dir) 
	{
		return new Point(x + dir.x * len, y + dir.y * len);
	}
}
public class Evaluate {
	   static int number = 0; 
	   /////////////////////////////////////////////////////////////
	   public static Point computerGo() {
			int computer = DrawChessBoard.color;
			int player = 3 - DrawChessBoard.color;
			Point attackPoint = null;
             
			if (DrawChessBoard.chessManArray[6][6] == 0) {
				Point cur = new Point(6, 6);
				attackPoint = cur;
			} else 
			{
				while (true) {
				int i, j;
				//由于Math.random() 函数返回一个浮点,  伪随机数在范围[0，1)，所以Math.random()*(m-n)+n返回的结果为[n，m)。
			//	    i = (int) (Math.random() * 15);
		    //		j = (int) (Math.random() * 15);
				i = (int) (Math.random() * (10-5)+5);
			   	j = (int) (Math.random() * (10-5)+5);
				Point cur = new Point(i, j);
				if (DrawChessBoard.chessManArray[j][i] == 0) {
					attackPoint = cur;
					break;
				}
				}
			}
			number++;
			return attackPoint;
		}
	   
	   
	   
	   /////////////////////////////////////////////////////////////////
	   public static boolean isEnd(int[][]  chessManArray,int x,int y,int color){
		
		int count=0;      //  横向扫描     左右扫描
    	for(int i=Math.max(0,x-4);i<=Math.min(x+4,14);i++){
    		 //  前4列只能扫描到第0列，不能越界
    		if(chessManArray[i][y]==color){
    			count++;
    		//	System.out.println("判断5子连线:"+color+" y:"+y + " i:"+i);
    		}
    		if(count==5){
    			if(color==1){
    				JOptionPane.showMessageDialog(null, "白胜利");
    			}else{
    				JOptionPane.showMessageDialog(null, "黑胜利");		
    			}
    			return true;
    		}
    		
    	}
           count=0;        //  纵向扫描     上下扫描
    	for(int i=Math.max(0,y-4);i<=Math.min(y+4,14);i++){
                  //  前4行只能扫描到第0行，不能越界； 最多扫描到14行，不能越界
    		if(chessManArray[x][i]==color){
    			count++;
    		//	System.out.println("判断5子连线 :"+color+" count:"+count + " y:"+y);	
    		}
    		if(count==5){
    			if(color==1){
    				JOptionPane.showMessageDialog(null, "白胜利");
    			}else{
    				JOptionPane.showMessageDialog(null, "黑胜利");
    				
    			}
    			System.out.println("win");
    			return true;
    		} 		
    	}
   	
    	 count=0;     //   右斜   对角线扫描A    	
     	for(int i=x-Math.min(Math.min(x,y),5), j=y-Math.min(Math.min(x,y),5);i<=Math.min(14, x+6)&&j<=Math.min(14, j+6);i++,j++){
     			
     	//	System.out.println("判断5子连线 :"+color+" count:"+count +i+"---"+j+"---"+chessManArray[i][j]);	
    		if(chessManArray[i][j]==color){
    			count++;   			
    		}
    		if(count==5){
    			if(color==1){
    				JOptionPane.showMessageDialog(null, "白胜利");
    			}else{
    				JOptionPane.showMessageDialog(null, "黑胜利");			
    			}
    			return true;
    		}   		
    	}
   	    count=0;     //  左斜     对角线扫描B
    	for(int i=x+Math.min(Math.min(y,14-x),5), j=y-Math.min(Math.min(y,14-x),5);i>=Math.max(0, x-5)&&j<=Math.min(14, y+6);i--,j++){
    		System.out.println("判断5子连线 :"+color+" count:"+count +i+"---"+j+"---"+chessManArray[i][j]);		
    		if(chessManArray[i][j]==color){
    			count++;   			
    		}
    		if(count==5){
    			if(color==1){
    				JOptionPane.showMessageDialog(null, "白胜利");
    			}else{
    				JOptionPane.showMessageDialog(null, "黑胜利");				
    			}
    			return true;
    		}   		
    	}	
   	
    	return false;
    }
	   ////////////////////////////////////////////////
	   public static void saveQipu(String[] str, int st1) { // 写入文件b.txt中
			try { // 防止文件建立或读取失败，用catch捕捉错误并打印，也可以throw
				File writename = new File("D:\\先手队名 vs后手队名.txt"); // 相对路径，如果没有则要建立一个新的output。txt文件
				writename.createNewFile(); // 创建新文件
				BufferedWriter out = new BufferedWriter(new FileWriter(writename));
				
				if (DrawChessBoard.color == 1) {
				out.write("{[computer][player][computer][后手胜][");
			    } else {
				out.write("{[computer][player][先手胜][player][");
		     	} 
				
				SimpleDateFormat sdf =new SimpleDateFormat("yyyy.MM.dd HH:mm:ss" );
				Date d= new Date();
				String strDate = sdf.format(d);
		      //  System.out.println(" 格式化后的输出: "+strDate);
		        out.write(strDate+"线上]");
				
				for (int i = 0; i < st1; i++) {
					out.write(str[i]);
				} // \r\n即为换行
				
			
				out.write("}");
				out.flush(); // 把缓存区内容压入文件
				out.close(); // 最后记得关闭文件
			} catch (Exception e1) {
				e1.printStackTrace();
			}

		}
	   
	   
	   
	   ///////////////////////////////////////////////
	   
	   
}
