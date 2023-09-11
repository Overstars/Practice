/*
 * @Author: Overstars
 * @Date: 2021-04-10 19:36:51
 * @LastEditTime: 2021-04-10 19:44:32
 * @LastEditors: Overstars
 */
/*服务器端*/
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
 
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JTextField;
public class Service extends JFrame{
	private static Service service=new Service();
	private static ServerSocket serverSocket;     //创建ServerSocket服务对象
	private static Socket socket;
	public static JTextArea ta;     //聊天区域
	public static JTextField text;  //消息输入
	public static JButton send;     //发送按钮
	Service()
	{
		JFrame frame=new JFrame("网络聊天---服务器");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(600, 400);
		Container c=frame.getContentPane();
		c.setLayout(new FlowLayout()); 
		ta=new JTextArea(15,52);     
		text=new JTextField(40);     
		send=new JButton("发送"); 
		send.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				try {
					Writer writer=new OutputStreamWriter(socket.getOutputStream());
					ta.append("请输入消息："+"\n");
					String s=text.getText();
					ta.append("我:"+s+"\n");
					writer.write(s+"\n");
					writer.flush();
					ta.append("消息已发出！"+"\n");
				}
				catch(Exception ex)
				{
					ex.printStackTrace();
				}
			}
		});
		c.add(ta);
		c.add(text);
		c.add(send);
		frame.setVisible(true);
	}
	public static void main(String args[]) 
	{
		try {
			serverSocket=new ServerSocket(2048);   //在2046端口建立监听
			ta.append("服务器监听建立，等待连接..."+"\n");
			socket=serverSocket.accept(); //产生阻塞直至客户端连接
			ta.append("已成功连接！"+"\n");
			Thread thread=new Thread(new Handler(socket));    //创建新线程
			thread.start();     //启动线程
			serverSocket.close();   //关闭服务
		}
		catch(SocketException e)
		{
			e.printStackTrace();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}