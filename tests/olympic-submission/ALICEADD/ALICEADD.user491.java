package Check;

public class interview_with_hackerrank {
	public static void main(String[] args) {
		int x[][] = { { 1, 2 }, { 2, 3 } };
		for(int i: aliceadd(2, x)) {
			System.out.println(i);
		}
	}

	static int[] aliceadd(int t, int z[][]) {
		int x[] = new int[t];
		for (int i = 0; i < t; i++) {
			x[i] = z[i][0] + z[i][1];
		}
		return x;
	}
}
