/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author krizba
 */
import java.util.Scanner;
import java.text.NumberFormat;
import java.lang.Math; //right below class statement
import java.util.Random;
import java.util.Vector;
import java.util.Arrays;
import javax.swing.*;

public class yahtzee {
    static  Random r = new Random();  //Calls constructor
    static Scanner scan = new Scanner(System.in); //Setup keyboard input
    // Die[] Dice = new Die[6];
    static Vector Players = new Vector();
    static int NumberofPlayers;
    
    static boolean ending = false;
    static Integer MAXTURNS = 3;

    public static void main(String[] args) {
        // "Bitches" BASS LINE SEASURE
        //Players[1].HiThere();
        // JOptionPane.showInputDialog(null, "Number of Players", "How Many?", 1);
        NumberofPlayers = RequestINT("How Many Players?");
        if (NumberofPlayers <= 0){
            NumberofPlayers = 2;
            System.out.println("Automaticly ending!");
            ending = true;
            MAXTURNS = 0;
        }
        Init();
       //scan.next();
        DoGame();
        String bye = Request("Bye bye!");
    }
    public static void Init(){
        // Set up shit lol
        for(int x = 0; x <NumberofPlayers; x++){
            Players.add(new Player("Player " + (x+1)));
            if (ending){
                ((Player)Players.elementAt(x)).Name();
                
            }
        }

    }
    public static void DoGame(){
        Player Winner = null;
        int turns = 0;
        // Les geat eit oawn!
        int x = 0;
        do{
            for (int ply = 0; ply < NumberofPlayers; ply++){
                // IN pairs loop LOL
                Player Cake = (Player)Players.get(ply);
                Cake.StartTurn();
                TurnCleaner(ply);
            }

            turns++;
        } while (turns <= MAXTURNS);
        
        Player highest = (Player)Players.elementAt(0);
        String Highest = highest.Name();
        String Extra = "";
        for (int y=1; y<Players.size(); y++){
            Player comp = ((Player)Players.elementAt(y));
            if (comp.compareTo(highest) == -1) {
                // Highest is greater
               Highest = highest.Name();
            }else if (comp.compareTo(highest) == 0){
                // Equal
                Highest = Highest + comp.Name();
                Extra = " Its a Tie REALLY tho!";
            }else{
                //COmp is greater
                highest = comp;
                Highest = highest.Name();
                Extra = "";
            }
        }
        System.err.println("Winner(s): " + Highest + Extra);
        System.err.println("Winner(s): " + Highest + Extra);
        return ;
        //return Winner;
    }

    
    public static void TurnCleaner(int ply){
        // Now with 85% more Bleach!
        Player Cake = (Player)Players.get(ply);
        Cake.CleanAfterRoll();

        //All dice.ReleaseDie()
    }
    public static String Request(String message)
    {// Fast way to print out
        String Ind = "";
            System.out.println("Enter " + message + ":");
            // Needs to be a new line cause next line just reads a line
            Ind = scan.nextLine();
        return Ind;
    }

    public static int RequestINT(String message){
        String cake = Request(message);
        return Integer.parseInt(cake);
    }
}
