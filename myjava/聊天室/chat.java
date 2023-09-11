/*客户端*/
import java.net.Socket;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.Writer;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JTextField;
public class Client extends JFrame {
	public static String serverId="输入IP地址";
	private static JTextField jip;        //IP地址
	private static JButton connect;       //连接按钮
	private static JTextArea ta;          //聊天区域
	private static JTextField text;       //输入消息
	private static JButton send;          //发送按钮
	private static JButton stop;          //停止服务按钮
	Socket socket;
	Client()
	{
		JFrame frame=new JFrame("网络聊天---客户端");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(600, 420);
		Container c=frame.getContentPane();
		c.setLayout(new FlowLayout()); 
		JTextField address=new JTextField("请输入要连接的IP:",20);
		jip=new JTextField("10.101.219.78",20);
		connect=new JButton("连接");
		connect.addActionListener(new ActionListener() //添加连接按钮监听事件
		{
			public void actionPerformed(ActionEvent e)
			{
				try
				{
					socket=new Socket(serverId,2046); //建立连接
					ta.append("连接已建立！");
				}
				catch(Exception ex)
				{
					ex.printStackTrace();
				}
			}
		});        
		ta=new JTextArea(15,52);    
		text=new JTextField(40);           
		send=new JButton("发送");     
		send.addActionListener(new ActionListener()   //添加发送按钮监听事件
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
					InputStreamReader isr=new InputStreamReader(socket.getInputStream());
					BufferedReader br=new BufferedReader(isr);
					ta.append("收到消息："+br.readLine());
				}
				catch(Exception ex)
				{
					ex.printStackTrace();
				}
			}
		});        
		stop=new JButton("停止服务");
		stop.addActionListener(new ActionListener()    //添加停止服务按钮监听事件
		{
			public void actionPerformed(ActionEvent e)
			{
				try {
					socket.close();
					}
				catch(Exception ex) 
				{
					ex.printStackTrace();
				}		
			}
		});        
		c.add(address);
		c.add(jip);
		c.add(connect);
		c.add(ta);
		c.add(text);
		c.add(send);
		c.add(stop);
		frame.setVisible(true);
	}
	public static void main(String args[])
	{
		Client client=new Client();
		ta.append("请建立连接！");
	}
}