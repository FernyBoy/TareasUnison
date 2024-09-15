import java.util.Scanner;

class Brocha
{
    public static void SacarBrocha()
    {

    }

    public static void MojarBrocha()
    {

    }

    public static void Pintar()
    {

    }

    public static void LavarBrocha()
    {

    }
}

class Pintura
{
    private static String[] colores = 
    {
        "Rojo", 
        "Azul", 
        "Verde", 
        "Negro", 
        "Blanco",
    };

    public static String colorParaUsar;

    public static void ElegirColor()
    {
        Scanner in = new Scanner(System.in);

        System.out.println("Escoge uno de los siguientes colores:");
        for(int i = 0; i < colores.length; i++)
        {
            System.out.println((i + 1) + ". " + colores[i]);
        }
        System.out.println("\n");

        int respuesta = in.nextInt();

        while(respuesta < 1 || respuesta > 5) 
        {
            System.out.println("Escoge una respuesta valida");
            respuesta = in.nextInt();
        }

        respuesta = respuesta - 1;
        
        colorParaUsar = colores[respuesta];
        System.out.println("Has escogido el color " + colores[respuesta]);
    }

    public static void SacarPintura()
    {
        
    }
}

class Flexometro
{
    public static void SacarFlexo()
    {

    }

    private static void MedirAlto()
    {

    }

    private static void MedirAncho()
    {

    }

    public static void MedirDimensiones()
    {

    }

    public static void GuardarFlexo()
    {

    }
}

class Escalera
{
    public static void SacarEscalera()
    {

    }

    public static void ColocarEscalera()
    {

    }

    public static void SubirEscalera()
    {

    }

    public static void BajarEscalera()
    {
        
    }

    public static void GuardarEscalera()
    {

    }
}

class Periodico
{
    public static void SacarPeriodico()
    {

    }

    public static void ColorcarPeriodico()
    {

    }

    public static void TirarPeriodico()
    {

    }
}

class Escoba
{
    public static void SacarEscoba()
    {

    }

    public static void Barrer()
    {

    }

    public static void GuardarEscoba()
    {

    }
}

class Pared
{

}

class Pintar
{
    public static void main(String[] args)
    {
        Pintura pintura = new Pintura();
        pintura.ElegirColor();
    }
}