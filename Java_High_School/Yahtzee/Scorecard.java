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
import java.util.Vector;



public class Scorecard {
    final int WIDTH = 200;
    final int HEIGHT = 200;

    private JFrame frame; // Java window
    private JPanel panel; // Container for stuff in the frame

    private int num;
    private String Name;
   
    private int[] Score = new int[13];
    //private boolean[] Used = new boolean[13];
    private static String[] ScoreNames = new String [13];
    private static String Rolled_Last;
    private static YahtzeeDice lol;
    
    private static int Count = 0;
    public Scorecard(Player ROFL, YahtzeeDice hi){
     // Keeps track of scores :\
     lol = hi;
     Rolled_Last = "Not rolled yet";
     ScoreNames[0] = "Aces";
     ScoreNames[1] = "Twos";
     ScoreNames[2] = "Threes";
     ScoreNames[3] = "Fours";
     ScoreNames[4] = "Fives";
     ScoreNames[5] = "Sixes";
     ScoreNames[6] = "3 of a Kind";
     ScoreNames[7] = "4 of a Kind";
     ScoreNames[8] = "Full House";
     ScoreNames[9] = "Small Straight";
     ScoreNames[10] = "Large Straight";
     ScoreNames[11] = "YAHTZEE";
     ScoreNames[12] = "Chance";

     Count++;
     num = Count;
     Name = ROFL.Name();
     ClearCard();

     frame = new JFrame(ROFL.Name() + "'s Score Card");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // end when x hit
        panel = new ScorePane();
        panel.setPreferredSize(new Dimension(WIDTH, HEIGHT));
        //panel.setLocation();

        frame.getContentPane().add(panel);
        frame.pack();
        frame.setVisible(true);
        frame.setBackground(Color.gray);
        Double wub = 1.0 + (num/10) + (num/100); // ROFL
        frame.setLocation((int)((WIDTH+20)*(num*1)+10), 60);

     
    }
    public String[] SendScoreNames(){
        return ScoreNames;
    }
    public Vector SendAbleScoreNames(){
        // Return  USEABLE score names, Need i say more?
        Vector What = new Vector();
        for (int x=0; x<ScoreNames.length; x++){
            if (Score[x] == -1){
                What.add(ScoreNames[x]);
            }
        }
        return What;
    }
    public Vector SendAbleScores(){
        // Return  USEABLE scores, Need i say more?
        Vector What = new Vector();
        
        // Man, I fucked up :\
        if (rsf(1,scoreas1()) != -1) {What.add(rsf(1,scoreas1()) );}
        if (rsf(2,scoreas2()) != -1) {What.add(rsf(2,scoreas2()) );}
        if (rsf(3,scoreas3()) != -1) {What.add(rsf(3,scoreas3()) );}
        if (rsf(4,scoreas4()) != -1) {What.add(rsf(4,scoreas4()) );}
        if (rsf(5,scoreas5()) != -1) {What.add(rsf(5,scoreas5()) );}
        if (rsf(6,scoreas6()) != -1) {What.add(rsf(6,scoreas6()) );}
        // mMMm
        if (rsf(7,scoreas3ok()) != -1) {What.add(rsf(7,scoreas3ok()) );}
        if (rsf(8,scoreas4ok()) != -1) {What.add(rsf(8,scoreas4ok()) );}
        // FH
        if (rsf(9,scoreasfh()) != -1) {What.add(rsf(9,scoreasfh()) );}
        
        if (rsf(10,scoreasss()) != -1) {What.add(rsf(10,scoreasss()) );}
        if (rsf(11,scoreasls()) != -1) {What.add(rsf(11,scoreasls()) );}
        // Yahtzee
        if (rsf(12,scoreasYAHTZEE()) != -1) {What.add(rsf(12,scoreasYAHTZEE()) );}
        // Chance
        if (rsf(13,scoreasc()) != -1) {What.add(rsf(13,scoreasc()) );}
        
        
        return What;
    }
    private int rsf(int num, int back){
        // reapeatscorefilter
        if (Score[num-1] == back){
            return -1;
        }else
            return back;
    }
    public int N2Tab(String wut){

        for (int x=0;x<ScoreNames.length;x++){
            if (wut.equalsIgnoreCase(ScoreNames[x]) || wut.equalsIgnoreCase(""+(x+1))) {
                return x;
            }
        }
        System.out.println("Could not convert " + wut + " To a score tab! WTF?");
        return 0;
    }
    public boolean AddScore(int item){
    // Add a score to the card, call in a loop until true
        //Used[item] = true;
        if (!(item >=0 && item<Score.length)) {System.out.println("woops! Couldnt add score!"); return false;}
        // Lets figure shit out eh,
        boolean k = true;
        
        if (item >= 0 && item < 6){
            // Sum score and submit
            Score[item] = Sumofoccurences(item);
        }else if (item == 6){// 3ok
            Score[item] = scoreas3ok();
        }else if (item == 7){
            Score[item] = scoreas4ok();
        }else if (item == 8){// FH
            Score[item] = scoreasfh();
        }else if (item == 9) {//SS
            Score[item] = scoreasss();
        }else if (item == 10) {//LS
            Score[item] = scoreasls();
        }else if (item == 11) {// Yahtzee
            
            Score[item] = scoreasYAHTZEE();
        }else if (item == 12) {// Chance
            Score[item] = scoreasc();
        }


       return true;
    }
    public int scoreas1(){
        if (Score[0] != -1) {return Score[0];}
        return Sumofoccurences(1);
    }
    public int scoreas2(){
        if (Score[1] != -1) {return Score[1];}
        return Sumofoccurences(2);
    }
    public int scoreas3(){
        if (Score[2] != -1) {return Score[2];}
        return Sumofoccurences(3);
    }
    public int scoreas4(){
        if (Score[3] != -1) {return Score[3];}
        return Sumofoccurences(4);
    }
    public int scoreas5(){
        if (Score[4] != -1) {return Score[4];}
        return Sumofoccurences(5);
    }
    public int scoreas6(){
        if (Score[5] != -1) {return Score[5];}
        return Sumofoccurences(6);
    }
    public int scoreas3ok(){
        // 3 of a kind
            int hi = Sumofoccurences(3), item = 6;
            if (Score[item] != -1) {return Score[item];}
            if (hi != -1) {return hi;}
            else
                return 0;
            
    }
    public int scoreas4ok(){
        // 4 of a kind
            int hi = Sumofoccurences(4), item = 7;
            if (Score[item] != -1) {return Score[item];}
            if (hi != -1) {return hi;}
            else
                return 0;
    }
    public int scoreasfh(){
        // Full house
            // God that show sucked..
            // 25 pts
            // 2same 3same
        if (Score[8] != -1) {return Score[8];}
            if (Numofoccurences(2)){
                return 25;
            }else
                return 0;
            //
    }
    public int scoreasss(){
        // Small Straight
            // 30 pts
            // Sequence of 4
        int item = 9;
        if (Score[item] != -1) {return Score[item];}
            if (Sequenceof(4)) {
            // Works
                return 30;
            }else{
                //System.out.println("Dummy...");
                
                return 0;
            }
    }
    public int scoreasls(){
        // Large Straight
            // Sequence of 5
        int item = 10;
        if (Score[item] != -1) {return Score[item];}
            if (Sequenceof(5)){
                // Works
                return 30;
            }else{
                //System.out.println("Dummy...");
                
                return 0;
            }
        
    }
    public int scoreasYAHTZEE(){
        int hi = Sumofoccurences(5), item = 11;
        if (Score[item] != -1) {return Score[item];}
            if (hi != -1) { return 25;}
    else{
                return 0;
    }
}
    public int scoreasc(){
        // Chance
            // TAKE THEM NUMBAS
            if (Score[12] != -1) {return Score[12];}
            int tot = 0;
            int len = 5;
            for (int x=0; x<len; x++){
                tot += lol.Value(x);
            }
            
        return tot;
    }
    // Got i hate that shit
    public boolean Sequenceof(int max){
        int derp = 0, cont = 0;
        Die[] heh = lol.SendDie();
        heh = SortDice(heh);
        derp = heh[0].Value();
        
        for (int x=1; x<heh.length; x++){
            if (!(heh[x].Value() == derp + 1)) {cont = 0;} else {cont++;}
            
        }
        
        return (derp == max);
    }
    private Die[] SortDice(Die[] meow){
        
        for (int i = 1; i < meow.length; i++) {
            //Comparable key = objects[i];
            int key = meow[i].Value();
            int position = i;

            // Shift larger values to the right
            while (position > 0 && meow[position - 1].Value() > key) {
                meow[position] = meow[position - 1];
                position--;
            }
        }
        
        return meow;
    }
    public int CalcScore(int item){
        // Cant rember what this is for
        return Score[item];
    }
    
    private boolean Numofoccurences(int MaxCount){
        // Find how many diff numbs we have
        int shit = 0;
        Vector found = new Vector();
        Vector foundint = new Vector();
        Vector Ya = new Vector();
        int len = lol.length();
        Ya.setSize(len);
        found.setSize(len);
        foundint.setSize(len);
        for (int y =0; y<len; y++){
            Ya.set(y, 0);
            found.set(y, 0);
            foundint.set(y, 0);
        }

        
        
        for (int x=0; x<len; x++){
            // Pickup values
            int wut = lol.Value(x)-1;
            Ya.set(wut, (Integer)Ya.get(wut) + 1);
            
            //Ya[lol.Value(x)-1]++;
        }

        Integer meow = found.toArray().length;
        return (meow == MaxCount);
    }
    private int Sumofoccurences(Integer MaxCount){
        // Find the sum of all occurences
        int shit = 0;
        Vector found = new Vector();
        Vector foundint = new Vector();
        int[] Ya = new int[6];
        for (int x=0; x<lol.length(); x++){
            // Pickup values
            Ya[lol.Value(x)-1]++;
        }
        // Now check how many meet the max
        for (int x=0; x<Ya.length; x++){
            // If the value of Ya is greater thanorequal to maxcount
            // *up to par*
            if (Ya[x] >= MaxCount) {
                // Calculate the total val
                found.add(x*Ya[x]);
                foundint.add(x);
                shit++;
            }
            // wtf?
            if (found.size() > MaxCount) {System.out.println("!! Found was higher than max count !!") ;break;}
        }

        if (found.size() != 1 && found.size() > 0) {
            // Go thro and find the highest value item
            Integer largest = 0;
            for (int x =0; x<found.size();x++){

                if ((Integer)found.get(x) >= largest){
                    largest = (Integer)found.get(x);
                }
            }
            // Now we lookup the largets value
            // Might not use it X.X

            //(Integer)found.get(largest)
            return largest;
        }else if (found.size() <= 0){
            System.out.println("Nothing met the maxcount");
            return 0;
        }else{
            
            return (Integer)found.firstElement();
        }

        
        //return -1;
    }
    public int SumCard(){
        // Total the entire card
        int cake =0;
        this.display();
        for (int x=0; x<Score.length; x++){
            if (Score[x] != -1){
            cake += Score[x];
           }
        }
        return cake;
    }
    public int SumCurrent(){
        // Total the current card
        int cake =0;
        this.display();
        for (int x=0; x<Score.length; x++){
            if (x==5){
                 if (cake >= 63){
                     cake += 63;
                     System.out.println("Earned a bonus! Cracker...");
                 }
                }
            
            if (Score[x] != -1){
            cake += Score[x];
           }
        }
        return cake;
        
    }
    public void ClearCard(){
    // CLEAN IT UP!
        for (int x=0; x<Score.length;x++){
            Score[x] = -1;
            //Used[x] = false;
            
        }
        //display();
    }
    public void SetLastRoll(String wut){
        // Sets the string of the last roll
        Rolled_Last = wut;
        display();
    }
    public void display(){

            panel.repaint();

        }
    private class ScorePane extends JPanel{
        // Objects of this type ARE JPanels in evesryway
        // expcept we will:
            final int WIDTH = 200;
            final int HEIGHT = 200;

        //override one method
        int center = WIDTH/2, scent = WIDTH/2 - (WIDTH/2)/2;
        int margin = 10;

            public void paintComponent(Graphics g){
                // Paint component is automatically called by
                // the rePaint() method

                //Call the original paintcomponent for background
                super.paintComponent(g);
                g.drawRect(margin, margin, HEIGHT-(margin*2), WIDTH-(margin*2));
                
                String sum = "____";
                int y = 1;
                for (int Num=0;Num<Score.length;Num++){
                    if (Score[Num] == -1) {
                        g.setColor(Color.gray);
                    }else{
                        g.setColor(Color.BLACK);
                        sum = "" + CalcScore(Num);
                        // Unconvertable type my ass..
                        }
                    
                    String wtf = (String)(ScoreNames[Num]) + ": ";
                    String tab = sum;
                    g.drawString(wtf, margin+2, (margin*y)+10);
                    g.drawString(tab, center, (margin*y)+10);
                    y++;
                }
                g.setColor(Color.BLACK);
                g.drawString(Rolled_Last, margin+4, HEIGHT-margin);
            
            }
    }
}
