package Check;

class reversearray {

	public static void main(String[] args) {
		int x[] = { 2 };
		CTNDIV(1, x);
	}

	static void CTNDIV(int t, int n[]) {
		for (int i = 0; i < t; i++) {
			int test = n[i] * (n[i] + 1) * (n[i] + 2);
			int count = 0;
			for (int j = 0; j < test; j++) {
				if (Math.pow(test, 2) % j == 0 && j < test && test % j != 0) {
					count++;
				}
			}
			System.out.println(count);
		}
	}
}
