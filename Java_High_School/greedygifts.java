/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author krizba
 */
import java.io.*;
import java.util.*;

public class greedygifts {
    static Person[] people = new Person[10];
    public static void main(String[] args) throws IOException {
        // THE WAREWOLF! *Seasure*
        //String filetoread = "ridek.in";
        Scanner scan = new Scanner(new File("people.in.txt"));
        //Use a PrintWriter for the output file
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ride.out")));

        // How many peeple. and names
        int NPeople = scan.nextInt();
        String giver;
        for (int x=0; x<NPeople; x++){
            people[x] = new Person(scan.next());
        }  
        
        
        for (int y=0; y<NPeople; y++){
            giver = scan.nextLine();
            int n1 = scan.nextInt(), n2 = scan.nextInt();
            for (int z=0; z<n2; z++){
                int given = n1/n2;
                String got = scan.nextLine();
                for (int v=0; v<NPeople; v++){
                    if (got == people.get[v]){
                        
                    }
                }// MEOW
            }

        }



        //Close the program
        out.close();
        System.exit(0);
    }
    public static int search(Person[] persons, String name){
        for (int x = 0; x<people.length; x++){
            if (name.equals(persons[x])){
                return 01;
            }
        }
        return -1;
    }
}

    class Person{

        private String name;
        private int InitBal;
        private int FinBal;
        private int friends;
        Scanner scan = new Scanner(System.in);

        public Person(String Name){
            name = Name;
            InitBal = 0;
            FinBal = 0;
        }
        public void setBalance(int money){
            InitBal = money;
        }
        public void give(Person lol, int cash){
            lol.setBalance(cash);
            //@@@
        }
        public String getName(int num){
            return name;
        }
        public int getTotalCash(int num){

            return InitBal;
        }
        public Person get(){
            return this;
        }
    }