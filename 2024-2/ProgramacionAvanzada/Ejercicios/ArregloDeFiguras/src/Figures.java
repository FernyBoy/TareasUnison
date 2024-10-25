package src;
import java.awt.Toolkit;

public class Figures 
{
    private java.awt.Dimension Screen = Toolkit.getDefaultToolkit().getScreenSize();
    int width = (int) Screen.getWidth();
    int height = (int) Screen.getHeight();

    int n = 50;
    int[][] figures = new int[n][4];

    public Figures(){}

    public void GenerateFigure()
    {
        for(int i = 0; i < n; i++)
        {
            figures[i][0] = (int) (Math.random() * this.width);
            figures[i][1] = (int) (Math.random() * this.height);
            figures[i][2] = (int) (Math.random() * 200);
            figures[i][3] = (int) (Math.random() * 100);
        }
    }
}
