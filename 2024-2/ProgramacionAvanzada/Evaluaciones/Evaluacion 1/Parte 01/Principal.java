import unison.transporte.Auto;
import unison.lcc.persona.Chofer;

public class Principal
{
	public static void main(String arreglo[])
	{
		unison.lcc.Anfitrion.darBienvenida();

		Auto auto01 = new Auto("Chevrolet", 2016);

		Chofer chofer01 = new Chofer( arreglo[1] );

		chofer01.asignarAuto( auto01 );

		chofer01.imprimirDatosPersonales();

		System.out.println( "\nAuto: " + auto01.obtenerDatosAuto() );

		chofer01.imprimirDatosAutomovil();

		unison.lcc.Anfitrion.darDespedida();
	}
}