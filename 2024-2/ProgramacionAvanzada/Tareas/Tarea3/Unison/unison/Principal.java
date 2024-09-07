package unison;

import java.util.Scanner;

import unison.lcc.Anfitrion;
import unison.lcc.Jugador;

class Principal
{
    static Scanner in = new Scanner(System.in);

    static Anfitrion anfitrion = new Anfitrion();
    static Jugador jugador = new Jugador();

    public static void main(String[] args)
    {
        boolean seguirJugando = true;
        String respuesta;

        anfitrion.DarBienvenida();

        while (seguirJugando) 
        {
            jugador.Jugar();

            System.out.println("\n¿Deseas seguir jugando? [S: Si / N: No]");
            respuesta = RespuestaSegura((in.nextLine()).toLowerCase());

            if(respuesta.equals("s"))
            {
                seguirJugando = true;
                jugador.resultado = true;
            }
            else
            {
                seguirJugando = false;
            }
        }

        anfitrion.ImprimirDespedida();
    }

    static public String RespuestaSegura(String respuesta)
    {
        if(!(respuesta.equals("s")) && !(respuesta.equals("n"))) 
        {
            while (!(respuesta.equals("s")) && !(respuesta.equals("n"))) 
            {
                // System.out.println("Respondiste: " + respuesta);
                System.out.println("\nIngresaste un valor incorrecto");
                System.out.println("¿Deseas seguir jugando? [S: Si / N: No]"); 
                respuesta = (in.nextLine()).toLowerCase();
            }
        }

        return respuesta;
    }
}