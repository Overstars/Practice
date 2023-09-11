/*
 * @Author: Overstars
 * @Date: 2021-04-10 19:37:14
 * @LastEditTime: 2021-04-10 19:44:39
 * @LastEditors: Overstars
 */
import java.net.Socket;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
 
public class Handler implements Runnable {
	private Socket socket;
	Handler(Socket socket)
	{
		this.socket=socket;
	}
	public void run()
	{
		try {
			System.out.println("新连接："+socket.getInetAddress()+":"+socket.getPort());
			InputStreamReader isr=new InputStreamReader(socket.getInputStream());
			BufferedReader br=new BufferedReader(isr);
			String words;
			while((words=br.readLine())!=null)
			{
				Service.ta.append("收到消息："+words+"\n");
				Service.ta.append("请输入回复："+"\n");
			}		
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally 
		{
			try {
				System.out.println("关闭连接："+socket.getInetAddress()+":"+socket.getPort());
				if(socket!=null)
				{
				socket.close();
				}
			}catch(IOException e)
			{
				e.printStackTrace();
			}
		}
	}
}