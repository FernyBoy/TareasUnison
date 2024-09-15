/*
 * Solicitar al usuario un numero entero N; por medio de consola.
 *  N representa la cantidad de ciclos a realizar.
 *  Si N no la proporciona el usuario, poner N = 10000.
 * 
 * Hacer un ciclo (for, while, etc.) con la N:
 *  Generar un numero aleatorio (double x).
 *  Generar un numero aleatorio (double y).
 *  Calcular la distancia de (0, 0) al punto (x, y) en caso de ser menor que 1,
 *  incrementar el contador de exitos (exitos++)
 */

import java.util.Scanner;
import java.lang.Math;
import java.lang.Integer;

class Ciclos
{
    public static Scanner in = new Scanner(System.in);

    public static int ObtenerCiclos(String args)
    {
        int n = Integer.parseInt(args);

        if(n < 1)
        {
            return 100;
        }
        return n;
    }

    public static void GenerarCoordenadas(int n)
    {
        for(int i = 0; i < n; i++)
        {
            double x = Math.random() * 2 - 1;
            double y = Math.random() * 2 - 1;
        }
    }
    public static void main(String[] args)
    {
        int N = ObtenerCiclos(args[0]);

        System.out.println(args);


    }
}