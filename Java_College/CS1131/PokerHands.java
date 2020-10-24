import java.util.Scanner; // Include the needed util


/**
 * Program01 - PokerHands
 * CS 1131
 * 
 * Poker Hands
 * 
 * 
 * @author Brett Kriz
 */

public class PokerHands{
    public static final char FACE_TBL[] = {'A','K','Q','J','T','9','8','7','6','5','4','3','2'};

    public static void main(String[] args){
            // Create all needed vars
	Scanner in = new Scanner(System.in);
        String[] handtbl = new String[6];
        
        // Assuming no abnormal inputs, all caps and such
       
        
        // input
        out("Please enter a hand: ");
        String rawhand = in.nextLine().trim();
        String hand  = rawhand; // For debuging really
          
        char face=0, suit=0;
        int len = hand.length(); // Terminating Chars? Check
        int x   = 0; //Go forward
        
        // Start looping
        while(x < 5){ // Due to the 2 peices
            
            // Split string
           // String temp = hand.substring(0);
            face = hand.charAt(0); // Grab face at 0
            suit = hand.charAt(1); // Grab suit at 1

            handtbl[x] = ""  + face + suit;
            
            //Cut down the string
            if (hand.length() >= 2){
                hand = hand.substring(2); // 0+1 = 2;
            }

            x++;
        }// END LOOP
        
        /*  Now that we have a table containing the card data
            We can use custom checks on handtbl
            to find highest hand
        */
        
        // For debuging
        boolean[] flagTBL = {isRoyalFlush( rawhand ),
                            isStraightFlush(handtbl),
                            is4ofaKind(handtbl),
                            isFullHouse(handtbl),
                            isFlush(handtbl),
                            isStraight(handtbl),
                            is3ofaKind(handtbl),
                            is2Pair(handtbl),
                            is1Pair(handtbl),
                            };
        
        
        {
        int y=0;
        while(y < handtbl.length-1){
            out("Hand -> "+ y + " | " + handtbl[y]);
            y++;
        }
        }
        /*
        {
        int y = 0;
        while(y < flagTBL.length){
            
            out("" + flagTBL[y]);
            y++;
        }
        }
        */
        
        if ( flagTBL[0] ){
            out("Royal Flush");
        } else if ( flagTBL[1] ){
            out("Straight Flush");
        } else if ( flagTBL[2] ){
            out("Four of a Kind");
        } else if ( flagTBL[3] ){
            out("Full House");
        } else if ( flagTBL[4] ){
            out("Flush");
        } else if ( flagTBL[5] ){
            out("Straight");
        } else if ( flagTBL[6] ){
            out("Three of a Kind");
        } else if ( flagTBL[7] ){
            out("Two Pair");
        } else if ( flagTBL[8] ){
            out("One Pair");
        } else{ // None of the above
            out("High Card");
        }
 
	} // END MAIN
    
    public static void out(String msg){
        System.out.println(msg); // Convience method
    }
    public static void out(int msg){
        System.out.println("" + msg);
    }

    // Check/boolean methods
    public static boolean isRoyalFlush(String hand){
            boolean A=false,K=false,Q=false,J=false,T=false;
            char cursuit = 'x';
            int x = 0,len = hand.length(); 
            
            while(x<len){
                if (cursuit == 'x'){ // IF we dont already have a suit to check,
                    cursuit = hand.charAt(1);
                }
                // Check for suit
                int suitpos = x+1; 
                if (hand.charAt(suitpos) != cursuit){
                    return false; // WRONG SUIT
                }
                // Check for faces
                char facetemp = hand.charAt(x); //to reduce the amount of checks
                // Now the jointed ifs for checks
                if ( facetemp== FACE_TBL[4] ){
                    T = true;
                }else if ( facetemp== FACE_TBL[3] ){
                    J = true;
                }else if ( facetemp== FACE_TBL[2] ){
                    Q = true;
                }else if ( facetemp== FACE_TBL[1] ){
                    K = true;
                }else if ( facetemp== FACE_TBL[0] ){
                    A = true;
                } 
                x = x+2; // Increment 2 B/C of String not Table
            }
            
            return A && K && Q && J && T; // Must have all
    }
    public static boolean isStraightFlush(String[] handtbl){
        // Lets cut some code...
        // Since it IS a straight & flush
        return ( isFlush(handtbl) && isStraight(handtbl) );
    }            
    public static boolean is4ofaKind(String[] handtbl){
        // 4 of the same face card
        int x = 0;
        int[] count = new int[13]; // Ment to mimic FACE_TBL
        int occurences = 0, targetSize = 4;
        int maxOcc = 1;
        // Sort the tables and count
        while(x < handtbl.length-1){
            char cur = handtbl[x].charAt(0);
            int y = 0;
            
            while (y<FACE_TBL.length-1){ // Find index to store at
                if (FACE_TBL[y] == cur){
                    count[y]++;
                    break;
                }
                y++;
            } // END WHILE
            x++;
        }// END WHILE

        x = 0;
        // Check sums
        while(x < count.length-1){
            if (count[x] == targetSize){
                occurences++;
                out(count[x]);
            }else if(count[x] > targetSize){
                return false; // This should prevent "5 of a kind"
            }
            
            if (occurences > maxOcc){ 
                // More occurences than allowed
                return false;
            }
            x++;
        }

        return (occurences == maxOcc);
    }
            
    public static boolean isFullHouse(String[] handtbl){
        int x = 0;
        int[] count = new int[13]; // Ment to mimic FACE_TBL2
        int occurences = 0,  targetSize = 3;
        int occurences2 = 0, targetSize2 = 2;
        int maxOcc = 1;
        boolean hasPair = false, has3OK = false;
        // Sort the tables and count
        while(x < handtbl.length-1){
            char cur = handtbl[x].charAt(0);
            int y = 0;
            
            while (y<FACE_TBL.length-1){ // Find index to store at
                if (FACE_TBL[y] == cur){
                    count[y]++;
                    break;
                }
                y++;
            } // END WHILE
            x++;
        }// END WHILE

        x = 0;
        // Check sums
        while(x < count.length){
            
            if (count[x] == targetSize){
                // Check for 3 of kind
                occurences++;
            }else if (count[x] == targetSize2){
                // Check for pair
                occurences2++;
            }
            x++;
        }

        return (occurences == maxOcc && occurences2 == maxOcc); // Return our flag
    }      
    public static boolean isFlush(String[] handtbl){
        char cursuit = 'x';
        int x = 0,len = handtbl.length-1; 
            
            while(x<len){
                if (cursuit == 'x'){ // IF we dont already have a suit to check,
                    cursuit = handtbl[x].charAt(1);
                }
                // Check for suit
                if (cursuit != handtbl[x].charAt(1)){
                    return false; // WRONG SUIT
                }
             x++;   
            }
        
        return true;
    }
    public static boolean isStraight(String[] handtbl){
        // Checking for consecutive face values
        // ASSUMING seqential numbering
        int x = 0; // Working backward
        int target = -1;
        char cur = handtbl[0].charAt(0); // Grab initial face
        
        while(x < FACE_TBL.length-1){
            if (cur == FACE_TBL[x]){
                target = x;
                break; // Find start in face tbl 2
            }
            x++;
        }

        // These blocks check for false
        if (FACE_TBL.length-target < handtbl.length){
            // Cant be straight with given length
            return false;
        }
        
        x=0;
        while(x < handtbl.length-1) {
            if (handtbl[x].charAt(0) != FACE_TBL[target + x]){
                // Cant be straight
                return false;
            }
            x++;
        }
        
        return true;
    }  
            
    public static boolean is3ofaKind(String[] handtbl){
        int x = 0;
        int[] count = new int[13]; // Ment to mimic FACE_TBL
        int occurences = 0, targetSize = 3;
        int maxOcc = 1;
        // Sort the tables and count
        while(x < handtbl.length-1){
            char cur = handtbl[x].charAt(0);
            int y = 0;
            
            while (y<FACE_TBL.length){ // Find index to store at
                if (FACE_TBL[y] == cur){
                    count[y]++;
                    break;
                }
                y++;
            } // END WHILE
            x++;
        }// END WHILE

        
        {
            int y =0;
            
            while(y<count.length){
                out( ">>" + y + " " + FACE_TBL[y] + ">> "+count[y] );
                y++;
            }
            
        }
        
        
        x = 0;
        // Check sums
        while(x < count.length){
            if (count[x] == targetSize){
                occurences++;
            }else if(count[x] > targetSize){
                return false;
            }
            if (occurences > maxOcc){ 
                // More occurences than allowed
                return false;
            }
            x++;
        }

        return (occurences == maxOcc);
    }
    
    public static boolean is2Pair(String[] handtbl){
        int x = 0;
        int[] count = new int[13]; // Ment to mimic FACE_TBL
        int occurences = 0, targetSize = 2;
        int maxOcc = 2;
        // Sort the tables and count
        while(x < handtbl.length-1){
            char cur = handtbl[x].charAt(0);
            int y = 0;
            
            while (y<FACE_TBL.length-1){ // Find index to store at
                if (FACE_TBL[y] == cur){
                    count[y]++;
                    break;
                }
                y++;
            } // END WHILE
            x++;
        }// END WHILE

        x = 0;
        // Check sums
        while(x < count.length-1){
            if (count[x] == targetSize){
                occurences++;
            }else if(count[x] > targetSize){
                return false;
            }
            if (occurences > maxOcc){ 
                // More occurences than allowed
                return false;
            }
            x++;
        }

        return (occurences == maxOcc);
    }
    public static boolean is1Pair(String[] handtbl){   
        int x = 0;
        int[] count = new int[13]; // Ment to mimic FACE_TBL
        int occurences = 0, targetSize = 2;
        int maxOcc = 1;
        // Sort the tables and count
        while(x < handtbl.length-1){
            char cur = handtbl[x].charAt(0);
            int y = 0;
            
            while (y<FACE_TBL.length-1){ // Find index to store at
                if (FACE_TBL[y] == cur){
                    count[y]++;
                    break;
                }
                y++;
            } // END WHILE
            x++;
        }// END WHILE

        x = 0;
        // Check sums
        while(x < count.length-1){
            if (count[x] == targetSize){
                occurences++;
            }else if(count[x] > targetSize){
                return false;
            }
            if (occurences > maxOcc){ 
                // More occurences than allowed
                return false;
            }
            x++;
        }

        return (occurences == maxOcc);
    }

} //END CLASS