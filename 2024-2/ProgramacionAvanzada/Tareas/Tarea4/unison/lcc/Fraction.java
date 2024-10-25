package unison.lcc;

import java.util.Random;

public class Fraction 
{
    Random rand = new Random();

    public int numerador, denominador;

    public Fraction()
    {
        numerador = rand.nextInt(9);
        denominador = rand.nextInt(8) + 1; 
    }

    public Fraction(Fraction f1, Fraction f2)
    {
        if(f1.numerador == 0 && f2.numerador == 0)
        {
            numerador = 0;
            denominador = 0;
        }
        else if(f1.numerador == 0)
        {
            numerador = f2.numerador;
            denominador = f2.denominador;
        }
        else if(f2.numerador == 0)
        {
            numerador = f1.numerador;
            denominador = f1.denominador;
        }
        else if(f1.denominador == f2.denominador)
        {
            numerador = f1.numerador + f2.numerador;
            denominador = f1.denominador;
        }
        else
        {
            int mcd = MCD(f1.denominador, f2.denominador);
            if(mcd == f1.denominador)
            {
                numerador = f1.numerador * (f2.denominador / f1.denominador) + f2.numerador;
                denominador = f2.denominador;
            }
            else if(mcd == f2.denominador)
            {
                numerador = f2.numerador * (f1.denominador / f2.denominador) + f1.numerador;
                denominador = f1.denominador;
            }
            else if(mcd == 1)
            {
                denominador = f1.denominador * f2.denominador;
                numerador = (f1.numerador * f2.denominador) + (f2.numerador * f1.denominador); 
            }
        }

        int mcd = MCD(numerador, denominador);
        numerador = numerador / mcd;
        denominador = denominador / mcd;
    }

    private int MCD(int a, int b)
    {
        while(b != 0)
        {
            int c = b;
            b = a % b;
            a = c;
        }

        return a;
    }
}
