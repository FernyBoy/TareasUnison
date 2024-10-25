import unison.lcc.persona.Usuario;
/**
 * Este programa se encarga de manipular entradas (consola, grafica) y
 * salidas (consola y gráficas) de datos. 
 * Para el caso de "textual" todo se debe hacer con la clase Scanner.
 * Para el caso de "gráfica" todo se debe hacer con la clase JOptionPane.
 * */
public class Principal{
	public static void main(String arg[]){
		//El usuario debe proporcionar si desea en interactuar en forma "textual" o "grafica"
		//y crear un usuario con esa informacion.
		Usuario usuario = new Usuario( arg[0] );
		
		//Preguntar al usuario por su numero favorito
		usuario.preguntarNumeroFavorito();
		
		//preguntar cuantos numeros desea que se generen al azar [100 y 999]
		int n = Usuario.preguntarCantidadNumeros();
		
		//generar n dígitos (los que dijo el usuario), es decir numeros entre 0 y 9, inclusivos
		//y contar cuantas veces se genera  el número del usuario.
		//publicar la cantidad de veces que se generó
		usuario.imprimirFrecuencia( usuario.generarNumerosAzar( n ) );
	}
}