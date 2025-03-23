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
				//����Math.random() ��������һ������,  α������ڷ�Χ[0��1)������Math.random()*(m-n)+n���صĽ��Ϊ[n��m)��
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
		
		int count=0;      //  ����ɨ��     ����ɨ��
    	for(int i=Math.max(0,x-4);i<=Math.min(x+4,14);i++){
    		 //  ǰ4��ֻ��ɨ�赽��0�У�����Խ��
    		if(chessManArray[i][y]==color){
    			count++;
    		//	System.out.println("�ж�5������:"+color+" y:"+y + " i:"+i);
    		}
    		if(count==5){
    			if(color==1){
    				JOptionPane.showMessageDialog(null, "��ʤ��");
    			}else{
    				JOptionPane.showMessageDialog(null, "��ʤ��");		
    			}
    			return true;
    		}
    		
    	}
           count=0;        //  ����ɨ��     ����ɨ��
    	for(int i=Math.max(0,y-4);i<=Math.min(y+4,14);i++){
                  //  ǰ4��ֻ��ɨ�赽��0�У�����Խ�磻 ���ɨ�赽14�У�����Խ��
    		if(chessManArray[x][i]==color){
    			count++;
    		//	System.out.println("�ж�5������ :"+color+" count:"+count + " y:"+y);	
    		}
    		if(count==5){
    			if(color==1){
    				JOptionPane.showMessageDialog(null, "��ʤ��");
    			}else{
    				JOptionPane.showMessageDialog(null, "��ʤ��");
    				
    			}
    			System.out.println("win");
    			return true;
    		} 		
    	}
   	
    	 count=0;     //   ��б   �Խ���ɨ��A    	
     	for(int i=x-Math.min(Math.min(x,y),5), j=y-Math.min(Math.min(x,y),5);i<=Math.min(14, x+6)&&j<=Math.min(14, j+6);i++,j++){
     			
     	//	System.out.println("�ж�5������ :"+color+" count:"+count +i+"---"+j+"---"+chessManArray[i][j]);	
    		if(chessManArray[i][j]==color){
    			count++;   			
    		}
    		if(count==5){
    			if(color==1){
    				JOptionPane.showMessageDialog(null, "��ʤ��");
    			}else{
    				JOptionPane.showMessageDialog(null, "��ʤ��");			
    			}
    			return true;
    		}   		
    	}
   	    count=0;     //  ��б     �Խ���ɨ��B
    	for(int i=x+Math.min(Math.min(y,14-x),5), j=y-Math.min(Math.min(y,14-x),5);i>=Math.max(0, x-5)&&j<=Math.min(14, y+6);i--,j++){
    		System.out.println("�ж�5������ :"+color+" count:"+count +i+"---"+j+"---"+chessManArray[i][j]);		
    		if(chessManArray[i][j]==color){
    			count++;   			
    		}
    		if(count==5){
    			if(color==1){
    				JOptionPane.showMessageDialog(null, "��ʤ��");
    			}else{
    				JOptionPane.showMessageDialog(null, "��ʤ��");				
    			}
    			return true;
    		}   		
    	}	
   	
    	return false;
    }
	   ////////////////////////////////////////////////
	   public static void saveQipu(String[] str, int st1) { // д���ļ�b.txt��
			try { // ��ֹ�ļ��������ȡʧ�ܣ���catch��׽���󲢴�ӡ��Ҳ����throw
				File writename = new File("D:\\���ֶ��� vs���ֶ���.txt"); // ���·�������û����Ҫ����һ���µ�output��txt�ļ�
				writename.createNewFile(); // �������ļ�
				BufferedWriter out = new BufferedWriter(new FileWriter(writename));
				
				if (DrawChessBoard.color == 1) {
				out.write("{[computer][player][computer][����ʤ][");
			    } else {
				out.write("{[computer][player][����ʤ][player][");
		     	} 
				
				SimpleDateFormat sdf =new SimpleDateFormat("yyyy.MM.dd HH:mm:ss" );
				Date d= new Date();
				String strDate = sdf.format(d);
		      //  System.out.println(" ��ʽ��������: "+strDate);
		        out.write(strDate+"����]");
				
				for (int i = 0; i < st1; i++) {
					out.write(str[i]);
				} // \r\n��Ϊ����
				
			
				out.write("}");
				out.flush(); // �ѻ���������ѹ���ļ�
				out.close(); // ���ǵùر��ļ�
			} catch (Exception e1) {
				e1.printStackTrace();
			}

		}
	   
	   
	   
	   ///////////////////////////////////////////////
	   
	   
}
