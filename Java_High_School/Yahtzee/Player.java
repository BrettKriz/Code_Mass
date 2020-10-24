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
import java.util.Arrays;
import java.util.Vector;
import javax.swing.*;


public class Player implements Comparable{
    private String Name;
    private Integer[] Score;
    private boolean Turn;
    private int Rolls;
    private Scorecard Card;
    
    private static YahtzeeDice Dice = new YahtzeeDice();
    //public final String Coms = "0=Roll, 1="
    static  Random r = new Random();  //Calls constructor
    static  Scanner scan = new Scanner(System.in); //Setup keyboard input

    


    public Player(String name){
        // Hola
        Name = name;
        //Score = 0;
        Card = new Scorecard(this, Dice);

    
        
    }
    public void AfterRoll(){
        ComputeScore();
        CleanAfterRoll();
        EndTurn();
    }
    public void CleanAfterRoll(){
        // Reset little things after roll
        Rolls = 0;
        Card.display();
        Dice.DrawGUI(1);
        Dice.ReleaseALLDice();
    }
    public boolean StartTurn(){
        // What does ply want to do?
        Turn = true;
        // Loop em up!
        Say(Name + "'s Turn! (Press any key to Roll, score to see own score)");
        Integer ind = JOptionPane.showConfirmDialog(null, Name + "'s Turn! No to see score"); // , "Wake up cracker!"
        // Roll n stuff
        if (ind == null || ind == 1) {Say("Your score: " + Score);} // @@@
        AfterRoll();
        DoRolls();
        ScoreMe();

        return !EndTurn();
    }
    private Integer DoRolls(){
        // Do the 3 rolls
        // decide what to hold
        Integer FinalINT =0;
        boolean Rollin = true;
        int rolz = 1;
        boolean allhold = false;
        // Do 3 rolls
        while (Rollin == true && rolz<4){
          FinalINT = RollDice();
          Say("Roll #" + rolz);
          Say("Enter Dice # you want to toggle hold oo/f (0 = Done with Roll, -1 = Done with TURN)");
          String Ind = new String("Y U NO WORK?");
          
          int derr = 1;
          for (int y=0; y<Dice.length(); y++){
              int lol = 0;
              if (Dice.isHeld(y)) {lol = 1;}
              derr = derr * lol;
              allhold = (derr != 0);
              Card.display();
          }
          
          while (!Ind.equalsIgnoreCase("0") || !Ind.isEmpty() || allhold){


            Ind = JOptionPane.showInputDialog(null, "Enter Dice # you want to toggle hold of\n(Cancel to End Turn) (0 to end Pickup selection)", "Hold Dice", 1);
            //Ind = (int)scan.nextDouble() -1; // Minus 1 cause we count from 0 LOL
          // What to hold

            if (Ind == null || Ind.equals(null) || Ind.equalsIgnoreCase("done")) {Rollin = false; break;} // Null
            if (Ind.equalsIgnoreCase("end")) {Ind = "0";}

            if (Ind.isEmpty()) {Rollin = false; break;} // Break out of Turn
            if (Ind.equalsIgnoreCase("0")) {break;} // Break out of holding die
            // Go through dice to toggle some dice
            for(Integer x=0; x<Dice.length(); x++){
                if (Ind.equals("0") || Ind.isEmpty()) {Rollin = false; break;}
                
                if (Ind.equals(x.toString())) {Dice.ToggleHold(x); System.out.print("  ..K Next: "); break;}
                if (x == Dice.length() - 1) {Say("Try using a number between 1 and 6!");}
            }
          }
          // K now..?

          rolz++;

        } 
        //       Until not rolling or < 3 rolls

        return FinalINT;
    }
    private void ScoreMe(){
        // Oh yeah! Score me up babe!
        // LOL
        // Real talk tho
        SendLastRollFULL();
         
        boolean ti = false;
        Vector shirt_bro = Card.SendAbleScoreNames(), shirt_dude = Card.SendAbleScores();
        String lol2 = "= \n";
        
        if (shirt_bro.size() != shirt_dude.size()) {Say("Damnit! Shirt bro and shirt dude arnt the same length?? " + shirt_dude.size() + shirt_bro.size());}
                
        for (int y=0; y<shirt_bro.size(); y++){
            String notanint = "" + ((String)shirt_bro.elementAt(y)) ;
            String notanint2 = "" + ((Integer)shirt_dude.elementAt(y)).toString() ;
            lol2 = lol2 + "\n" + notanint;
        } // 
        // Thee actual scoring LOL
        String udonknowme = JOptionPane.showInputDialog(null, "Enter the name of the item you want to score\n(Currently Possible)"  + lol2, "Score me!", 1);
        int ffff = 0;
        do{
            ti = Card.AddScore(Card.N2Tab(udonknowme));
            // A rather large line there
            Say("Adding score... OH FFFFFFFFFUUUU" + ffff);
            ffff++;
        } while (!ti);
    }
        
    public int GetScore(){
        // AWWW SHIT.
        // See sum current
        return Card.SumCurrent();
    }
    private void SendLastRollFULL(){
        // Sent them things lol
        String rofl = "";
        for(int x=0; x<Dice.length(); x++){
            //if (Dice.canRoll(x)) {
                String lol = "#" + (x+1) + "=" + Dice.Value(x) + " ";
                rofl = rofl + lol;
                
                System.out.print(lol);
            //}

        }
        Card.SetLastRoll(rofl);
        Card.display();
    }
    private void SendLastRollUNHELD(){
        // Sent them things lol
        String rofl = "";
        for(int x=0; x<Dice.length(); x++){
            if (!Dice.isHeld(x)) {
                String lol = "#" + (x+1) + "=" + Dice.Value(x) + " ";
                rofl = rofl + lol;
                
                System.out.print(lol);
            }

        }
        Card.SetLastRoll(rofl);
        Card.display();
    }
    private void SendLastRollHELD(){
        // Sent them things lol
        String rofl = "";
        for(int x=0; x<Dice.length(); x++){
            if (Dice.isHeld(x)){
                String lol = "#" + (x+1) + "=" + Dice.Value(x) + " ";
                rofl = rofl + lol;
                
                System.out.print(lol);
            }

        }
        Card.SetLastRoll(rofl);
        Card.display();
    }
    private int RollDice(){
        // Roll the dice and return sum
        Dice.Roll();
        String rofl = "";
        for(int x=0; x<Dice.length(); x++){
            // Held dice wont roll when called
            // 
            //                            Boost +1
            
            if (Dice.canRoll(x)) {
                String lol = "#" + (x+1) + "=" + Dice.Value(x) + " ";
                rofl = rofl + lol;
                
                System.out.print(lol);
            }

        }
        Card.SetLastRoll(rofl);
            Card.display();
            
        Say("");
        for (int y=0; y<Dice.length(); y++){
          Dice.DrawGUI(y);
        }
        return CountDieVal();
    }
    private static int CountDieVal(){
        int sum = 0;
        for(int x=0; x<Dice.length(); x++){
            sum += Dice.Value(x);
            //
        }
        System.out.print("   Total: " + sum + "\n");
        return sum;
    }
    public boolean EndTurn(){
        // End tha turn
        Turn = false;
        return !Turn;
    }
    public void HiThere(){
        System.out.println("Hola! Im " + Name);
    }
    public String Name(){
        return Name;
    }
    private void ComputeScore(){
        // Figure out the score!!
        // Now used to ask aboot what to keep

        //Card.AddScore(Rolls);
        Card.SumCurrent();
        
    }

    public int compareTo(Object o){
        // lol compair shit
        Player p = (Player) o;
        // The 1 line got to long :(
        if (p.GetScore() < this.GetScore()) {
            return 1;
        } else if (p.GetScore() == this.GetScore()) {
            return 0;
        } else {
            return -1;
        }

        //return 0;
    }
    /*
    private class ScorePane extends JPanel{
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
            */
    private static void Say(String message)
    {// Fast way to print out
        boolean newline = true;
        if (newline) {
            System.out.println(message);
        } else {
            System.out.print(message);
        }
        return ;
    }
}
