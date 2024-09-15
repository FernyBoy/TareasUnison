package Estructura;

import java.util.Random;

public class Dado 
{
    Random random = new Random();

    int valorActual;

    public Dado(){}

    public Dado(int num){}

    public Dado(int num1, int num2){}

    public Dado(String[] args){}

    public String lanzar()
    {
        int num = (random.nextInt(6)) + 1;

        valorActual = num;

        System.out.println("Ha caído el número " + leerValor(num));

        return leerValor(num);
    }

    public void obtenerValor()
    {
        System.out.println("\nValor actual del dado: " + leerValor(valorActual));
    }

    public String leerValor(int num)
    {
        String valor = "";

        switch (num) {
            case 1:
                valor = "Uno";
                break;
        
            case 2:
                valor = "Dos";
                break;

            case 3:
                valor = "Tres";
                break;

            case 4:
                valor = "Cuatro";
                break;

            case 5:
                valor = "Cinco";
                break;

            case 6:
                valor = "Seis";
                break;
        }

        return valor;
    }
}
