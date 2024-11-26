import java.io.IOException;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.Scanner;

public class Cliente
{

    public static void main(String[] args)
    {
        final String HOST = "127.0.0.1";
        final int PUERTO = 8080;
        DataInputStream in;
        DataOutputStream out;

        Scanner inScanner = new Scanner(System.in);

        try
        {
            Socket sc = new Socket(HOST, PUERTO);

            in = new DataInputStream(sc.getInputStream());
            out = new DataOutputStream(sc.getOutputStream());

            System.out.println("Escribe el mensaje que deseas mandar al servidor:");
            String mensajeCliente = inScanner.nextLine();

            out.writeUTF("\n--------------\n" + mensajeCliente + "\n--------------\n");

            String mensajeServidor = in.readUTF();

            System.out.println(mensajeServidor);

            sc.close();
        }
        catch(IOException ex)
        {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
