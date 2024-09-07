import src.Estructura.Electronica.*;

class Principal
{
	static Refrigeracion refrigeracion = new Refrigeracion(true);

	public static void main(String[] args)
	{
		refrigeracion.CambiarTemperatura(-3);
		refrigeracion.CambiarModo();

		System.out.println("\nTemperatura actual: " + refrigeracion.TemperaturaActual() + "°C");
		System.out.println("Modo actual: " + refrigeracion.ModoActual());
		System.out.println("Estado actual: " + refrigeracion.EstadoActual());

		refrigeracion.ImprimirDescripcion();
	}
}
