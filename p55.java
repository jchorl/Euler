import java.util.concurrent.atomic.AtomicInteger;
import java.math.BigInteger;
import java.util.stream.LongStream;
public class p55 {

	public static boolean palindrome(String s){
		for(int i = 0; i < s.length()-(i+1); i++){
			if(s.charAt(i)!=s.charAt(s.length()-(i+1))){
				return false;
			}
		}
		return true;
	}

	public static boolean lychrel(BigInteger orig, int calls){
		if(calls > 50){
			return true;
		}
		BigInteger switched = new BigInteger((new StringBuilder(orig.toString())).reverse().toString());

		BigInteger addition = orig.add(switched);

		if(palindrome(addition.toString())){
			return false;
		}
		return lychrel(addition, calls+1);
	}

	public static void main(String[] args){
		AtomicInteger sum = new AtomicInteger(0);
		LongStream.iterate(10, n -> ++n).limit(9990).forEach(n -> {
			if(lychrel(BigInteger.valueOf(n), 0)){
				sum.incrementAndGet();
			}
		});

		System.out.println(sum.toString());
	}
}