package src.Estructura.Electronica;

import java.util.Scanner;

public class Refrigeracion 
{
    Scanner in = new Scanner(System.in);

    private boolean encendido = false;
    private float temperatura = 20;
    private String modoActual = "Aire";

    public Refrigeracion(){}

    public Refrigeracion(boolean encendido){}

    public void CambiarTemperatura(float cambio)
    {
        temperatura += cambio;
    }

    public void CambiarModo()
    {
        System.out.println("\nIngresa el modo deseado [ 0:Aire | 1:Enfriar | 2:Calentar ]");
        int modo = in.nextInt();

        switch (modo) 
        {
            case 0:
                modoActual = "Aire";
                break;
        
            case 1:
                modoActual = "Enfriar";
                break;
            
            case 2:
                modoActual = "Calentar";
                break;
        }
    }

    public float TemperaturaActual()
    {
        return temperatura;
    }

    public String ModoActual()
    {
        return modoActual;
    }

    public String EstadoActual()
    {
        String estado = encendido
            ?   "Encendido"
            :   "Apagado";

        return estado;
    }

    public void ImprimirDescripcion()
    {
        System.out.println("\nEste aire acondicionado está diseñado para proporcionar confort en diversas condiciones");
        System.out.println("climáticas. Cuenta con tres modos de operación: 'Aire', para una ventilación suave; 'Enfriar',");
        System.out.println("ideal para reducir la temperatura en días calurosos; y 'Calentar', perfecto para mantener el");
        System.out.println("ambiente cálido en invierno. Además, permite ajustar la temperatura a la medida del usuario y");
        System.out.println("controlar su estado de encendido o apagado. Con su versatilidad, es la solución perfecta para");
        System.out.println("garantizar un entorno confortable durante todo el año, adaptándose a las necesidades del");
        System.out.println("espacio y preferencias personales.");
    }
}
