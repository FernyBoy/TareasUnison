package unison.lcc;

public abstract class Persona extends ObjetoAula
{
    public Persona()
    {
        this.direccion = this.toString();
        this.tipo = "Persona";
    }
}
