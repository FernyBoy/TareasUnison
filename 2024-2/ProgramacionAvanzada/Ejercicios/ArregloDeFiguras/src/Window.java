package src;
import javax.swing.JFrame;
import java.awt.*;

public class Window extends JFrame
{
    private java.awt.Dimension Screen = Toolkit.getDefaultToolkit().getScreenSize();
    private int height = (int) Screen.getHeight();
    private int width = (int) Screen.getWidth();

    public Window()
    {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        this.setSize(this.width, this.height);
    }
}
