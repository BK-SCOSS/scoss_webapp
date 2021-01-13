package tesolympic;
import java.util.Scanner;
public class CNTDIV {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int t = n*(n+1)*(n+2);
		int k = t*t;
		int dem = 0;
		for(int i = 1;i<n;i++) {
			if(k % i ==0 && n % i != 0) {
				dem = dem + 1;
			}
		}
		System.out.print(dem);
	}
}
	}
}
