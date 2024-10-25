package unison.lcc.persona;

import unison.transporte.Auto;

public class Chofer 
{
    String name = "No se ha proporcionado un nombre.";
    Auto auto;

    public Chofer(String name)
    {
        this.name = name;
    }

    public void asignarAuto(Auto auto)
    {
        this.auto = auto;
    }

    public void imprimirDatosPersonales()
    {
        System.out.print("Nombre: " + this.name);
    }

    public void imprimirDatosAutomovil()
    {
        String info = this.auto.obtenerDatosAuto();
        System.out.print(info);
    }
}
