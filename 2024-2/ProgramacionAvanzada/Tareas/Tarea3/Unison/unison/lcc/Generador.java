package unison.lcc;

import java.util.Scanner;
import java.util.Random;

// Esta clase genera numeros aleatorios en un rango dado.
public class Generador
{
    private Scanner in = new Scanner(System.in);
    private Random generarRandom = new Random();

    public int min, max, rand, minimoCercano, maximoCercano, minimoIntentos;

    public void Generar()
    {
        EstablecerRango();
        GenerarRandom();
        GenerarCercanos();
        MaximoDeIntentos();
    }

    private void EstablecerRango()
    {
        int minimo, maximo;

        System.out.println("\nIngresa el limite inferior del rango:");
        minimo = in.nextInt();

        System.out.println("\nIngresa el limite superior del rango:");    
        maximo = in.nextInt();

        if((max - 2) <= min)
        {
            while((maximo - 2) <= minimo)
            {
                System.out.println("\nEl limite superior debe ser 3 unidades mayor al limite inferior.");

                System.out.println("\nIngresa nuevamente el limite inferior del rango:");
                minimo = in.nextInt();
    
                System.out.println("\nIngresa nuevamente el limite superior del rango.");    
                maximo = in.nextInt();
            }

            min = minimo;
            max = maximo;
        }
        else
        {
            min = minimo;
            max = maximo;
        }

        System.out.println("\nTu rango se ha establecido entre " + min + " y " + max + ".");
    }

    private void GenerarRandom()
    {
        rand = (generarRandom.nextInt(max - (min + 1))) + (min + 1);
        System.out.println("\nSe ha generado un numero aleatorio entre " + min + " y " + max + ".");
    }

    private void GenerarCercanos()
    {
        int radio = (max - min) / 5;
        minimoCercano = rand - radio;
        maximoCercano = rand + radio;
    }

    private void MaximoDeIntentos()
    {
        minimoIntentos = (int) Math.ceil((Math.log((max - min)) / Math.log(2)));
    }
}