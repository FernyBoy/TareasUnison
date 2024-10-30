package src;

import java.util.Scanner;

public class Datos 
{
    static Scanner in = new Scanner(System.in);

    public String nombre;
    public int edad;
    public int semestre;
    
    public Datos() 
    {
        PreguntarDatos();
    }

    private void PreguntarDatos() 
    {
        System.out.print("\nIngresa tu nombre completo:\n - ");
        nombre = in.nextLine();

        System.out.print("\nIngresa tu edad:\n - ");
        edad = in.nextInt();

        System.out.print("\nIngresa tu semestre:\n - ");
        semestre = in.nextInt();
        
        in.nextLine();
    }
}

