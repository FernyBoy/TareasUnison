import unison.lcc.*;
import unison.lcc.Personas.*;
import unison.lcc.Muebles.*;
import unison.lcc.Electronicos.*;
import unison.lcc.Articulos.*;

import java.util.Random;

public class Principal 
{
    private static Random generar = new Random();

    private static int N = 100;
    private static ObjetoAula[] Objetos = new ObjetoAula[N];
    private static int[] Frecuencia = new int[17];

    public static void main(String[] args)
    {
        for(int i = 0; i < N; i++)
        {
            Objetos[i] = CrearObjeto();
            Objetos[i].ImprimirInfo();
        }

        ImprimirFrecuencias();
    }

    private static ObjetoAula CrearObjeto()
    {
        int random = generar.nextInt(17);
        Frecuencia[random]++;

        switch(random) 
        {
            case 0: 
                return new Mesa(){};
        
            case 1: 
                return new Pizarron(){};

            case 2:
                return new Puerta(){};
                
            case 3:
                return new SillaOficina(){};
                
            case 4:
                return new Estudiante(){};
                
            case 5:
                return new Profesor(){};
                
            case 6:
                return new Bocina(){};

            case 7:
                return new CajaFusible(){};
                
            case 8:
                return new Computadora(){};
                
            case 9:
                return new Lampara(){};
                
            case 10:
                return new Monitor(){};
                
            case 11:
                return new Mouse(){};
                
            case 12:
                return new Proyector(){};
            
            case 13:
                return new Teclado(){};
                
            case 14:
                return new Extintor(){};
                
            case 15:
                return new Marcador(){};
                
            case 16:
                return new Taza(){};
                
        }
        return null;
    }

    public static void ImprimirFrecuencias()
    {
        for(int i = 0; i < 17; i++)
        {
            System.out.println(Objetos[i].nombre + ": " + CalcularFrecuencias(Frecuencia[i]));
        }
    }

    public static String CalcularFrecuencias(int f)
    {
        String frecuencia = "";

        for(int i = 0; i < f; i++)
        {
            frecuencia += "X";
        }

        return frecuencia;
    }
}
