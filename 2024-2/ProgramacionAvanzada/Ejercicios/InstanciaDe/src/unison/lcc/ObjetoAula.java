package unison.lcc;

public abstract class ObjetoAula 
{
    protected String direccion, tipo;
    public String nombre;

    public void ImprimirInfo()
    {
        System.out.println("\nDireccion en memoria: " + direccion);
        System.out.println("Tipo: " + tipo + "\n");
    }
}