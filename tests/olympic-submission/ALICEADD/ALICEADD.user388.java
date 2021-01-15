package Aliceadd;
import java.util.Scanner;
import java.util.Arrays; 
import java.util.List;
public class Test {
	

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int[] rs = new int[T];
		int[] arr1 = new int[T];
		int[] arr2 = new int[T];
		for(int i=0;i<T;i++) {
			arr1[i] = sc.nextInt();
			arr2[i] = sc.nextInt();
			rs[i] = arr1[i] + arr2[i];
		}
		
		for(int i=0;i<T;i++) {
			System.out.println(rs[i]);
		}
	}

}
