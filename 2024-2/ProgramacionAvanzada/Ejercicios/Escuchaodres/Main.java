import javax.management.ListenerNotFoundException;
import javax.swing.JFrame;

public class Main 
{
    public static void main(String[] args)    
    {
        JFrame ven = new JFrame();
        ven.setSize(1080, 720);
        ven.setVisible(true);
        ven.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Listener mylListener = new Listener();

        ven.addMouseListener(mylListener);
    }
}
