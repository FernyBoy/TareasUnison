import java.awt.event.*;

public class Listener implements java.awt.event.MouseListener
{
    public void mouseExited(MouseEvent me)
    {
        System.out.print("\nEl mouse ha salido");
    }    

    public void mouseEntered(MouseEvent me)
    {
        System.out.print("\nEl mouse ha entrado");
    }

    public void mousePressed(MouseEvent me)
    {
        System.out.print("\nEl mouse ha sido presionado");
    }

    public void mouseReleased(MouseEvent me)
    {
        System.out.print("\nEl boton del mouse ha sido soltado");
    }

    public void mouseClicked(MouseEvent me)
    {
        System.out.print("\nEl boton del mouse ha sido presionado");
    }
}
