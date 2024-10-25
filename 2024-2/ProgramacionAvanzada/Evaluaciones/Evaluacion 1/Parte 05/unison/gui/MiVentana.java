package unison.gui;

import java.awt.Toolkit;

import javax.swing.JFrame;

public class MiVentana extends javax.swing.JFrame
{
    private java.awt.Dimension Pantalla = Toolkit.getDefaultToolkit().getScreenSize();;
    private int alto = Pantalla.height / 2;
    private int ancho = this.alto;
    private int x = (Pantalla.width - this.ancho) / 2;
    private int y = (Pantalla.height - this.alto) / 2;

    public MiVentana() 
    {
        initComponents();
    }

    public void initComponents()
    {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        this.setSize(this.ancho, this.alto);
        this.setLocation(this.x, this.y);
    }
}
