import java.awt.event.*;

import src.Canvas;
import src.Window;

class Main
{
    public static void main(String[] args)
    {
        Canvas can = new Canvas();
        
        Window win = new Window(); 
        win.add(can);
    }
}