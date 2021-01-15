
import java.io.IOException;
import java.util.Scanner;


public class ALICEADD {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int i =0; i<T; i++){
			long a= in.nextLong();
			long b=in.nextLong();
			System.out.println(a+b);
		}
		
	}

}
