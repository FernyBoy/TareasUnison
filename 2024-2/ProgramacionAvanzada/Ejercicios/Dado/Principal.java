import Estructura.Dado;

class Principal
{
    static Dado dado = new Dado();

    public static void main(String[] args)
    {
        for(int i = 0; i < 10; i++)
        {
            dado.lanzar();    
        }

        dado.obtenerValor();
    }
}