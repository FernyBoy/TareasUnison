import java.io.IOException;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Servidor
{
    public static void main(String[] args)
    {
        // Servidor
        ServerSocket servidor = null;

        // Sockets de clientes
        Socket ClientSocket_1 = null;
        Socket ClientSocket_2 = null;

        // Inputs y outputs de clientes
        // --- I/O Cliente 1
        DataInputStream inClient_1;
        DataOutputStream outClient_1;

        // --- I/O Cliente 2
        DataInputStream inClient_2;
        DataOutputStream outClient_2;

        final int PUERTO = 8080;
        
        try
        {
            servidor = new ServerSocket(PUERTO);

            System.out.println("---------------------------");
            System.out.println(" --- Servidor iniciado --- ");
            System.out.println("---------------------------");

            while (true) 
            {
                ClientSocket_1 = servidor.accept();
                System.out.println("\nCliente - 1 - conectado");
                inClient_1 = new DataInputStream(ClientSocket_1.getInputStream());
                outClient_1 = new DataOutputStream(ClientSocket_1.getOutputStream());

                ClientSocket_2 = servidor.accept(); 
                System.out.println("\nCliente - 2 - conectado");
                inClient_2 = new DataInputStream(ClientSocket_2.getInputStream());
                outClient_2 = new DataOutputStream(ClientSocket_2.getOutputStream());

                String mensaje_1 = inClient_1.readUTF();
                String mensaje_2 = inClient_2.readUTF();

                System.out.println(mensaje_1);
                System.out.println(mensaje_2);

                outClient_1.writeUTF("\nSaludos al servidor 1");
                outClient_2.writeUTF("\nSaludos al servidor 2");

                ClientSocket_1.close();
                ClientSocket_2.close();

                System.out.println("! Clientes desconectados !");
            }

        }
        catch(IOException ex)
        {
            Logger.getLogger(Servidor.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
