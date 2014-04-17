public class p17 {
	public static int ones(int n) {
		int[] one2nineteen = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7,
				7, 9, 8, 8 };
		return one2nineteen[n];
	}

	public static int tens(int n) {
		int[] twenty2ninety = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };
		return twenty2ninety[n / 10] + ones(n % 10);
	}

	public static int hundreds(int n) {
		int[] hundo = { 0, 10, 10, 12, 11, 11, 10, 12, 12, 11, 10 };
		if (n % 100 > 19) {
			return hundo[n / 100] + tens(n % 100) + 3;
		} else if (n % 100 == 0) {
			return hundo[n / 100];
		}
		return hundo[n / 100] + ones(n % 100) + 3;
	}

	public static void main(String[] args) {
		int sum = 0;
		for (int i = 1; i < 1000; i++) {
			if (i < 20) {
				sum += ones(i);
			} else if (i < 100) {
				sum += tens(i);
			} else {
				sum += hundreds(i);
			}
		}
		sum += 11;
		System.out.println(sum);
		// System.out.println(ones(17));
		// System.out.println(ones(14));
		// System.out.println(ones(4));
		// System.out.println(ones(1));
		// System.out.println(ones(19));
		// System.out.println(tens(50));
		// System.out.println(tens(78));
		// System.out.println(tens(20));
		// System.out.println(tens(99));
		// System.out.println(hundreds(114));
		// System.out.println(hundreds(100));
		// System.out.println(hundreds(999));
		// System.out.println(hundreds(568));
		// System.out.println(hundreds(311));
	}
}
