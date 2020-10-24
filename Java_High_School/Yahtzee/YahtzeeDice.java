/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author krizba
 */
public class YahtzeeDice {
    private static DiceGUI MyGUI = new DiceGUI();
    private Die[] Dice = new Die[5];
    
    public YahtzeeDice(){
        for (int x=0; x<Dice.length; x++){
            Dice[x] = new Die(MyGUI.sendDieDrawing(x));
            //System.out.println("Have " + (Dice.length-1) + " Dice!");
        }
    }
    public void ToggleHold(int num){
        Dice[num].ToggleHold();
        refresh();
    }
    public void ReleaseDie(int num){
        Dice[num].ReleaseDie();
        refresh();
    }
    public void ReleaseALLDice(){
        for (int x=0;x<Dice.length;x++){
            Dice[x].ReleaseDie();
        }
        refresh();
    }
    public void Roll(){
        for(int x = 0; x<Dice.length; x++){
            if (Dice[x].canRoll()) {Dice[x].Roll();}
            MyGUI.display(x, Dice[x].Value());
        }
        refresh();
    }
    public boolean canRoll(int num){
        MyGUI.display(num);
        refresh();
        return Dice[num].canRoll();
    }
    public int length(){
        return Dice.length;
    }
    public int Value(int num){
        refresh();
        //if (num < Dice.length){
        return Dice[num].Value();
        //}else{
            //System.out.println("We screwed up! Cant go to " + num);
           // return Dice[Dice.length-1].Value();
        //}
    }
    public void DrawGUI(int num){
        // Display them all!!
        MyGUI.display();
        refresh();
    }
    private void setFace(int num, int face){
        Dice[num].setFace(face);
        MyGUI.display(num, face);
        refresh();
    }
    public boolean isHeld(int num){
        return Dice[num].IsHeld();
    }
    public int getFaceNumber(int num){
        refresh();
        return Dice[num].getFaceNumber();
    }
    public Die[] SendDie(){
        return Dice;
    }
    /*
    public void insertionSort() {
        Die lol[] = Dice;
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
    }
     
     */
    private void refresh(){
        // Refresh ALL values
        
        for (int x=0;x<Dice.length;x++){
           MyGUI.setHeld(x, Dice[x].IsHeld());
           MyGUI.display(x, Dice[x].Value());
        }
        MyGUI.display();
    }
    public String dietostring(int num){
        return Dice[num].toString();
    }

}
