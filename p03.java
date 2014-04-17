import java.math.BigInteger;
import java.util.Iterator;
import java.util.LinkedHashSet;


public class p03 {
	public static LinkedHashSet<BigInteger> primeFactors(BigInteger n){
		LinkedHashSet<BigInteger> primes= new LinkedHashSet<BigInteger>();
		BigInteger i= new BigInteger("2");
		while(!n.equals(new BigInteger("1"))){
			if(n.mod(i).equals(new BigInteger("0"))){
				primes.add(i);
				n=n.divide(i);
			}
			else{
				i=i.add(new BigInteger("1"));
			}
		}
		return primes;
	}
	public static void main(String[] args){
		BigInteger b= new BigInteger("600851475143");
		LinkedHashSet<BigInteger> lhm= primeFactors(b);
		System.out.println(lhm.toArray()[lhm.size()-1]);
	}
}
