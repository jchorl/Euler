import java.util.function.IntUnaryOperator;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;

public class p61 {
	public static ArrayList<Integer> genFourDigitSpecialNumbers(IntUnaryOperator op) {
		int curr;
		int i = 0;
		ArrayList<Integer> numbers = new ArrayList<>();

		while(op.applyAsInt(i) < 1000){
			i++;
		}
		curr = op.applyAsInt(i);
		do {
			numbers.add(curr);
			curr = op.applyAsInt(++i);
		} while (curr < 10000);
		return numbers;
	}
	public static Set<Integer> getFirstDigits(List<Integer> numbers) {
		Set<Integer> firstDigits = new HashSet<>();
		numbers.forEach(n -> firstDigits.add(n / 100));
		return firstDigits;
	}
	public static Set<Integer> getLastDigits(List<Integer> numbers) {
		Set<Integer> lastDigits = new HashSet<>();
		numbers.forEach(n -> lastDigits.add(n % 100));
		return lastDigits;
	}
	public static void eliminateBasedOnFirstDigits(Set<Integer> firstNumbers, List<Integer> numbers) {
		for (Iterator<Integer> it = numbers.iterator(); it.hasNext();) {
			int num = it.next();
			// check if first numbers contains the last two digits, otherwise the number cannot connect to any other number
			if (!firstNumbers.contains(num % 100)) {
				it.remove();
			}
		}
	}
	public static void eliminateBasedOnLastDigits(Set<Integer> lastNumbers, List<Integer> numbers) {
		for (Iterator<Integer> it = numbers.iterator(); it.hasNext();) {
			int num = it.next();
			// check if last numbers contains the first two digits, otherwise the number cannot connect to any other number
			if (!lastNumbers.contains(num / 100)) {
				it.remove();
			}
		}
	}
	public static void main(String[] args) {
		List<IntUnaryOperator> ops = new ArrayList<>();
		ops.add(n -> n * (n + 1) / 2);
		ops.add(n -> n * n);
		ops.add(n -> n * (3 * n - 1) / 2);
		ops.add(n -> n * (2 * n - 1));
		ops.add(n -> n * (5 * n - 3) / 2);
		ops.add(n -> n * (3 * n - 2));

		List<List<Integer>> numberLists = new ArrayList<>();
		ops.forEach(o -> numberLists.add(genFourDigitSpecialNumbers(o)));

		// get hashset of first two digits and last two digits to eliminate
		Set<Integer> allFirstDigits = new HashSet<>();
		Set<Integer> allLastDigits = new HashSet<>();
		List<Set<Integer>> firstDigits = new ArrayList<>();
		List<Set<Integer>> lastDigits = new ArrayList<>();
		numberLists.forEach(nl -> firstDigits.add(getFirstDigits(nl)));
		numberLists.forEach(nl -> lastDigits.add(getLastDigits(nl)));
		firstDigits.forEach(fd -> allFirstDigits.addAll(fd));
		lastDigits.forEach(ld -> allLastDigits.addAll(ld));
		
		// first batch of eliminations
		numberLists.forEach(nl -> eliminateBasedOnFirstDigits(allFirstDigits, nl));
		numberLists.forEach(nl -> eliminateBasedOnLastDigits(allLastDigits, nl));

		// DFS - since loop, can start with any list
		boolean used[];
		for (int n1 : numberLists.get(0)) {
			// this is the start of the chain
			int last1 = n1 % 100;
			used = new boolean[5];

			// we dont know which list the chain will come from
			for (int i = 1; i < numberLists.size(); i++) {
				// check to see if the last digits appear as first digits in this list
				if (firstDigits.get(i).contains(last1)) {
					// mark this list as used
					used[i - 1] = true;
					for (int n2 : numberLists.get(i)) {
						// make sure that the first 2 digits of n2 match the last 2 of n1
						if (last1 == n2 / 100) {
							int last2 = n2 % 100;
							for (int j = 1; j < numberLists.size(); j++) {
								if (!used[j - 1] && firstDigits.get(j).contains(last2)) {
									// j is now used as well
									used[j - 1] = true;
									for (int n3 : numberLists.get(j)) {
										if (last2 == n3 / 100) {
											int last3 = n3 % 100;
											for (int k = 1; k < numberLists.size(); k++) {
												if (!used[k - 1] && firstDigits.get(k).contains(last3)) {
													// k is also used
													used[k - 1] = true;
													for (int n4 : numberLists.get(k)) {
														if (last3 == n4 / 100) {
															int last4 = n4 % 100;
															for (int l = 1; l < numberLists.size(); l++) {
																if (!used[l - 1] && firstDigits.get(l).contains(last4)) {
																	used[l - 1] = true;
																	for (int n5 : numberLists.get(l)) {
																		if (last4 == n5 / 100) {
																			int last5 = n5 % 100;
																			for (int m = 1; m < numberLists.size(); m++) {
																				if (!used[m - 1] && firstDigits.get(m).contains(last5) && lastDigits.get(m).contains(n1 / 100)) {
																					// check if those numbers are paired together
																					for (int n6 : numberLists.get(m)) {
																						if (n6 / 100 == last5 && n6 % 100 == n1 / 100) {
																							System.out.println(n1 + n2 + n3 + n4 + n5 + n6);
																							return;
																						}
																					}
																				}
																			}
																		}
																	}
																	used[l - 1] = false;
																}
															}
														}
													}
													used[k - 1] = false;
												}
											}
										}
									}
									used[j - 1] = false;
								}
							}
						}
					}
					// mark as unused since we never actually took a number from the list
					used[i - 1] = false;
				}
			}
		}
	}
}
