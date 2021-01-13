package test;
import java.util.Scanner;
public class aliceadd {
			public static void main(String[] args) {
				Scanner sc = new Scanner(System.in);
				int t = sc.nextInt();
				int tong = 0;
				int[] a = new int[t];
				for(int i = 0; i<t;i++) {
					a[i] = sc.nextInt();
					tong = tong + a[i];
				}
				System.out.print(tong);
			}
		}
