package GeneradorDeArchivos;
import java.io.FileWriter;
import java.io.IOException;
import java.io.File;

class Main
{
    public static void main(String[] args)
    {
        try
        {
            File archivo = new File("Datos.txt");
            FileWriter escritor = new FileWriter(archivo);
            escritor.write("Pan al pan, al vino vino \nY en tu culo \nMi pepino");
            escritor.write("\n\n-------------------------------");
            escritor.close();
        }
        catch(IOException err)
        {
            System.err.println("No es posible escribir en el archivo.");
        }
    }
}

