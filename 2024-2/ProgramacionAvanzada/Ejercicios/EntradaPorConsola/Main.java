public class Main
{
    public static void main(String[] args)
    {
        try
        {
            int nacido = Integer.parseInt(args[1]);
            int tiempoDeLucha = Integer.parseInt(args[2]);

            System.out.println(
                "Datos del usuario: \nDon "
                + args[0] + " nacido en " + nacido
                + " tiene " + tiempoDeLucha + " años de lucha."
            );

        }
        catch(ArrayIndexOutOfBoundsException err)
        {
            System.out.println("No se han ingresado todos los datos.");
        }
        catch(NumberFormatException err)
        {
            System.out.println("Algun numero se ha ingresado de manera incorrecta.");
        }
        catch(Exception err)
        {
            System.out.println("Excepcion desconocida.");
        }
        finally
        {
            
        }
    }
}