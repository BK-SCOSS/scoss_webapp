package olippic;

import java.util.Scanner;

public class olimpic {
	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		int n=scanner.nextInt();
		if(n>0) {
			long[] clgt=new long[n];
			for(int i=0;i<n;i++) {
				long m=scanner.nextLong();
				long k=scanner.nextLong();
				clgt[i]=m+k;
			}
			for(int i=0;i<n;i++) {
				System.out.println(clgt[i]);
			}
		}
	}

}
