package unison.util;

import java.util.ArrayList;
import java.util.Random;

public class Vehiculo 
{
    private static Random rand = new Random();

    private String tipo;
    private char letra;
    private int modelo = 0;

    private static String[] vocales = {"a", "e", "i", "o", "u"};

    public Vehiculo(String tipo, char letra, int modelo)
    {
        this.tipo = tipo;
        this.letra = letra;
        this.modelo = modelo;
    }

    public static Vehiculo crearObjeto(char l)
    {
        String t;
        char let;
        int m;

        // if(Arrays.asList(vocales).contains(l))
        if(l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')
        {
            t = "Bicicleta";
            let = l;
            m = rand.nextInt((2024 - 1817)) + 1817;
        }
        else
        {
            t = "Tractor";
            let = l;
            m = rand.nextInt((2024 - 1917)) + 1917;
        }

        Vehiculo v = new Vehiculo(t, let, m);
        return v;
    }

    public static void imprimir(ArrayList<Vehiculo> bodega)
    {
        Vehiculo[] b = bodega.toArray(new Vehiculo[0]);

        for(int i = 0; i < b.length; i++)
        {
		    if(b[i].tipo == "Bicicleta")
            {
                System.out.print("\n\nTipo: " + b[i].tipo);
                System.out.print("\nLetra: " + b[i].letra);
                System.out.print("\nModelo: " + b[i].modelo);
            }
		}

        System.out.println("\n\n-------");

        for(int i = 0; i < b.length; i++)
        {
		    if(b[i].tipo == "Tractor")
            {
                System.out.print("\n\nTipo: " + b[i].tipo);
                System.out.print("\nLetra: " + b[i].letra);
                System.out.print("\nModelo: " + b[i].modelo);
            }
		}

        System.out.print("\n\n\n--------------------------------------------------------------\n\n\n");
    }
}