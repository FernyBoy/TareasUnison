package unison.lcc;

import java.util.Scanner;

// Le pide al usuario que adivine el valor aleatorio, valida los valores e informa el resultado.
// Niveles alcanzables: Excelente <= (Intentos + I/4), Bueno <= (I + I/2), Regular > (I + I/2)
public class Jugador
{
    Scanner in = new Scanner(System.in);

    Anfitrion anfitrion = new Anfitrion();
    Generador generador = new Generador();

    private int intentos = 0, valorUsuario;
    public boolean resultado = true;
    private String bajarSubir, frioCaliente, categoria;

    public void Jugar()
    {
        generador.Generar();
        
        while (resultado) 
        {
            PedirValor();
            InformarResultado(valorUsuario);
            intentos++;    
        }
    }

    private void PedirValor()
    {
        System.out.println("Ingresa un valor para adivinar el numero:");
        valorUsuario = RespuestaSegura(in.nextInt());
    }

    private int RespuestaSegura(int valorUsuario)
    {
        if((valorUsuario < generador.min) || (valorUsuario > generador.max)) 
        {
            while ((valorUsuario < generador.min) || (valorUsuario > generador.max)) 
            {
                System.out.println("\nHas ingresado un valor fuera del limite");
                System.out.println("Ingresa valores entre " + generador.min + " y " + generador.max + "."); 
                valorUsuario = in.nextInt();
            }
        }

        return valorUsuario;
    }

    private void InformarResultado(int valorUsuario)
    {
        if(valorUsuario != generador.rand)
        {
            bajarSubir = BajarSubir(valorUsuario);
            frioCaliente = FrioCaliente(valorUsuario);

            System.out.println("\n" + frioCaliente + bajarSubir + " Adivina el resultado entre " + generador.min + " y " + generador.max + ":");
            resultado = true;
        }
        else if(valorUsuario == generador.rand)
        {
            GenerarCategoria();

            System.out.println("\nADIVINASTE!");
            System.out.println("FELICIDADES te encuentras entre los participantes " + categoria);

            intentos = 0;
            resultado = false;
        }
    }

    private String BajarSubir(int valorUsuario)
    {
        String respuesta = "";

        if(valorUsuario < generador.rand) 
        {
            respuesta = "Subele!";
        }
        else if (valorUsuario > generador.rand)
        {
            respuesta = "Bajale!";
        }

        return respuesta;
    }

    private String FrioCaliente(int valorUsuario)
    {
        String respuesta = "";

        if((valorUsuario >= generador.minimoCercano) || (valorUsuario <= generador.maximoCercano)) 
        {
            respuesta = "Caliente, caliente! ";
        }
        else
        {
            respuesta = "Frio, frio! ";
        }

        return respuesta;
    }

    private void GenerarCategoria()
    {
        // Niveles alcanzables: Excelente <= (Intentos + I/4), Bueno <= (I + I/2), Regular > (I + I/2)
        if(intentos <= (generador.minimoIntentos + (generador.minimoIntentos / 4)))
        {
            categoria = "EXCELENTES!";
        }
        else if(intentos <= (generador.minimoIntentos + (generador.minimoIntentos / 2)))
        {
            categoria = "BUENOS!";
        }
        else if(intentos > (generador.minimoIntentos + generador.minimoIntentos / 2))
        {
            categoria = "REGULARES!";
        }
    }
}
