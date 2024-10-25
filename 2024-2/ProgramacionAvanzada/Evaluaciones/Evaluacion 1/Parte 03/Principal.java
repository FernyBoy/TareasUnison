import java.util.ArrayList;
import unison.util.Vehiculo;
/**
 * Este programa se encarga de manipular un arreglo dinámico.
 * Los elementos del arreglo dinámico son objetos heredados de la Clase Abstracta: Vehiculo.
 * Las clases que heredan a Vehiculo son: Bicicleta, Tractor.
 * 
 * Inicialmente, el usuario propociona una cadena de caracteres, exclusivamente vocales y consonantes.
 * Se descompone la cadena en un arreglo de caracteres el cual debe ser recorrido.
 * Durante el recorrido, si se obtiene una vocal, se crea un objeto tipo Bicicleta (la cual debe tener la vocal, 
 * y el modelo de la misma siendo un valor desde 1817 que se crea la primer bicicleta, hasta el año de hoy), posteriormente se agrega al arreglo.
 * Si se obtiene una consonante, se crea un objeto tipo Tractor (dicho objeto debe tener la consonante y el modelo del mismo,
 * el cual debe ser un valor generando al azar, desde 1917 que se crea el primer tractor, hasta el año de hoy)  y se agrega al arreglo.
 * 
 * Despues de culminar el recorrido, se imprimen los elementos por categoria (primero las bicicletas y despues los tractores,
 * o viceversa, al gusto del programador), en cada impresión indicar, el tipo de objeto, la letra de la cadena y el modelo del mismo.
 * 
 */
public class Principal{
	public static void main(String arg[]){
		//conversion de la cadena a caracteres
		char[] arregloCaracteres = arg[0].toCharArray();
		//creación del arreglo dinámico
		ArrayList<Vehiculo> bodega = new ArrayList<Vehiculo>();
		
		//recorrer la cadena para crear los objetos.
		//for(int i=0; i<arregloCaracteres.length; i++){
			//bodega.add(Vehiculo.crearObjeto( arregloCaracteres[i]) );
		//}
		//El siguiente for (modo compacto) hace exactamente lo mismo que el for anterior (modo extenso)
		for(char c: arregloCaracteres){
			bodega.add(Vehiculo.crearObjeto( c ) );
		}

		//Enviar el arreglo para imprimir los elementos
		Vehiculo.imprimir( bodega );
	}
}