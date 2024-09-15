package Hillo.Comunidad;

import java.util.Scanner;

public class Persona
{
    Scanner in = new Scanner(System.in);

    String nombre;
    int edad;
    String trabajo; 
    public Hillo.Comunidad.Empleador empleador = new Empleador();
    
    public Persona(String n, int e)
    {
        this.nombre = n;
        this.edad = e;
    }
    
    public void firmarContratoTrabajo()
    {
        System.out.println("\nIngresa la profesion a la que se dedicara " + nombre);
        this.trabajo = in.nextLine();
        System.out.println("\n" + nombre + " ha comenzado a trabajar de " + this.trabajo);
    }
    
    public void trabajar()
    {
        System.out.println("\nIngresa la dirección en la que trabajará " + nombre);
        this.empleador.establecerDireccion(in.nextLine());
    }   

    public String obtenerNombre()
    {
        return nombre;
    }

    public String obtenerEmpleo()
    {
        return trabajo;
    }
}
