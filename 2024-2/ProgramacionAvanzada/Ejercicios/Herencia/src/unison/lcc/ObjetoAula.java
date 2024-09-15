package unison.lcc;

public abstract class ObjetoAula 
{
    String direccion, tipo;

    public void ImprimirInfo()
    {
        System.out.println("\n\nDireccion en memoria: " + direccion);
        System.out.println("Tipo: " + tipo);
    }
}