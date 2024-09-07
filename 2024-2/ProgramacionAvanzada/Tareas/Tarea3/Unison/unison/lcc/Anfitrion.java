package unison.lcc;

import java.util.Scanner;

// Esta clase da la bienvenida, pide su nombre al usuario, pide el valor minimo y maximo, y despide al usuario
public class Anfitrion
{
    Scanner in = new Scanner(System.in);

    String nombre;

    public void DarBienvenida()
    {
        ImprimirTitulo();

        System.out.println("Bienvenido a Atinale al Numero. \nPara poder comenzar, por favor dame tu nombre:");
        nombre = in.nextLine();

        System.out.println("\nMucho gusto " + nombre + "!");
        System.out.println("\n\nComencemos...");
    }

    private void ImprimirTitulo()
    {
        System.out.println("\n\n\n-------------------------");
        System.out.println("|                       |");
        System.out.println("|   ATINALE AL NUMERO   |");
        System.out.println("|                       |");
        System.out.println("-------------------------\n\n");
    }

    public void ImprimirDespedida()
    {
        System.out.println("\n\n-------------------------");
        System.out.println("|   Gracias por jugar   |");
        System.out.println("-------------------------\n\n");
    }
}