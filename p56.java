import java.math.BigInteger;
public class p56 {

	public static int addDigits(String s){
		int sum = 0;
		for(char c:s.toCharArray()){
			sum += c-'0';
		}
		return sum;
	}

	public static void main(String[] args){
		BigInteger hundo = BigInteger.valueOf(100);
		int highest = 0;
		for(BigInteger a = BigInteger.ONE; a.compareTo(hundo) < 0; a = a.add(BigInteger.ONE)){
			for(int b = 1; b < 100; b++){
				int digitSum = addDigits(a.pow(b).toString());
				highest = Math.max(highest, digitSum);
			}
		}
		System.out.println(highest);
	}
}