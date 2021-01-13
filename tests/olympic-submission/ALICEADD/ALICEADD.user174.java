import java.util.Scanner;
public class ALICEADD {
    public static void main(String[] arg){
        int T;
        Scanner sc = new Scanner(System.in);
        T=sc.nextInt();
        long a,b;
        for(int i=0;i<T;i++){
            a=sc.nextLong();
            b=sc.nextLong();
            System.out.println(a+b);
        }
         
     }
    
}
