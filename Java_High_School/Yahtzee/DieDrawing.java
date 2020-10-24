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

public class DieDrawing {
    final int sideWidth = 15;
    private int Face;
    private boolean Held = false;
    private int startX;
    private int startY;
    final int SCALE = 2;

    private int Num;
    //private Graphics page;
    private static JFrame Window;

    private static int made = 1;
    

    public DieDrawing(){

        Num = made;
        //System.out.println("Created die picture: " + made);
        made++;

        startX = (2*sideWidth)*made*SCALE; // Horiziontal
        // Space it
        startY = sideWidth*SCALE;
        
        
    }
    public int Id(){
        return Num;
    }
    public static void setFrame(JFrame lol){
        Window = lol;
        // meow
    }
    public int getFace(){
        return Face;
    }

    public void setHeld(boolean heldrightnow){
        Held = heldrightnow;
    }
    public void SetFace(int dienum){
        // Called from die
        Face = dienum;

        
    }
    public void Draw(Graphics page){
        //
        // These will use the page
        // To draw ovals n shit
        
        int dienum = Face;
        
        page.drawRect(startX, startY, sideWidth, sideWidth);
        if (Held) {page.setColor(Color.gray);} else {page.setColor(Color.black);}
        
        // 
        int Height = 3, Width = 3;
        int leftx = startX + 2;
        int rightx = startX +10;
        int centerx = startX + (sideWidth/2)-(Width/2);

        int lowy = startY + 10;
        int highy = startY + 2;
        int centery = startY + (sideWidth/2)-(Height/2);

        
        
        //if (dienum == null) {System.out.println("!![ERROR]!! dienum is NULL in Draw");}

        if (dienum == 1){
            page.drawOval(centerx, centery, Height, Width); // Center

        }else if (dienum == 2){
            page.drawOval(leftx, highy, Height, Width); // Upper Left
            page.drawOval(rightx, lowy, Height, Width); // Lower Right
        }else if (dienum == 3){
            page.drawOval(centerx, centery, Height, Width); // Center
            
            page.drawOval(leftx, highy, Height, Width); // Upper Left
            page.drawOval(rightx, lowy, Height, Width); // Lower Right
        }else if (dienum == 4){
            page.drawOval(leftx, highy, Height, Width); // Upper Left
            page.drawOval(rightx, highy, Height, Width); // Upper Right

            page.drawOval(leftx, lowy, Height, Width); // Lower Left
            page.drawOval(rightx, lowy, Height, Width); // Lower Right
        }else if (dienum == 5){
            page.drawOval(centerx, centery, Height, Width); // Center

            page.drawOval(leftx, highy, Height, Width); // Upper Left
            page.drawOval(rightx, highy, Height, Width); // Upper Right

            page.drawOval(leftx, lowy, Height, Width); // Lower Left
            page.drawOval(rightx, lowy, Height, Width); // Lower Right
        }else if (dienum == 6){
            page.drawOval(leftx, highy, Height, Width); // Upper Left
            page.drawOval(rightx, highy, Height, Width); // Upper Right

            page.drawOval(leftx, lowy, Height, Width); // Lower Left
            page.drawOval(rightx, lowy, Height, Width); // Lower Right


            page.drawOval(leftx, centery, Height, Width); // Center Left
            page.drawOval(rightx, centery, Height, Width); // Center Right
        }
        
    }
        

}
