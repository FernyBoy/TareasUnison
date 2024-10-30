import java.util.Scanner;
import java.io.FileWriter;
import java.io.IOException;
import java.io.File;
import java.util.ArrayList;

import src.Datos;

class Main {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) 
    {
        boolean agregar = true;
        int respuesta = 0;
        ArrayList<Datos> listaDatos = new ArrayList<>(); 
        
        try 
        {
            File archivo = new File("Datos.txt");
            FileWriter escritor = new FileWriter(archivo);

            escritor.write("Nombre completo | Edad del encuestado | Semestre actual\n");

            while (agregar) 
            {
                Datos alumno = new Datos();
                listaDatos.add(alumno);

                System.out.println("\n¿Deseas seguir agregando alumnos? [0: No | 1: Sí]");
                respuesta = in.nextInt();

                while (respuesta != 0 && respuesta != 1) 
                {
                    System.out.println("Ingresa una respuesta válida [0: No | 1: Sí]");
                    respuesta = in.nextInt();
                }

                if (respuesta == 0) 
                {
                    agregar = false;
                }
            }

            for (Datos dato : listaDatos) 
            {
                escritor.write(dato.nombre + " | " + dato.edad + " | " + dato.semestre + "\n");
            }

            escritor.close();

            System.out.println("\n\nLos datos se han guardado en 'Datos.txt'.");
        } 
        catch(IOException err) 
        {
            System.err.println("No es posible escribir en el archivo.");
        }
    }
}