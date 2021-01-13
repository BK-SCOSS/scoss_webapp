import java.math.BigInteger;
import java.util.Scanner;

public class ALICEADD {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n= scanner.nextInt();
        for(int i=0;i<n;i++){
            long a= scanner.nextLong();
            long b= scanner.nextLong();
            BigInteger a1= new BigInteger(Long.toString(a));
            BigInteger b1= new BigInteger(Long.toString(b));
            System.out.println(a1.add(b1));
        }
    }
}
