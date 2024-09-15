package unison.lcc;

public abstract class Electronico extends ObjetoAula
{
    public Electronico()
    {
        this.direccion = this.toString();
        this.tipo = "Electronico inanimado";
    }
}