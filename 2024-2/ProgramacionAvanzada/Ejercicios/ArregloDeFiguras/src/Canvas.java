package src;
import javax.swing.JPanel;
import java.awt.Graphics;
import java.awt.Color;
import java.awt.event.*;
import java.awt.Toolkit;


public class Canvas extends JPanel
{
    Figures fig = new Figures();

    public Canvas()
    {
        this.addMouseListener(new MouseAdapter()
        {
            @Override
            public void mousePressed(MouseEvent me)
            {
                fig.GenerateFigure();
                repaint();
            }
        });
    }
    
    @Override
    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);

        for(int i = 0; i < fig.figures.length; i++)
        {
            g.setColor(new Color((int)(Math.random() * 256), (int)(Math.random() * 256), (int)(Math.random() * 256)));
            g.fillRect(fig.figures[i][0], fig.figures[i][1], fig.figures[i][2], fig.figures[i][3]);
        }
    }
}
