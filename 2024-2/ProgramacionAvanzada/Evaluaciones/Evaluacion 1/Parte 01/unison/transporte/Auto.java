package unison.transporte;

public class Auto
{
    String brand;
    int year;

    public Auto(String brand, int year)
    {
        this.brand = brand;
        this.year = year;
    }

    public String obtenerDatosAuto()
    {
        String datos = "\n - Marca: " + this.brand + "\n - Año: " + this.year; 
        return  datos;
    }
}
