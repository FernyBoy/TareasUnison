package unison.gui;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.Graphics;
import java.awt.Color;

public class MiLienzo extends javax.swing.JPanel
{
    public MiLienzo(){}
    
    @Override
    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);

        int ancho = getWidth();
        int alto = getHeight();
        
        g.setColor(Color.YELLOW);
        g.fillOval(0, 0, ancho, ancho);

        g.setColor(Color.BLACK);
        g.fillOval(((ancho / 7) * 2), (alto / 7), 50, 100);
        g.fillOval(((ancho / 7) * 4), (alto / 7), 50, 150);
         
        g.fillArc(((ancho / 7) * 2), ((alto / 7) * 5), 300, 150, 180, 360);
    }

}
