/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author krizba
 */
import java.awt.*; // Abstract windows toolkit
import javax.swing.*; //GUI toolbox 3:

public class DiceGUI {
    // LOL
    //private int Num;


    private JFrame frame; // Java window
    private JPanel panel; // Container for stuff in the frame

    private final int WIDTH = 500;
    private final int HEIGHT = 100;

    private static DieDrawing[] DicePics= new DieDrawing[5];

    private static int GUIcountlol = 1;
    
        public DiceGUI(){
        // Meow
        int Num =0;
        Num = GUIcountlol;
        GUIcountlol++;
        frame = new JFrame("Yahtzee, son");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // end when x hit
        panel = new ImagePane();
        panel.setPreferredSize(new Dimension(WIDTH, HEIGHT));

        frame.getContentPane().add(panel);
        frame.pack();
        frame.setVisible(true);
        frame.setBackground(Color.gray);
        frame.setLocation((WIDTH-(500/2))+5, 10);
        DieDrawing.setFrame(frame);
            for (int x=0; x<DicePics.length; x++){
              DicePics[x] = new DieDrawing();
            }
        
        panel.repaint();
        }
        // lol overloading
        public void display(int cake, int lol){
            // Not sure if I personally need a number
            DicePics[cake].SetFace(lol);

            panel.repaint();
        }
        public void setHeld(int cake,boolean heldnow){
            DicePics[cake].setHeld(heldnow);
        }
        public void display(int cake){
            // Not sure if I personally need a number
            panel.repaint();
            
        }
        public void display(){
            // Not sure if I personally need a number
            //DicePics[cake].SetFace(lol);
            //for (int x=0; x<DicePics.length; x++){
                //DicePics[x].Draw();
            //}
            panel.repaint();

        }
        public DieDrawing sendDieDrawing(int number){

            return DicePics[number];
        }

        private class ImagePane extends JPanel{
        // Objects of this type ARE JPanels in everyway
        // expcept we will:

        //override one method

            public void paintComponent(Graphics g){
                // Paint component is automatically called by
                // the rePaint() method

                //Call the original paintcomponent for background
                super.paintComponent(g);
                
                for (int x=0; x<DicePics.length;x++){
                    DicePics[x].Draw(g);
                }
                
            }

    }
}
