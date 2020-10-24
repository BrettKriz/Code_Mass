/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author krizba
 */
import java.lang.Math;
import java.util.Random;
import java.util.Scanner;

public class Die {
    private boolean Useable;
    private Integer VisableFace;

    private DieDrawing ChildDisplay = new DieDrawing();

    static  Random r = new Random();  //Calls constructor
    static  Scanner scan = new Scanner(System.in); //Setup keyboard input
    // Accumulate a count of how many have been made
    private static int loldiecount = 1;
    private int Num;

    public Die(DieDrawing Child){
        // Initialize
        Useable = true;
        
        ChildDisplay = Child;
        Num = loldiecount;
        System.out.println("Created die number: " + loldiecount + " with die drawing #:" + ChildDisplay.Id());

        loldiecount++;

        Roll();
        
         
    }

    public void Roll(){
        // Roll the dice lol
        if (Useable == true) {
            setFace( 1+(r.nextInt(5)) );
        }else{
            // Moo
            System.out.println("Held die not rolled..");
        }
        
    }

    public void setFace(int face){
        // lollolololol
        VisableFace = face;
        ChildDisplay.SetFace(face);

        //System.out.print("\t (Die #" + Num + " is now " + VisableFace + " | Child has" + ChildDisplay.getFace() + ")");
        // Send GUI info
        
    }
    public int getFaceNumber(){
       
        return VisableFace;
    }
    public int Value(){
        // Better call
        return getFaceNumber();
    }
    public boolean IsHeld(){
      return !Useable;
    }
    public void ToggleHold(){
        // Toggle lol
        Useable = !Useable;
        String wat = "";
        if (Useable) {wat = "Releasing";}else{wat = "Holding";}


        System.out.println(wat + " die..");
    }
    public void HoldDie(){
        // Hold it
        Useable = false;
        ChildDisplay.setHeld(Useable);
    }
    public void ReleaseDie(){
        Useable = true;
        ChildDisplay.setHeld(Useable);
    }
    public boolean canRoll(){
        return Useable;
    }
    public String toString(){
        // PARADOX o.0
        return Integer.toString(Value());
    }
    // Templated...


}
