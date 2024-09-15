import Hillo.Comunidad.Persona;
import java.util.Scanner;

public class Principal
{
    static Scanner in = new Scanner(System.in);  
    
    public static void main(String[] args)
    {
        System.out.println("\nIngresa el nombre de la persona que deseas registrar:");
        String nombre = in.nextLine();

        System.out.println("\nIngresa la edad del trabajador:");
        int edad = in.nextInt();

        // Crear una persona, con nombre y edad.
        Hillo.Comunidad.Persona persona01 = new Persona(nombre, edad);

        // La persona obtiene un trabajo... stripper
        // La operacion trabajar, crea el local donde la persona va a trabajar
        persona01.firmarContratoTrabajo();

        // Mandar a la persona a trabajar
        persona01.trabajar();

        // Imprimir datos de la persona
        System.out.println(
            "\n\nLa persona " + persona01.obtenerNombre() + 
            " ya tiene un contrato de " + persona01.obtenerEmpleo() + 
            " ubicado en " + persona01.empleador.obtenerDireccion() );
        System.out.println("____________________________________________________________\n");
        //Ejemplo de salida.
        // La persona Juan ya tiene un contrato de Stripper ubicado en Blvd. Kino 978.
    }
}