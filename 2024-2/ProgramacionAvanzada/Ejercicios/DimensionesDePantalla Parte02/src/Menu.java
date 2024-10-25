
import java.awt.Toolkit;
import javax.swing.JFrame;

public class Menu extends javax.swing.JFrame 
{
    public Menu() 
    {
        initComponents();
    }

    @SuppressWarnings("unchecked")

    private void initComponents() 
    {
        Menu = new javax.swing.JMenuBar();
        Archivo = new javax.swing.JMenu();
        Nuevo = new javax.swing.JMenuItem();
        Abrir = new javax.swing.JMenuItem();
        Guardar = new javax.swing.JMenuItem();
        Salir = new javax.swing.JMenuItem();
        Edicion = new javax.swing.JMenu();
        Copiar = new javax.swing.JMenuItem();
        Pegar = new javax.swing.JMenuItem();
        Deshacer = new javax.swing.JMenuItem();
        Rehacer = new javax.swing.JMenuItem();
        Vista = new javax.swing.JMenu();
        Vista100 = new javax.swing.JMenuItem();
        Vista75 = new javax.swing.JMenuItem();
        Vista50 = new javax.swing.JMenuItem();
        Vista25 = new javax.swing.JMenuItem();
        Ayuda = new javax.swing.JMenu();
        AcercaDe = new javax.swing.JMenuItem();
        Creditos = new javax.swing.JMenuItem();
        Manual = new javax.swing.JMenuItem();
        Pantalla = Toolkit.getDefaultToolkit().getScreenSize();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        Archivo.setText("Archivo");

        Nuevo.setText("Nuevo");
        Nuevo.addMenuDragMouseListener(new javax.swing.event.MenuDragMouseListener() 
        {
            public void menuDragMouseDragged(javax.swing.event.MenuDragMouseEvent evt) 
            {
                NuevoMenuDragMouseDragged(evt);
            }

            public void menuDragMouseEntered(javax.swing.event.MenuDragMouseEvent evt) {}

            public void menuDragMouseExited(javax.swing.event.MenuDragMouseEvent evt) {}

            public void menuDragMouseReleased(javax.swing.event.MenuDragMouseEvent evt) {}
        });
        
        Nuevo.addActionListener(new java.awt.event.ActionListener() 
        {
            public void actionPerformed(java.awt.event.ActionEvent evt) 
            {
                NuevoActionPerformed(evt);
            }
        });
        Archivo.add(Nuevo);

        Abrir.setText("Abrir");
        Archivo.add(Abrir);

        Guardar.setText("Guardar");
        Guardar.addActionListener(new java.awt.event.ActionListener() 
        {
            public void actionPerformed(java.awt.event.ActionEvent evt) 
            {
                GuardarActionPerformed(evt);
            }
        });
        Archivo.add(Guardar);

        Salir.setText("Salir");
        Salir.addActionListener(new java.awt.event.ActionListener() 
        {
            public void actionPerformed(java.awt.event.ActionEvent evt) 
            {
                SalirActionPerformed(evt);
            }
        });
        Archivo.add(Salir);

        Menu.add(Archivo);

        Edicion.setText("Edición");

        Copiar.setText("Copiar");
        Copiar.addActionListener(new java.awt.event.ActionListener() 
        {
            public void actionPerformed(java.awt.event.ActionEvent evt) 
            {
                CopiarActionPerformed(evt);
            }
        });
        Edicion.add(Copiar);

        Pegar.setText("Pegar");
        Edicion.add(Pegar);

        Deshacer.setText("Deshacer");
        Edicion.add(Deshacer);

        Rehacer.setText("Rehacer");
        Edicion.add(Rehacer);

        Vista.setText("Vista");

        Vista100.setText("100%");
        Vista100.addActionListener(new java.awt.event.ActionListener() 
        {
            public void actionPerformed(java.awt.event.ActionEvent evt) 
            {
                Vista100ActionPerformed(evt);
            }
        });
        Vista.add(Vista100);

        Vista75.setText("75%");
        Vista75.addActionListener(new java.awt.event.ActionListener() 
        {
            public void actionPerformed(java.awt.event.ActionEvent evt) 
            {
                Vista75ActionPerformed(evt);
            }
        });
        Vista.add(Vista75);

        Vista50.setText("50%");
        Vista50.addActionListener(new java.awt.event.ActionListener() 
        {
            public void actionPerformed(java.awt.event.ActionEvent evt) 
            {
                Vista50ActionPerformed(evt);
            }
        });
        Vista.add(Vista50);

        Vista25.setText("25%");
        Vista25.addActionListener(new java.awt.event.ActionListener() 
        {
            public void actionPerformed(java.awt.event.ActionEvent evt) 
            {
                Vista25ActionPerformed(evt);
            }
        });
        Vista.add(Vista25);

        Edicion.add(Vista);

        Menu.add(Edicion);

        Ayuda.setText("Ayuda");

        AcercaDe.setText("Acerca de...");

        AcercaDe.addActionListener(new java.awt.event.ActionListener() 
        {
            public void actionPerformed(java.awt.event.ActionEvent evt) 
            {
                AcercaDeActionPerformed(evt);
            }
        });
        Ayuda.add(AcercaDe);

        Creditos.setText("Créditos");

        Creditos.addActionListener(new java.awt.event.ActionListener() 
        {
            public void actionPerformed(java.awt.event.ActionEvent evt) 
            {
                CreditosActionPerformed(evt);
            }
        });

        Ayuda.add(Creditos);

        Manual.setText("Manual");

        Ayuda.add(Manual);

        Menu.add(Ayuda);

        setJMenuBar(Menu);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());

        getContentPane().setLayout(layout);

        layout.setHorizontalGroup
        (
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING).addGap(0, 400, Short.MAX_VALUE)
        );

        layout.setVerticalGroup
        (
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING).addGap(0, 277, Short.MAX_VALUE)
        );

        pack();
    }

    private void NuevoActionPerformed(java.awt.event.ActionEvent evt) {}

    private void NuevoMenuDragMouseDragged(javax.swing.event.MenuDragMouseEvent evt) {}

    private void GuardarActionPerformed(java.awt.event.ActionEvent evt) {}

    private void CopiarActionPerformed(java.awt.event.ActionEvent evt) {}

    private void Vista100ActionPerformed(java.awt.event.ActionEvent evt) 
    {
        this.setExtendedState(JFrame.MAXIMIZED_BOTH);
    }

    private void Vista75ActionPerformed(java.awt.event.ActionEvent evt) 
    {
        this.setSize(((int) (Pantalla.width * 0.75)), ((int) (Pantalla.height * 0.75)));
    }

    private void Vista50ActionPerformed(java.awt.event.ActionEvent evt) 
    {
        this.setSize(((int) (Pantalla.width * 0.5)), ((int) (Pantalla.height * 0.5)));
    }

    private void Vista25ActionPerformed(java.awt.event.ActionEvent evt) 
    {
        this.setSize(((int) (Pantalla.width * 0.25)), ((int) (Pantalla.height * 0.25)));
    }

    private void AcercaDeActionPerformed(java.awt.event.ActionEvent evt) {}

    private void CreditosActionPerformed(java.awt.event.ActionEvent evt) {}

    private void SalirActionPerformed(java.awt.event.ActionEvent evt) 
    {
        System.exit(0);
    }

    public static void main(String args[]) 
    {
        try 
        {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels())
            {
                if ("Nimbus".equals(info.getName())){
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        
        java.awt.EventQueue.invokeLater(new Runnable() 
        {
            public void run() 
            {
                new Menu().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuItem Abrir;
    private javax.swing.JMenuItem AcercaDe;
    private javax.swing.JMenu Archivo;
    private javax.swing.JMenu Ayuda;
    private javax.swing.JMenuItem Copiar;
    private javax.swing.JMenuItem Creditos;
    private javax.swing.JMenuItem Deshacer;
    private javax.swing.JMenu Edicion;
    private javax.swing.JMenuItem Guardar;
    private javax.swing.JMenuItem Manual;
    private javax.swing.JMenuBar Menu;
    private javax.swing.JMenuItem Nuevo;
    private javax.swing.JMenuItem Pegar;
    private javax.swing.JMenuItem Rehacer;
    private javax.swing.JMenuItem Salir;
    private javax.swing.JMenu Vista;
    private javax.swing.JMenuItem Vista100;
    private javax.swing.JMenuItem Vista25;
    private javax.swing.JMenuItem Vista50;
    private javax.swing.JMenuItem Vista75;
    private java.awt.Dimension Pantalla;
    // End of variables declaration//GEN-END:variables
}
