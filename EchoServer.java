import java.net.*;
import java.io.*;

public class EchoServer {
    public static void main(String[] args) throws IOException {
	
	//create server	
        try (
            ServerSocket serverSocket =
                new ServerSocket(3000);//port 3000
            Socket clientSocket = serverSocket.accept();     
            PrintWriter out =
                new PrintWriter(clientSocket.getOutputStream(), true);                   
            BufferedReader in = new BufferedReader(
                new InputStreamReader(clientSocket.getInputStream()));
        ) {
            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                out.println(inputLine);
            }
        } catch (IOException e) {
            System.out.println("Error, failed to connect");
            System.out.println(e.getMessage());
        }//end of try-catch
    }//end of main
}//end of class
