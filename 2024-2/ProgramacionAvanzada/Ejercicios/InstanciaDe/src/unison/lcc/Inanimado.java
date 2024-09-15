package unison.lcc;

public abstract class Inanimado extends ObjetoAula
{
    public Inanimado()
    {
        this.direccion = this.toString();
        this.tipo = "Inanimado";
    }
}
