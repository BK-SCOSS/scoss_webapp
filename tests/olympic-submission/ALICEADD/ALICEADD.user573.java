import java.math.BigInteger; 
import java.util.Scanner;

public class ALICEADD{

     public static void main(String []args){
        int n;
        BigInteger a = new BigInteger("0");
        BigInteger b = new BigInteger("0");
        
        Scanner sc = new Scanner(System.in);
        
        n = sc.nextInt();
        
        for (int i = 0; i < n; i++){
            a = new BigInteger(sc.next());
            b = new BigInteger(sc.next());
            a = a.add(b);
            System.out.println(a);
        }
     }
}