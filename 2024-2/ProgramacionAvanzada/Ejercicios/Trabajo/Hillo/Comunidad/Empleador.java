package Hillo.Comunidad;

public class Empleador
{
    String direccion;

    public void establecerDireccion(String d)
    {
        direccion = d;
    }

    public String obtenerDireccion()
    {
        return this.direccion;
    }
}