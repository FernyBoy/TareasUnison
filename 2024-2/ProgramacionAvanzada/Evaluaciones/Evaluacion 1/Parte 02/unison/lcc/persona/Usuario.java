package unison.lcc.persona;

import java.util.Random;
import java.util.Scanner;

public class Usuario
{
    static Scanner in = new Scanner(System.in);
    Random random = new Random();

    static int numeroFav;

    public Usuario(String modo){}

    public static void preguntarNumeroFavorito()
    {
        System.out.println("\nDime cuál es tu número favorito entre 0 y 9: ");
        numeroFav = in.nextInt();

        while(numeroFav < 0 || numeroFav > 9)
        {
            System.out.print("\nTu número debe ser entre el 0 y el 9: ");
            numeroFav = in.nextInt();
        }
    }

    public static int preguntarCantidadNumeros()
    {
        int cantidad = 0;

        System.out.print("\nIndica la cantidad de números entre 100 y 999 que deseas generar al azar: \n");
        cantidad = in.nextInt();

        while(cantidad < 100 || cantidad > 999)
        {
            System.out.print("\nLa cantidad debe ser entre 100 y 999: \n");
            cantidad = in.nextInt();
        }

        return cantidad;
    }
    
    public int generarNumerosAzar(int n)
    {
        int contador = 0, numeroAzar;

        for(int i = 0; i < n; i++)
        {
            numeroAzar = random.nextInt(10);
            
            if(numeroAzar == numeroFav)
            {
                contador++;
            }
        }

        return contador;
    }
    public void imprimirFrecuencia(int f)
    {
        System.out.print("\nEl número " + numeroFav + " ha aparecido " + f + " veces.\n\n");
        
        System.out.print("---------------------------------------------\n\n");
    }
}
