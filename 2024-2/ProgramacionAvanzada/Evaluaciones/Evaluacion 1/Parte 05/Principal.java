import unison.gui.MiLienzo;
/**
 * Este programa se encarga de manipular una ventana gráfica.
 * Se debe desplegar la famosa "carita feliZ", originalmente creada en Worcester, EUA.
 * Entre las caracteristicas destacan:
 * Utiliza el color amarillo.
 * La cara se representa con un circulo perfecto.
 * Los ojos son pequeños, el derecho mas grande que el izquierdo, entre otros elementos.
 * 
 * En este trabajo los ojos y la boca deben cambiar aleatoriamente el color, pero siempre
 * debe ser el mismo para ambos.
 */
public class Principal{
	public static void main(String arg[]){
		//Creacion de una ventana gráfica de cierto tamaño e inicialmente ubicada en la 
		//parte central de la pantalla (aproximadamente, no tiene que ser exacto).
		unison.gui.MiVentana miVentanita = new unison.gui.MiVentana();

		//Dicha ventana debe contener al menos un contenedor para dibujar que extienda de JPanel
		
		MiLienzo lienzo = new MiLienzo();
		miVentanita.add(lienzo);
		miVentanita.setVisible(true);

		//Al desplegar la ventana por primera vez, se debe dibujar una carita feliz en la pantalla
		//esto es, un circulo perfecto amarillo, unos ojos negros (ovalados, el ojo derecho ligeramente
		//mas grande que el izquierdo) y sonriendo.
		//Para esto, se sugiere sobreescribir el metodo paint de la clase MiLienzo.

		//al momento de modificar la venta, ya sea minimizando o cambiando de tamaño,
		//el programa debe volver a dibujar la carita feliz, pero cambiando al azar el color
		//de los ojos y la boca (el color debe ser el mismo para ambos elementos).
	}
}