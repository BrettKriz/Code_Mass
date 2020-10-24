/**
 * Program 00
 * Basic output manipulation of some sort
 * Even tho we didn't learn about overloading
 * or functions/methods yet
 * 
 * @author Brett Kriz
 */

public class program00{
    public static void main(String[] args){
        // Since it seems to be the only quick way
        // Lets make an overloaded quick fuction that concats the 2 segments
            out("What is 3 ^ 5? ",3 ^ 5); // Not sure why xor is neecded, but sure
            out("What is 6 / 3? ",6 / 3);
            out("What is 6.0 / 3? ",6.0 / 3);
            out("What is 6 / 3.0? ",6 / 3.0);
            out("What is 1.0 / 3.0? ",1.0 / 3.0);
            out("What is 0x01 ? ",0x01); // not sure why Hex is needed, but sure
            out("What is 0x10 ? ",0x10);
            out("What is 010? ",010); // Yeaaaaah.... 10
            out("What is 024? ",024);
            out("What is 4 % 3? ",4 % 3); // Decimal ops
            out("What is 5 % 3? ",5 % 3);
            out("What is 6 % 3? ",6 % 3);
            out("What is -2 % 3? ",-2 % 3);
            out("What is 8 * 5 + 2? ",8 * 5 + 2);
            out("What is 2 + 5 * 8? ",2 + 5 * 8);
            out("What is (8 * 5) + 2? ",(8 * 5) + 2);
            out("What is 8 * (5 + 2)? ",8 * (5 + 2));
            out("What is 5.0 > 3.0? ",5.0 > 3.0); // How cute, bools!
            out("What is !(5.0 > 3.0)? ",!(5.0 > 3.0));
            out("What is 3.0 == 3? ",3.0 == 3);
            out("What is !(3.0 == 3)? ",!(3.0 == 3));
            out("What is 0x1 << 1? ",0x1 << 1); // How cute, Shifts!
            out("What is 0x1 << 2? ",0x1 << 2);
            out("What is 0x1 << 3? ",0x1 << 3);
            out("What is 0x1 << 4? ",0x1 << 4);
        // Done with main
    }
    public static void out(String arg1, double arg2){
        System.out.println(arg1 + arg2); // Convience Function
    }
    public static void out(String arg1, int arg2){
        System.out.println(arg1 + arg2); // overloaded Convience Function
    }
    public static void out(String arg1, boolean arg2){
        System.out.println(arg1 + arg2); // overloaded Convience Function
    }
    // How pain-less!
}