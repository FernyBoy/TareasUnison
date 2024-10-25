import unison.lcc.Fraction;

class main
{
    public static void main(String[] args)
    {
        for(int i = 0; i < 20; i++)
        {
            Fraction f1 = new Fraction();
            Fraction f2 = new Fraction();
            Fraction suma = new Fraction(f1, f2);

            System.out.println(f1.numerador + "/" + f1.denominador + " + " + f2.numerador + "/" + f2.denominador + " = " + suma.numerador + "/" + suma.denominador);
        }
    }   
}