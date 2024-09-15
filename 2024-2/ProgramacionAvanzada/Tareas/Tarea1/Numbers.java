import java.util.Scanner;
import java.math.BigInteger;

/*
 * Nombre: Borquez Guerrero Angel Fernando
 * Expediente: 219208106
 * 
 * Este programa se dedica a calcular el maximo comun divisor y el minimo comun divisor haciendo una comparacion entre
 * las funciones creadas de manera propia y las funciones que existen en la API de java pidiendo dos numeros para hacer
 * los respectivos calculos.
 * 
 */

class Numbers
{
    public static int MCD(int a, int b)
    {
        while(b != 0)
        {
            int c = b;
            b = a % b;
            a = c;
        }

        return a;
    }
    
    public static int MCM(int a, int b)
    {
        return (a * b) / MCD(a, b);
    }

    public static void Despedida()
    {
        System.out.println("Creado por Fernando Borquez en la Universidad de Sonora.\n\n");
    }
    
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        int a, b, mcd, mcm;
        BigInteger bigA, bigB, bigMcd, bigMcm;
        
        System.out.println("Ingresa el valor 1:");
        a = in.nextInt();
        bigA = BigInteger.valueOf(a);
        System.out.println("\n---------------------------------------\n");

        System.out.println("Ingresa el valor 2:");
        b = in.nextInt();
        bigB = BigInteger.valueOf(b);
        System.out.println("\n---------------------------------------\n");

        mcd = MCD(a, b);
        mcm = MCM(a, b);

        bigMcd = bigA.gcd(bigB);
        bigMcm = (bigA.multiply(bigB)).divide(bigMcd);

        System.out.println("------------Funciones propias------------");
        System.out.println("El máximo común divisor entre " + a + " y " + b + " es: " + mcd);
        System.out.println("\nEl mínimo común múltimplo entre " + a + " y " + b  + " es: " + mcm);
        System.out.println("\n");

        System.out.println("------------Funciones de Java------------");
        System.out.println("El máximo común divisor entre " + a + " y " + b + " es: " + bigMcd);
        System.out.println("\nEl mínimo común múltimplo entre " + a + " y " + b  + " es: " + bigMcm);
        System.out.println("\n\n");

        Despedida();
    }
}